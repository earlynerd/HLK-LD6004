"""Trace the ADT6101P init sequence by running from reset and stopping on
software breakpoints, capturing peripheral diffs at every stop.

Why this shape: reset-and-halt stops the core at the ROM vector (PC=0xE0) with
the radar front end unpowered (0x40008000 reads 0xFFFFFFFF), and in that state
the debug port stays alive indefinitely. Halting an already-running app instead
loses the AP at the second FMCW ramp wrap (~9 s), because the sweep engine
asserts an NMI at every wrap and a halted core cannot take it. So we trace
forward from reset: ROM -> jump code -> Boot Area -> App1.

At each stop we log PC/LR, snapshot the front-end / synth / timer / DSP / system
blocks, and print only the words that changed since the previous stop. That
gives the configuration ORDER with real values, which the static call graph
cannot.

Constraint: a breakpoint stop halts the core, so once the sweep is running there
is one wrap (<=5.0 s) of headroom. Keep each stop quick and do not stop more
than necessary.

Usage:
  "C:\\Program Files\\Python314\\python.exe" tools/jlink/trace_init.py [OUTDIR]
      [--bp 0xabfc] [--bp 0x80bc] [--max 40] [--limit 120]
"""
import argparse
import json
import os
import time

import pylink

# Peripheral windows to snapshot at every stop.
SNAPS = {
    "FE":     (0x40003000, 0x100),   # front end; config regs start around +0x100
    "SYNTH":  (0x40008000, 0x20),
    "TIMER":  (0x4000C000, 0x30),
    "DSP":    (0x40021000, 0x80),
    "SYSCTL": (0x40022000, 0x40),
}
VECTORS = (0x00008000, 2)


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def snap_all(jl):
    out = {}
    for k, (a, n) in SNAPS.items():
        try:
            out[k] = jl.memory_read32(a, n)
        except pylink.errors.JLinkException as e:
            out[k] = f"ERR {e}"
    return out


def diff_words(prev, cur):
    """Human-readable list of words that changed between two snapshots."""
    out = []
    for k, v in cur.items():
        p = (prev or {}).get(k)
        if not isinstance(v, list):
            continue
        if not isinstance(p, list):
            if any(v):
                out.append(f"{k} now live")
            continue
        base = SNAPS[k][0]
        for i, (a, b) in enumerate(zip(p, v)):
            if a != b:
                out.append(f"{base + 4 * i:#010x}:{a:X}->{b:X}")
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("outdir", nargs="?", default="dumps/2026-10-29")
    ap.add_argument("--bp", action="append", default=[],
                    help="breakpoint address, repeatable")
    ap.add_argument("--max", type=int, default=40, help="max stops")
    ap.add_argument("--limit", type=float, default=8.0,
                    help="seconds of target time to trace; the ramp is running "
                         "from t~0.75s and the AP dies ~2 wraps (about 10s) "
                         "afterwards, so stay under ~8s")
    ap.add_argument("--out", default=None,
                    help="output file; default init_trace_<UTC>.json so a "
                         "failed run cannot clobber a good capture")
    a = ap.parse_args()
    os.makedirs(a.outdir, exist_ok=True)
    bps = [int(x, 16) & ~1 for x in a.bp] or [0xabfc]

    jl = connect()
    log = {"breakpoints": [hex(x) for x in bps], "stops": []}
    print(f"breakpoints available={jl.num_available_breakpoints()} "
          f"watchpoints available={jl.num_available_watchpoints()}", flush=True)
    try:
        jl.reset(halt=True)
        print(f"halted at reset: PC={jl.register_read('R15 (PC)'):#08x}", flush=True)
        jl.enable_soft_breakpoints()
        for addr in bps:
            jl.breakpoint_set(addr)
        print("planted: " + " ".join(f"{b:#08x}" for b in bps), flush=True)

        jl.restart(num_instructions=0, skip_breakpoints=True)
        t0 = time.time()
        prev = None
        while time.time() - t0 < a.limit and len(log["stops"]) < a.max:
            while not jl.halted():
                time.sleep(0.005)
                if time.time() - t0 > a.limit:
                    break
            if not jl.halted():
                print("  timed out waiting for a stop", flush=True)
                break

            pc = jl.register_read("R15 (PC)") & ~1
            lr = jl.register_read("R14") & ~1
            t = time.time() - t0
            sn = snap_all(jl)
            vec = jl.memory_read32(*VECTORS)
            hit = pc if pc in bps else None
            ch = diff_words(prev, sn)
            print(f"  t={t:6.2f} PC={pc:#08x} LR={lr:#08x} "
                  f"{'<BP>' if hit is not None else '<stop>'} "
                  f"appVec={vec[0]:#010x}/{vec[1]:#08x}", flush=True)
            if ch:
                print("      " + "  ".join(ch[:24]) + ("" if len(ch) <= 24 else
                      f"  (+{len(ch) - 24} more)"), flush=True)
            log["stops"].append({"t": round(t, 3), "pc": pc, "lr": lr,
                                 "bp": hit is not None, "vectors": vec,
                                 "changed": ch, "snaps": sn})
            prev = sn

            if hit is None:
                print("  stopped somewhere we did not ask for; ending", flush=True)
                break
            # Step over the breakpointed instruction, then resume.
            jl.restart(num_instructions=1, skip_breakpoints=True)
            time.sleep(0.02)
            jl.restart(num_instructions=0, skip_breakpoints=True)
    except pylink.errors.JLinkException as e:
        print("probe error:", e, flush=True)
        log["error"] = str(e)
    finally:
        try:
            jl.breakpoint_clear_all()
        except pylink.errors.JLinkException:
            pass
        try:
            jl.reset(halt=False)
            log["reset"] = "reset and run"
        except pylink.errors.JLinkException as e:
            log["reset"] = f"failed: {e}"
        try:
            jl.close()
        except pylink.errors.JLinkException:
            pass
        path = a.out or os.path.join(
            a.outdir, time.strftime("init_trace_%Y%m%d_%H%M%S.json", time.gmtime()))
        json.dump(log, open(path, "w"), indent=2)
        print(f"log: {path}  ({len(log['stops'])} stops)")


if __name__ == "__main__":
    main()
