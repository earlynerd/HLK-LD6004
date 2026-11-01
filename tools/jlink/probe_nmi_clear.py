"""Prove (or kill) the NMI-re-entry lockup theory for the ADT6101P.

The radar asserts an NMI at every FMCW ramp wrap: the sweep counter at
0x40008004 counts down from 0x1DCD6500 (500e6) at ~100e6/s, i.e. a 5.0 s ramp.
With the core halted the NMI cannot be serviced, so it latches pending (ICSR
bit 31, VECTPENDING=2). The next wrap then delivers a second NMI while one is
already pending -> Cortex-M3 lockup, which is what looks like "the target
resets ~5 s after a halt".

This run halts and clears the pending NMI (ICSR bit 27, NMICLR) on every poll.
If the AP stays readable well past the second wrap, the theory is confirmed and
long halt sessions become possible. If it dies on schedule anyway, the NMI
source is level-asserted and re-pends instantly, so the fix is masking the
source instead.

Writes only the core's ICSR. Ends with reset-and-run.

SUPERSEDED (2026-10-31). Two static errors in the premise, both settled by
the chip's own TRM and the SP805 TRM:
- ICSR bit 27 on Cortex-M3 (ARM DDI 0337G) is PENDSVCLR, not an NMI clear;
  the M3 has NO way to clear a pending NMI via ICSR at all (only
  NMIPENDSET, bit 31). So this run never cleared anything, and its failure
  does not prove a "level-asserted" source.
- The source is the SP805 watchdog's WDOGINT (block 0x40008000, ARM DDI
  0270B). Its interrupt is cleared by unlocking (+0xC00 = 0x1ACCE551) and
  writing +0x0C WdogIntClr, which also reloads the counter. That is the
  lever probe_wdt.py uses.
"""
import json
import os
import sys
import time

import pylink

ICSR = 0xE000ED04
NMICLR = 1 << 27          # MISNAMED: on this part (DDI 0337G) bit 27 = PENDSVCLR
NMI_PENDING = 1 << 31     # NMIPENDSET; reads back as pending-NMI state

WATCH = {
    "ICSR":    (ICSR, 1),
    "SYSCTL":  (0x40022000, 8),
    "TIMER":   (0x4000C000, 10),
    "SYNTH":   (0x40008000, 2),
    "SAMPLES": (0x20008000, 2),
    "VECTORS": (0x00008000, 2),
}
POLL_S = 0.25
WATCH_S = 22.0            # comfortably past the 2nd (~9 s) and 3rd (~14 s) wraps


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


def main():
    outdir = sys.argv[1] if len(sys.argv) > 1 else "dumps/2026-10-29"
    os.makedirs(outdir, exist_ok=True)
    jl = connect()
    log = {"clears": 0, "wraps": [], "samples": []}
    try:
        b = sample(jl)
        print("baseline ICSR =", f"{b['ICSR'][0]:#010x}", flush=True)

        jl.halt()
        t0 = time.time()
        prev_synth = None
        died_at = None
        while time.time() - t0 < WATCH_S:
            t = time.time() - t0
            cur = sample(jl)
            errs = [k for k, v in cur.items() if isinstance(v, str)]
            if errs:
                died_at = t
                print(f"  t={t:5.2f}  AP READ FAILURES x{len(errs)}", flush=True)
                break

            icsr = cur["ICSR"][0]
            sweep = cur["SYNTH"][1]
            wrapped = prev_synth is not None and sweep > prev_synth  # counted down, then jumped up
            if wrapped:
                log["wraps"].append(round(t, 2))
            note = "  <RAMP WRAP>" if wrapped else ""

            cleared = ""
            if icsr & NMI_PENDING:
                try:
                    jl.memory_write32(ICSR, [NMICLR])
                    log["clears"] += 1
                    cleared = "  NMICLR written"
                except pylink.errors.JLinkException as e:
                    cleared = f"  NMICLR failed: {e}"

            print(f"  t={t:5.2f}  ICSR={icsr:#010x}  sweep={sweep:#010x}"
                  f"  TIMER8={cur['TIMER'][8]:#010x}{note}{cleared}", flush=True)
            log["samples"].append({"t": round(t, 3), "icsr": icsr, "sweep": sweep,
                                   "timer8": cur["TIMER"][8]})
            prev_synth = sweep
            time.sleep(POLL_S)

        survived = died_at is None
        log["died_at_s"] = died_at
        log["survived"] = survived
        print(f"\nsurvived {WATCH_S:.0f} s halted: {survived}", flush=True)
        print("ramp wraps seen at:", log["wraps"], flush=True)
        print("NMICLR writes:", log["clears"], flush=True)

        if survived:
            # Confirm the core is still alive and can actually be resumed.
            try:
                jl.restart(num_instructions=0, skip_breakpoints=True)
                time.sleep(0.5)
                running = not jl.halted()
                log["resumed_after_long_halt"] = running
                print("core resumed after long halt:", running, flush=True)
            except pylink.errors.JLinkException as e:
                log["resumed_after_long_halt"] = f"failed: {e}"
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
        path = os.path.join(outdir, "nmi_clear_probe.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
