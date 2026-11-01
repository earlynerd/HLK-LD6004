"""SP805 watchdog bench experiments at 0x40008000 (ARM DDI 0270B r1p0).

The block is an Arm PrimeCell SP805 WDT: +0x00 WdogLoad, +0x04 WdogValue,
+0x08 WdogControl (bit0 INTEN, bit1 RESEN), +0x0C WdogIntClr (W, any value:
clears WDOGINT and reloads the counter), +0x10 WdogRIS, +0x14 WdogMIS,
+0xC00 WdogLock (0x1ACCE551 = unlock, anything else re-locks; reads return
lock status). WDOGINT is wired to the core NMI; WDOGRES (second uncleared
timeout) is what killed the AP ~9 s into every long halt in earlier probes.

Modes:
  ids     read-only, running: block state + PrimeCell ID registers.
          DDI 0270B reset values: PeriphID = 05 18 14 00 (PartNo 0x0014 =
          WDT), PCellID = 0D F0 05 B1. Lock read: 0 = unlocked, 1 = locked.
  service halt mid-run; wait for the first timeout (WdogRIS latches, NMI
          pends), then the stock unlock recipe: +0xC00 = 0x1ACCE551, then
          +0x0C = 1 (clears WDOGINT + reloads), then stock disable:
          +0x08 = 0 (counter stops, DDI 0270B 2.5), re-lock. Then poll for
          --watch seconds. PREDICTION: RIS/MIS clear, Value reloads then
          freezes, AP stays alive far past the old ~9 s death point.
  disable halt mid-run and immediately run the stock disable recipe
          (FUN_00015138: unlock, Control=0, re-lock) before any timeout.
          PREDICTION: no NMI ever, Value frozen, survives --watch seconds.

Writes are limited to the SP805's own registers (+0xC00, +0x0C, +0x08),
mirroring sequences App1 itself executes in its TF 0x3000/0x4000 handlers.
Ends with reset-and-run so the board always boots normally afterwards.

Register decoders follow the chip's own TRM: ARM DDI 0337G Table 8-15 (ICSR:
PENDSVSET=28, PENDSVCLR=27, PENDSTSET=26, PENDSTCLR=25, ISRPREEMPT=23,
ISRPENDING=22, VECTPENDING=[21:12], no NMI-clear bit) and Table 10-2 (DHCSR:
S_REGRDY=16, S_HALT=17, S_SLEEP=18, S_LOCKUP=19, S_RETIRE_ST=24,
S_RESET_ST=25; bits [31:16] read back as status bits [25:16]).
"""
import argparse
import json
import os
import sys
import time

import pylink

BASE = 0x40008000
LOAD    = BASE + 0x00
VALUE   = BASE + 0x04
CONTROL = BASE + 0x08
INTCLR  = BASE + 0x0C
RIS     = BASE + 0x10
MIS     = BASE + 0x14
LOCK    = BASE + 0xC00
KEY     = 0x1ACCE551

DHCSR = 0xE000EDF0
ICSR  = 0xE000ED04

# DDI 0337G Table 10-2
DHCSR_BITS = {
    "C_DEBUGEN": 0, "C_HALT": 1, "C_STEP": 2, "C_MASKINTS": 3,
    "C_SNAPSTALL": 5, "S_REGRDY": 16, "S_HALT": 17, "S_SLEEP": 18,
    "S_LOCKUP": 19, "S_RETIRE_ST": 24, "S_RESET_ST": 25,
}
# DDI 0337G Table 8-15
ICSR_BITS = {
    "NMIPENDSET": 31, "PENDSVSET": 28, "PENDSVCLR": 27, "PENDSTSET": 26,
    "PENDSTCLR": 25, "ISRPREEMPT": 23, "ISRPENDING": 22, "RETTOBASE": 11,
}
EXC_NAMES = {2: "NMI", 3: "HardFault", 4: "MemManage", 5: "BusFault",
             6: "UsageFault"}


def decode(reg, bits):
    on = [name for name, b in bits.items() if reg & (1 << b)]
    return sorted(on)


def icsr_text(v):
    vp = (v >> 12) & 0x3FF
    va = v & 0x1FF
    s = ",".join(decode(v, ICSR_BITS))
    return (f"ICSR={v:#010x} [{s}] pending={vp}({EXC_NAMES.get(vp, 'exc')}) "
            f"active={va}")


def dhcsr_text(v):
    return f"DHCSR={v:#010x} [{','.join(decode(v, DHCSR_BITS))}]"


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def r1(jl, addr):
    return jl.memory_read32(addr, 1)[0]


