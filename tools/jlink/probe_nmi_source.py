"""Catch the post-halt failure live, and find the NMI source.

Two questions in one run:

1. Live core state at the moment of failure. DHCSR/ICSR are read on every poll
   while the AP still answers, so the last good sample shows what the core was
   doing just before the AP went deaf. Reconnecting first resets the core, which
   wipes S_LOCKUP and the pending NMI, so post-mortem reads are useless.

2. Which hardware register fires at the wrap. The sweep counter (0x40008004)
   counts down and wraps every ~5.0 s; the NMI latches pending at each wrap.
   Candidate status/ack blocks are sampled every poll and diffed against the
   wrap timestamps. A word that changes exactly at a wrap, and not in between,
   is the NMI source (or its status bit).

Read-only. Ends with reset-and-run.

SUPERSEDED in interpretation (2026-10-31): 0x40008000 is an Arm SP805
watchdog (ARM DDI 0270B). "Wrap" = timeout; the two "wrap-only" words are
WdogRIS/WdogMIS; the NMI is WDOGINT; the AP death ~2 timeouts later is
WDOGRES (the watchdog reset output), not a core lockup. See
tools/jlink/probe_wdt.py and DEBUG_LOG 2026-10-31.
"""
import json
import os
import sys
import time

import pylink

CORE = {"DHCSR": 0xE000EDF0, "ICSR": 0xE000ED04, "HFSR": 0xE000ED2C,
        "DFSR": 0xE000ED30}
SWEEP = 0x40008004
BLOCKS = {                      # candidate NMI sources / status + ack regs
    "TIMER":  (0x4000C000, 0x10),
    "SYNTH":  (0x40008000, 0x08),
    "DSP":    (0x40021000, 0x20),
    "IRQ0":   (0x40010000, 0x10),
    "IRQ1":   (0x40011000, 0x10),
    "IRQ2":   (0x40012000, 0x10),
    "BLK00":  (0x40000000, 0x10),
    "SYSCTL": (0x40022000, 0x20),
    "GPIO":   (0x40020000, 0x10),
}
POLL_S = 0.2
MAX_S = 15.0


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect("Cortex-M3", verbose=False)
    return jl


def grab(jl):
    core, blk = {}, {}
    for k, a in CORE.items():
        core[k] = jl.memory_read32(a, 1)[0]
    sw = jl.memory_read32(SWEEP, 1)[0]
    for k, (a, n) in BLOCKS.items():
        blk[k] = jl.memory_read32(a, n)
    return core, sw, blk


def main():
    outdir = sys.argv[1] if len(sys.argv) > 1 else "dumps/2026-10-29"
    os.makedirs(outdir, exist_ok=True)
    jl = connect()
    log = {"samples": [], "wraps": []}
    try:
        jl.halt()
        t0 = time.time()
        prev, prev_t, prev_sweep = None, None, None
        last_good = None
        died_at = None
        while time.time() - t0 < MAX_S:
            t = time.time() - t0
            try:
                core, sw, blk = grab(jl)
            except pylink.errors.JLinkException as e:
                died_at = t
                print(f"  t={t:5.2f}  AP DEAD ({e})", flush=True)
                break
            wrapped = prev_sweep is not None and sw > prev_sweep
            if wrapped:
                log["wraps"].append(round(t, 2))
            moves = []
            if prev is not None:
                for k in blk:
                    for i, (a, b) in enumerate(zip(prev[k], blk[k])):
                        if a != b:
                            moves.append((k, i, a, b))
            print(f"  t={t:5.2f} DHCSR={core['DHCSR']:#010x} ICSR={core['ICSR']:#010x} "
                  f"sweep={sw:#010x}{'  <WRAP>' if wrapped else ''}"
                  f"  {' '.join(f'{k}[{i}]:{a:X}->{b:X}' for k, i, a, b in moves)}",
                  flush=True)
            log["samples"].append({"t": round(t, 3), "core": core, "sweep": sw,
                                   "blocks": blk, "wrap": wrapped,
                                   "moves": [[k, i, a, b] for k, i, a, b in moves]})
            last_good = {"t": round(t, 3), "core": core, "sweep": sw}
            prev, prev_t, prev_sweep = blk, t, sw
            time.sleep(POLL_S)

        log["died_at_s"] = died_at
        log["last_good"] = last_good
        print("\nlast good sample before AP died:", last_good, flush=True)
        if last_good:
            d = last_good["core"]["DHCSR"]
            # Cortex-M3 TRM (ARM DDI 0337G) Table 10-2: the status bits are
            # 16-19, and DHCSR[31:16] "reads back as status bits [25:16]" —
            # so the mirrored copy lives in the top halfword too.
            print(f"  S_LOCKUP={bool(d & (1 << 19))} S_SLEEP={bool(d & (1 << 18))} "
                  f"S_HALT={bool(d & (1 << 17))}  ICSR={last_good['core']['ICSR']:#010x}",
                  flush=True)

        # Which words move only at wraps?
        at_wrap, between = {}, {}
        for s in log["samples"]:
            for k, i, a, b in s["moves"]:
                (at_wrap if s["wrap"] else between).setdefault((k, i), 0)
                if s["wrap"]:
                    at_wrap[(k, i)] += 1
                else:
                    between[(k, i)] += 1
        wrap_only = sorted(k for k in at_wrap if k not in between)
        print("\nwords that change ONLY at a ramp wrap:",
              [f"{k}[{i}]" for k, i in wrap_only] or "none", flush=True)
        log["wrap_only_words"] = [list(k) for k in wrap_only]
        log["always_moving"] = sorted(f"{k}[{i}]" for k, i in between)
        print("words moving between wraps too:", log["always_moving"], flush=True)
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
        path = os.path.join(outdir, "nmi_source_probe.json")
        json.dump(log, open(path, "w"), indent=2)
        print("log:", path)


if __name__ == "__main__":
    main()
