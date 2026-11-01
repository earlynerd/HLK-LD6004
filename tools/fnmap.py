"""Resolve an address to the enclosing function in a Ghidra DumpDecompiled.c.

The init trace gives PC/LR pairs; the call tree comes from knowing which function
each LR lives in. Parses the '/* ===== FUN_xxxx @ addr ===== */' headers into a
sorted table and does a bisect.

Usage: python tools/fnmap.py <decompiled.c> <addr> [addr ...]
"""
import bisect
import re
import sys

HDR = re.compile(r"^/\* ===== (\S+) @ ([0-9a-fA-F]+) ===== \*/\s*$")


def load(path):
    starts, names = [], []
    for line in open(path, encoding="utf-8", errors="replace"):
        m = HDR.match(line)
        if m:
            starts.append(int(m.group(2), 16))
            names.append(m.group(1))
    return starts, names


def resolve(addrs, starts, names):
    out = []
    for a in addrs:
        a &= ~1
        i = bisect.bisect_right(starts, a) - 1
        if i < 0:
            out.append((a, None, None, None))
        else:
            end = starts[i + 1] if i + 1 < len(starts) else None
            out.append((a, names[i], starts[i],
                        (a - starts[i]) if end is None or a < end else None))
    return out


def main():
    path, *addrs = sys.argv[1:]
    starts, names = load(path)
    print(f"{len(starts)} functions in {path}")
    for a, n, s, off in resolve([int(x, 16) for x in addrs], starts, names):
        if n is None:
            print(f"  {a:#08x}  <no function contains this address>")
        else:
            print(f"  {a:#08x}  {n}  base={s:#08x}  +{off:#x}")


if __name__ == "__main__":
    main()
