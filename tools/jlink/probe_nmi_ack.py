"""Try to ack/mask the FMCW-wrap NMI at its source so the core can stay halted.

Established: the AP stops answering at the second FMCW ramp wrap (t~9 s after a
halt). The NMI latches pending at the first wrap and ICSR NMICLR does not clear
it, so the source is level-asserted. The only two registers that change *only*
at a wrap are 0x40008010 and 0x40008014, which latch 0 -> 1 and stay set. They
are the candidate status/ack pair.

This halts, then on every poll writes a chosen value to those two registers
(optionally also writing ICSR NMICLR), and reports whether:
  * the pending NMI ever clears,
  * the latch at 0x40008010/14 ever clears,
  * the AP survives past the second wrap (success).

Run long enough to pass two wraps. Ends with reset-and-run, which re-runs the
boot chain and re-initialises every register, so any bad value is undone.

Usage: python tools/jlink/probe_nmi_ack.py [OUTDIR] [--mode clear|set|clear+nmi|set+nmi]
"""
import argparse
import json
import os
import sys
import time

import pylink

ICSR = 0xE000ED04
NMICLR = 1 << 27
NMI_PENDING = 1 << 31
SYN = 0x40008000
LATCH = (0x40008010, 0x40008014)
POLL_S = 0.2
RUN_S = 22.0          # past the 2nd (~9 s) and 3rd (~14 s) wraps


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("outdir", nargs="?", default="dumps/2026-10-29")
    ap.add_argument("--mode", default="clear",
                    choices=["clear", "set", "clear+nmi", "set+nmi"])
    a = ap.parse_args()
    os.makedirs(a.outdir, exist_ok=True)

    val = 0 if a.mode.startswith("clear") else 1
    also_nmi = a.mode.endswith("+nmi")
    jl = connect()
    log = {"mode": a.mode, "wraps": [], "samples": [], "ack_writes": 0}
    try:
        pre = jl.memory_read32(SYN, 8)
        print(f"synth block before halt: {[hex(v) for v in pre]}", flush=True)

        jl.halt()
        t0 = time.time()
        prev_sweep = None
        died_at = None
        nmi_clears = latch_clears = 0
        while time.time() - t0 < RUN_S:
            t = time.time() - t0
            try:
                icsr = jl.memory_read32(ICSR, 1)[0]
                syn = jl.memory_read32(SYN, 8)
            except pylink.errors.JLinkException as e:
                died_at = t
                print(f"  t={t:5.2f}  AP DEAD ({e})", flush=True)
                break

            sweep = syn[1]
            wrapped = prev_sweep is not None and sweep > prev_sweep
            if wrapped:
                log["wraps"].append(round(t, 2))

            acted = ""
            if syn[4] or syn[5]:
                try:
                    jl.memory_write32(LATCH[0], [val])
                    jl.memory_write32(LATCH[1], [val])
                    back = jl.memory_read32(LATCH[0], 2)
                    log["ack_writes"] += 1
                    acted = f"  ack->{val} wrote, read back {back[0]:X}/{back[1]:X}"
                    if back[0] == 0 and back[1] == 0:
                        latch_clears += 1
                except pylink.errors.JLinkException as e:
                    acted = f"  ack failed: {e}"
            if also_nmi and (icsr & NMI_PENDING):
                try:
                    jl.memory_write32(ICSR, [NMICLR])
                except pylink.errors.JLinkException:
                    pass

            if not (icsr & NMI_PENDING):
                nmi_clears += 1

            print(f"  t={t:5.2f} ICSR={icsr:#010x} "
                  f"{'NMI' if icsr & NMI_PENDING else '   '} "
                  f"+10={syn[4]:X} +14={syn[5]:X} sweep={sweep:#010x}"
                  f"{'  <WRAP>' if wrapped else ''}{acted}", flush=True)
            log["samples"].append({"t": round(t, 3), "icsr": icsr, "syn": syn,
                                   "wrap": wrapped})
            prev_sweep = sweep
            time.sleep(POLL_S)

        survived = died_at is None
        log.update({"died_at_s": died_at, "survived": survived,
                    "nmi_clear_polls": nmi_clears, "latch_clear_polls": latch_clears})
        print(f"\nmode={a.mode}  survived {RUN_S:.0f}s halted: {survived}", flush=True)
        print(f"wraps at {log['wraps']}  ack writes {log['ack_writes']}  "
              f"polls with NMI clear {nmi_clears}  polls with latch clear {latch_clears}",
              flush=True)
        if survived:
            try:
                jl.restart(num_instructions=0, skip_breakpoints=True)
                time.sleep(0.5)
                log["resumed"] = not jl.halted()
                print("core resumed after long halt:", log["resumed"], flush=True)
            except pylink.errors.JLinkException as e:
                log["resumed"] = f"failed: {e}"
                print("resume failed:", e, flush=True)
    finally:
        try:
            jl.reset(halt=False)
            log["reset"] = "reset and run"
        except pylink.errors.JLinkException as e:
            log["reset"] = f"failed: {e}"
        try:
            jl.close()
        except pylink.errors.JLinkException:
            pass
        path = os.path.join(a.outdir, f"nmi_ack_{a.mode}.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
