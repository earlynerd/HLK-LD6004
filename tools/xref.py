#!/usr/bin/env python3
"""Find literal-constant cross-references in a raw ADT6101P image.

Given a raw binary (as extracted by tools/bin2elf.py for Ghidra) and one or more
32-bit constants (peripheral bases, control-block addresses, magic values),
report every 2-byte-aligned offset where that constant appears as a little-endian
word, and name the enclosing function using the pseudo-C listing produced by
analysis/adt6101p/ghidra_scripts/DumpDecompiled.java.

Only the literal-pool *word* is found here; resolving the actual ADR/LDR that
uses it is left to the disassembly. That is enough to answer "which functions
touch block X".

Usage:
  python tools/xref.py <image.bin> <base-addr> <hex-constant> [more ...] \
      [--c <decompiled.c>]

Example:
  python tools/xref.py analysis/adt6101p/app1.bin 0x8000 4002e000 4001e000 \
      --c analysis/adt6101p/elf/app1_decompiled.c
"""
import argparse
import re
import struct
import sys

FUNC_RE = re.compile(r"/\* ===== (\S+) @ ([0-9a-fA-F]+) ===== \*/")


def load_functions(cpath):
    """Return a sorted list of (address, name) from a DumpDecompiled.c listing."""
    out = []
    try:
        with open(cpath, encoding="utf-8", errors="replace") as fh:
            for line in fh:
                m = FUNC_RE.search(line)
                if m:
                    out.append((int(m.group(2), 16), m.group(1)))
    except OSError:
        pass
    out.sort()
    return out


def enclosing(funcs, addr):
    """Best-effort: the last function whose start address is <= addr."""
    lo, hi, best = 0, len(funcs) - 1, None
    while lo <= hi:
        mid = (lo + hi) // 2
        if funcs[mid][0] <= addr:
            best = funcs[mid]
            lo = mid + 1
        else:
            hi = mid - 1
    return f"{best[1]}+{addr - best[0]:#x}" if best else "?"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("base", help="load address of the image, e.g. 0x8000")
    ap.add_argument("consts", nargs="+", help="hex constants, no 0x")
    ap.add_argument("--c", dest="cfile", default=None)
    args = ap.parse_args()

    data = open(args.image, "rb").read()
    base = int(args.base, 0)
    funcs = load_functions(args.cfile) if args.cfile else []

    for c in args.consts:
        want = int(c, 16)
        packed = struct.pack("<I", want)
        hits, off = [], 0
        while True:
            j = data.find(packed, off)
            if j < 0:
                break
            if j % 2 == 0:
                hits.append(j)
            off = j + 2
        print(f"== {want:#010x}: {len(hits)} hit(s)")
        for j in hits:
            addr = base + j
            where = f"  in {enclosing(funcs, addr)}" if funcs else ""
            print(f"   literal @ {addr:#08x}{where}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
