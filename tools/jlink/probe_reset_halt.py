"""Test the workflow the ack experiment accidentally revealed.

Halting a *running* app loses the AP at the second FMCW ramp wrap (~9 s): the
sweep engine asserts an NMI at every wrap, a halted core cannot take it, and
after two wraps the debug port stops answering. Writing ICSR NMICLR and writing
to the wrap-status pair 0x40008010/14 (read-only, reads back 1/1) do not help.

But in one run the core was halted before the app had started the sweep — the
whole 0x40008000 block read 0xFFFFFFFF — and the AP stayed alive for the full
22 s with no NMI ever pending. So the lever may be *when* we halt, not what we
write.

This halts on reset (core stopped at the boot vector, radar never started) and
polls for 20 s, reporting: is the AP still alive, is the synth block live
(0x1DCD6500) or gated (0xFFFFFFFF), and where is the PC.

Ends with reset-and-run.
"""
import json
import os
import sys
import time

import pylink

READS = {"ICSR": 0xE000ED04, "SYNTH0": 0x40008000, "SWEEP": 0x40008004,
         "LATCH0": 0x40008010, "SYSCTL0": 0x40022000, "TIMER8": 0x4000C020,
         "VECT0": 0x00008000, "SAMPLES": 0x20008000}
POLL_S = 0.5
RUN_S = 20.0


def main():
    outdir = sys.argv[1] if len(sys.argv) > 1 else "dumps/2026-10-29"
    os.makedirs(outdir, exist_ok=True)
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    log = {"samples": []}
    try:
        jl.reset(halt=True)          # reset and stay halted at the boot vector
        t0 = time.time()
        died_at = None
        prev = None
        while time.time() - t0 < RUN_S:
            t = time.time() - t0
            try:
                v = {k: jl.memory_read32(a, 1)[0] for k, a in READS.items()}
                pc = jl.register_read("R15 (PC)")
            except pylink.errors.JLinkException as e:
                died_at = t
                print(f"  t={t:5.2f}  AP DEAD ({e})", flush=True)
                break
            ch = "" if prev is None else " ".join(
                k for k in READS if prev[k] != v[k])
            print(f"  t={t:5.2f} PC={pc:#08x} ICSR={v['ICSR']:#010x} "
                  f"SYNTH0={v['SYNTH0']:#010x} sweep={v['SWEEP']:#010x} "
                  f"latch={v['LATCH0']:#06x} changed:[{ch}]", flush=True)
            log["samples"].append({"t": round(t, 2), "pc": pc, **v})
            prev = v
            time.sleep(POLL_S)

        log["died_at_s"] = died_at
        log["survived"] = died_at is None
        print(f"\nsurvived {RUN_S:.0f} s halted-from-reset: {log['survived']}", flush=True)
        if log["samples"]:
            last = log["samples"][-1]
            print(f"synth live: {last['SYNTH0'] != 0xFFFFFFFF}  "
                  f"PC={last['pc']:#08x}  ICSR={last['ICSR']:#010x}", flush=True)
        try:
            jl.restart(num_instructions=0, skip_breakpoints=True)
            time.sleep(1.0)
            jl.halt()
            log["restarted_ok"] = True
            print("core restarted and re-halted fine; PC =",
                  f"{jl.register_read('R15 (PC)'):#08x}", flush=True)
        except pylink.errors.JLinkException as e:
            log["restarted_ok"] = False
            print("restart failed:", e, flush=True)
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
        path = os.path.join(outdir, "reset_halt_probe.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