def wdt(jl):
    return {"load": r1(jl, LOAD), "value": r1(jl, VALUE),
            "control": r1(jl, CONTROL), "ris": r1(jl, RIS),
            "mis": r1(jl, MIS), "lock": r1(jl, LOCK)}


def log_wdt(log, tag, s, t=None):
    print(f"  t={t if t is not None else 0:6.2f}  {tag}: "
          f"load={s['load']:#010x} value={s['value']:#010x} "
          f"control={s['control']:#x} ris={s['ris']:#x} mis={s['mis']:#x} "
          f"lock={s['lock']:#x}", flush=True)
    log["samples"].append({"t": t, "tag": tag, **s})


def poll_core(jl, log, t):
    d, i = r1(jl, DHCSR), r1(jl, ICSR)
    print(f"    {dhcsr_text(d)}  {icsr_text(i)}", flush=True)
    log["samples"].append({"t": t, "tag": "core", "dhcsr": d, "icsr": i})


def run_ids(jl, log):
    s = wdt(jl)
    log_wdt(log, "running baseline", s, 0.0)
    time.sleep(0.5)
    s2 = wdt(jl)
    log_wdt(log, "running +0.5s", s2, 0.5)
    if s["control"] & 1:
        if s2["value"] > s["value"]:
            gap = s["load"] - s2["value"]
            print(f"  counter went UP between samples: caught a live FEED "
                  f"(WdogLoad re-write reloads the counter, DDI 0270B 2.5); "
                  f"~{gap/1e6:.2f}e6 counts since that feed", flush=True)
            log["feed_observed"] = True
        else:
            rate = (s["value"] - s2["value"]) / 0.5
            print(f"  decrement rate ~{rate:.3g}/s -> next timeout in "
                  f"~{s2['value']/rate:.2f} s", flush=True)
            log["count_rate_hz"] = rate
    ids = {}
    for name, off in [("PeriphID0", 0xFE0), ("PeriphID1", 0xFE4),
                      ("PeriphID2", 0xFE8), ("PeriphID3", 0xFEC),
                      ("PCellID0", 0xFF0), ("PCellID1", 0xFF4),
                      ("PCellID2", 0xFF8), ("PCellID3", 0xFFC),
                      ("ITCR", 0xF00), ("ITOP", 0xF04)]:
        ids[name] = r1(jl, BASE + off)
        print(f"  +{off:#05x} {name:10s} = {ids[name]:#010x}", flush=True)
    log["ids"] = ids
    expect = {"PeriphID0": 0x05, "PeriphID1": 0x18, "PeriphID2": 0x14,
              "PeriphID3": 0x00, "PCellID0": 0x0D, "PCellID1": 0xF0,
              "PCellID2": 0x05, "PCellID3": 0xB1}
    match = {k: ids.get(k, -1) & 0xFF == v for k, v in expect.items()}
    log["id_match_ddi0270b"] = match
    print("  ID match vs DDI 0270B reset values:", match, flush=True)
    print("  " + icsr_text(r1(jl, ICSR)), flush=True)


def unlock(jl, log, t):
    jl.memory_write32(LOCK, [KEY])
    st = r1(jl, LOCK)
    print(f"  t={t:6.2f}  unlock: wrote {KEY:#010x} to +C00, "
          f"lock reads {st:#x} (0 = unlocked per DDI 0270B)", flush=True)
    log["samples"].append({"t": t, "tag": "unlock", "lock": st})
    return st == 0


def relock(jl, log, t):
    jl.memory_write32(LOCK, [0xFFFFFFFF])
    st = r1(jl, LOCK)
    print(f"  t={t:6.2f}  relock: lock reads {st:#x} (1 = locked)", flush=True)
    log["samples"].append({"t": t, "tag": "relock", "lock": st})


def stock_disable(jl, log, t):
    if not unlock(jl, log, t):
        log["unlock_readback"] = "not 0 after key write"
    jl.memory_write32(CONTROL, [0])
    relock(jl, log, time.time() - log["t0"])
    s = wdt(jl)
    log_wdt(log, "after stock disable", s, time.time() - log["t0"])
    return s


