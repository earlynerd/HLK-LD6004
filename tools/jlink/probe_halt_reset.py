"""Time the ADT6101P's ~5 s post-halt reset and classify it.

Read-only: connect, sample, halt, sample on a fixed timebase, then reset-and-run
so the target boots normally again. No memory writes, no flash access.

What it answers:
  * Does the core/hardware resume on its own (i.e. did the chip reset)?
  * How long after the halt does that happen?
  * Does the SWD/AP path survive it (core/system reset) or drop out
    (chip-level reset or power event)?
  * Which blocks keep counting while the core is halted, i.e. which clock
    domain they live in.

Usage: python tools/jlink/probe_halt_reset.py [OUTDIR]
"""
import json
import os
import sys
import time

import pylink

WATCH = {
    # name: (addr, words)
    "ICSR":       (0xE000ED04, 1),   # active/reset state of the core
    "AIRCR":      (0xE000ED0C, 1),   # SYSRESETREQ bit 2
    "SYSCTL":     (0x40022000, 8),   # +0x00 free-runs, +0x1C set by ROM/app init
    "TIMER":      (0x4000C000, 10),  # timer / DSP trigger block
    "BOOTPINS":   (0x4002002C, 1),   # boot pin status (P12 bit12, P19 bit19)
    "SYNTH":      (0x40008000, 2),   # RF synthesizer sweep registers
    "DSPSTAT":    (0x40021058, 1),   # DSP engine busy/status
    "SAMPLES":    (0x20008000, 2),   # ADC sample buffer
    "VECTORS":    (0x00008000, 2),   # app SP / reset handler (re-boot marker)
}
POLL_S = 0.25
WATCH_S = 12.0


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def sample(jl):
    out = {}
    for name, (addr, n) in WATCH.items():
        try:
            out[name] = jl.memory_read32(addr, n)
        except pylink.errors.JLinkException as e:
            out[name] = f"ERR {e}"
    return out


def snap(jl):
    """One line of compact text for the log."""
    return "  ".join(
        f"{k}={' '.join(f'{v:08X}' for v in s) if isinstance(s, list) else s}"
        for k, s in sample(jl).items()
    )


def diff(a, b):
    """Addresses whose words differ between two samples."""
    return [k for k in WATCH if a.get(k) != b.get(k)]


def main():
    outdir = sys.argv[1] if len(sys.argv) > 1 else "dumps/2026-10-29"
    os.makedirs(outdir, exist_ok=True)
    jl = connect()
    log = {"watch": {k: [f"{a:#x}", n] for k, (a, n) in WATCH.items()}}
    try:
        print("== baseline, core running, no halt ==", flush=True)
        b0 = sample(jl)
        print("  t=0.00 " + snap(jl), flush=True)
        time.sleep(1.0)
        b1 = sample(jl)
        print("  t=1.00 " + snap(jl), flush=True)
        log["running_changes"] = diff(b0, b1)
        print("  changing while running:", log["running_changes"], flush=True)

        print("\n== halt, then poll every %.2f s for %.0f s ==" % (POLL_S, WATCH_S), flush=True)
        jl.halt()
        t0 = time.time()
        prev = sample(jl)
        print(f"  t=0.00 {snap(jl)}", flush=True)
        log["halted"] = {"t0": t0, "samples": []}

        resumed_at, lost_at, recovered_at = None, None, None
        while time.time() - t0 < WATCH_S:
            time.sleep(POLL_S)
            t = time.time() - t0
            cur = sample(jl)
            errs = [k for k, v in cur.items() if isinstance(v, str)]
            changed = diff(prev, cur)
            tag = ""
            if errs and lost_at is None:
                lost_at = t
                tag = "  <-- SWD/AP read failure"
            if not errs and lost_at is not None and recovered_at is None:
                recovered_at = t
                tag = "  <-- reads working again"
            if changed and resumed_at is None and t > 1.0:
                resumed_at = t
                tag += f"  <-- first change since halt: {changed}"
            print(f"  t={t:5.2f} {' '.join(changed) or '-':28s}{tag}", flush=True)
            log["halted"]["samples"].append({"t": round(t, 3), "changed": changed,
                                             "errors": errs, "values": {
                                                 k: v for k, v in cur.items()
                                                 if isinstance(v, list)}})
            prev = cur

        resumed_at, lost_at, recovered_at = None, None, None
        while time.time() - t0 < WATCH_S:
            time.sleep(POLL_S)
            t = time.time() - t0
            cur = sample(jl)
            errs = [k for k, v in cur.items() if isinstance(v, str)]
            changed = diff(prev, cur)
            tag = ""
            if errs and lost_at is None:
                lost_at = t
                tag = "  <-- SWD/AP read failure"
            if not errs and lost_at is not None and recovered_at is None:
                recovered_at = t
                tag = "  <-- reads working again"
            if changed and resumed_at is None and t > 1.0:
                resumed_at = t
                tag += f"  <-- first change since halt: {changed}"
            note = f"  ERR x{len(errs)}" if errs else ""
            print(f"  t={t:5.2f} {' '.join(changed) or '-':28s}{note}{tag}", flush=True)
            log["halted"]["samples"].append({"t": round(t, 3), "changed": changed,
                                             "errors": errs, "values": {
                                                 k: v for k, v in cur.items()
                                                 if isinstance(v, list)}})
            prev = cur
        log["halted"]["resumed_at_s"] = resumed_at
        log["halted"]["ap_lost_at_s"] = lost_at

        # Does the target come back on its own, and did the boot chain re-run?
        # Reconnect the way the proven SPI harness does: close the handle, wait,
        # open a fresh one.
        print("\n== reconnect phase ==", flush=True)
        log["reconnect"] = {"tries": 0, "back_at_s": None}
        back_at = None
        t_end = t0 + WATCH_S + 20.0
        while time.time() < t_end:
            log["reconnect"]["tries"] += 1
            try:
                jl.close()
            except pylink.errors.JLinkException:
                pass
            time.sleep(2.0)
            jl = connect()
            s = sample(jl)
            if not any(isinstance(v, str) for v in s.values()):
                back_at = time.time() - t0
                log["reconnect"]["back_at_s"] = back_at
                log["reconnect"]["values"] = {k: v for k, v in s.items() if isinstance(v, list)}
                print(f"  t={back_at:5.2f} target readable again "
                      f"(attempt {log['reconnect']['tries']})", flush=True)
                print("  " + snap(jl), flush=True)
                break
            print(f"  t={time.time() - t0:5.2f} attempt {log['reconnect']['tries']}: "
                  f"still unreachable", flush=True)
        if back_at is None:
            print("  target never became readable again", flush=True)
    finally:
        try:
            jl.reset(halt=False)      # pylink 2.0.1 has no go(); this resets and runs
            log["reset"] = "reset and run"
        except pylink.errors.JLinkException as e:
            log["reset"] = f"failed: {e}"
        try:
            jl.close()
        except pylink.errors.JLinkException:
            pass
        path = os.path.join(outdir, "halt_reset_probe.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
