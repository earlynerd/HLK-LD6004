"""Measure, rather than infer, that the post-halt failure is a Cortex-M3 lockup.

Halts, polls until the AP stops answering (expected at the second FMCW ramp
wrap, t~9 s), then closes and re-opens the J-Link handle and reads the debug
and fault status registers BEFORE issuing any reset:

  DHCSR 0xE000EDF0  status: 0 DBGACT, 1 S_REGRDY, 2 S_SLEEP, 3 S_HALT,
                        4 S_LOCKUP, 24 S_TWIDTH  (control bits are 16-21)
  DFSR  0xE000ED30  DWTOPCN / DWTUPTCN / SBTUPTCN / HALTIREQ / VECTTABLERD
  HFSR  0xE000ED2C  bit 1 FORCED, bit 30 VECTTBL
  ICSR  0xE000ED04  active/pending exception state

If S_LOCKUP reads 1, the NMI-re-entry theory is confirmed by measurement.
Ends with reset-and-run.
"""
import json
import os
import sys
import time

import pylink

CORE = {
    "DHCSR": (0xE000EDF0, 3),   # DHCSR/DHCP/DHDSR
    "DFSR":  (0xE000ED30, 1),
    "HFSR":  (0xE000ED2C, 1),
    "ICSR":  (0xE000ED04, 1),
    "AIRCR": (0xE000ED0C, 1),
}
SWEEP = (0x40008004, 1)


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def read_core(jl):
    out = {}
    for k, (a, n) in CORE.items():
        try:
            out[k] = jl.memory_read32(a, n)
        except pylink.errors.JLinkException as e:
            out[k] = f"ERR {e}"
    return out


def main():
    outdir = sys.argv[1] if len(sys.argv) > 1 else "dumps/2026-10-29"
    os.makedirs(outdir, exist_ok=True)
    jl = connect()
    log = {}
    try:
        print("before halt:", read_core(jl), flush=True)
        jl.halt()
        t0 = time.time()
        died_at = None
        while time.time() - t0 < 15.0:
            time.sleep(0.2)
            t = time.time() - t0
            try:
                sw = jl.memory_read32(*SWEEP)
            except pylink.errors.JLinkException:
                died_at = t
                print(f"  t={t:5.2f}  AP dead", flush=True)
                break
            print(f"  t={t:5.2f}  sweep={sw[0]:#010x}", flush=True)
        log["died_at_s"] = died_at

        print("\nreconnecting and reading fault state before any reset", flush=True)
        try:
            jl.close()
        except pylink.errors.JLinkException:
            pass
        time.sleep(2.0)
        jl = connect()
        st = read_core(jl)
        log["core_after"] = st
        for k, v in st.items():
            print(f"  {k:6s} {v}", flush=True)

        dhcsr = st.get("DHCSR")
        if isinstance(dhcsr, list) and dhcsr:
            d = dhcsr[0]
            # DHCSR status bits are 1-4, NOT 16-19 (those are the C_* control bits).
            log["S_LOCKUP"] = bool(d & (1 << 4))
            log["S_SLEEP"] = bool(d & (1 << 2))
            log["S_HALT"] = bool(d & (1 << 3))
            log["DBGACT"] = bool(d & (1 << 0))
            print(f"\n  DHCSR={d:#010x}  S_LOCKUP={log['S_LOCKUP']}  "
                  f"S_SLEEP={log['S_SLEEP']}  S_HALT={log['S_HALT']}  "
                  f"DBGACT={log['DBGACT']}", flush=True)
        try:
            log["halted_after"] = bool(jl.halted())
        except pylink.errors.JLinkException:
            pass
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
        path = os.path.join(outdir, "lockup_probe.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