def survival(jl, log, t0_watch, seconds):
    """Poll the core and the WDT block; return None if alive, else died_at."""
    t0 = time.time()
    died_at = None
    while time.time() - t0 < seconds:
        t = time.time() - log["t0"]
        try:
            s = wdt(jl)
        except pylink.errors.JLinkException as e:
            died_at = round(t, 2)
            print(f"  t={t:6.2f}  AP DEAD ({e}) - watchdog hypothesis wrong?",
                  flush=True)
            break
        log_wdt(log, "watch", s, t)
        try:
            poll_core(jl, log, t)
        except pylink.errors.JLinkException as e:
            died_at = round(t, 2)
            print(f"  t={t:6.2f}  AP DEAD on core read ({e})", flush=True)
            break
        time.sleep(0.5)
    log["survived_watch"] = died_at is None
    log["died_at_s"] = died_at
    return died_at


def run_service(jl, log, watch_s):
    log_wdt(log, "running baseline", wdt(jl), 0.0)
    jl.halt()
    log["t0"] = time.time()
    print("halted; waiting for the first timeout (WdogRIS -> 1) ...", flush=True)

    first = None
    while time.time() - log["t0"] < 12.0:
        s = wdt(jl)
        t = time.time() - log["t0"]
        if s["ris"]:
            first = (t, s)
            log_wdt(log, "FIRST TIMEOUT (RIS latched)", s, t)
            print("  " + icsr_text(r1(jl, ICSR)), flush=True)
            break
        log_wdt(log, "pre-timeout", s, t)
        time.sleep(0.1)
    if first is None:
        print("no timeout seen in 12 s - is the app running and the WDT armed?",
              flush=True)
        log["aborted"] = "no RIS latch within 12 s"
        return

    t, s = first
    rate = (s["load"] - 0) or 1
    if s["value"]:
        print(f"  ~{s['value']/1e6:.1f}e6 counts to next zero -> WDOGRES "
              f"deadline in ~{s['value']/100e6:.2f} s at 100e6/s", flush=True)

    if not unlock(jl, log, time.time() - log["t0"]):
        log["unlock_readback"] = "lock not 0 after key write"
    jl.memory_write32(INTCLR, [1])
    s = wdt(jl)
    log_wdt(log, "after IntClr (expect ris=0 mis=0, value reloaded)", s,
            time.time() - log["t0"])
    log["intclr_cleared_ris"] = (s["ris"] == 0 and s["mis"] == 0)

    s = stock_disable(jl, log, time.time() - log["t0"])
    v1 = s["value"]
    time.sleep(1.0)
    v2 = r1(jl, VALUE)
    print(f"  counter frozen? value {v1:#010x} -> {v2:#010x} "
          f"(delta {v1 - v2:+d})", flush=True)
    log["counter_frozen"] = (v1 == v2)

    print(f"  polling for {watch_s:.0f} s (old probes died ~9-10 s after "
          f"halt)...", flush=True)
    survival(jl, log, time.time(), watch_s)


def run_disable(jl, log, watch_s):
    log_wdt(log, "running baseline", wdt(jl), 0.0)
    jl.halt()
    log["t0"] = time.time()
    s = stock_disable(jl, log, time.time() - log["t0"])
    v1 = s["value"]
    time.sleep(1.0)
    v2 = r1(jl, VALUE)
    print(f"  counter frozen? value {v1:#010x} -> {v2:#010x} "
          f"(delta {v1 - v2:+d})", flush=True)
    log["counter_frozen"] = (v1 == v2)
    print("  " + icsr_text(r1(jl, ICSR)) + "   (expect no NMIPENDSET)", flush=True)
    print(f"  polling for {watch_s:.0f} s ...", flush=True)
    survival(jl, log, time.time(), watch_s)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("mode", choices=["ids", "service", "disable"])
    ap.add_argument("outdir", nargs="?", default="dumps/2026-10-31")
    ap.add_argument("--watch", type=float, default=25.0,
                    help="survival poll seconds for service/disable modes")
    a = ap.parse_args()
    os.makedirs(a.outdir, exist_ok=True)
    stamp = time.strftime("%Y%m%dT%H%M%SZ", time.gmtime())
    path = os.path.join(a.outdir, f"wdt_{a.mode}_{stamp}.json")

    log = {"mode": a.mode, "utc": stamp, "samples": []}
    jl = connect()
    try:
        if a.mode == "ids":
            run_ids(jl, log)
        elif a.mode == "service":
            run_service(jl, log, a.watch)
        else:
            run_disable(jl, log, a.watch)
    except pylink.errors.JLinkException as e:
        log["error"] = str(e)
        print("probe error:", e, flush=True)
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
        with open(path, "w") as f:
            json.dump(log, f, indent=2)
        print("log:", path, flush=True)


if __name__ == "__main__":
    main()
