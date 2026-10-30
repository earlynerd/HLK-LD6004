"""Summarise which decompiled functions touch which peripheral blocks.

Usage: python func_periph_map.py <raw.bin> <decompiled.c> [<raw.bin> <decompiled.c> ...]
Resolves DAT_<addr> symbols by reading the 32-bit value at <addr> from the raw
image (literal pools), then reports peripheral references per function.
"""
import re
import struct
import sys

def run(img, dec, base=0x8000):
    data = open(img, 'rb').read()

    def datval(addr):
        off = addr - base
        if 0 <= off <= len(data) - 4:
            return struct.unpack_from('<I', data, off)[0]
        return None

    txt = open(dec, encoding='utf-8', errors='replace').read()
    parts = re.split(r"/\* ===== (\S+) @ (\S+) ===== \*/", txt)
    for i in range(1, len(parts) - 2, 3):
        name, addr, body = parts[i], parts[i + 1], parts[i + 2]
        refs = set()
        for sym in set(re.findall(r"DAT_([0-9a-fA-F]{8})", body)):
            v = datval(int(sym, 16))
            if v is not None and 0x40000000 <= v <= 0x40040000:
                refs.add(v)
            elif int(sym, 16) and 0x40000000 <= int(sym, 16) <= 0x40040000:
                refs.add(int(sym, 16))
        if refs:
            pretty = " ".join(f'{v:08X}' for v in sorted(refs))
            print(f"{name} @ {addr}: {pretty}")

def main():
    argv = sys.argv[1:]
    for j in range(0, len(argv), 2):
        print("=" * 30, argv[j + 1])
        run(argv[j], argv[j + 1])

if __name__ == "__main__":
    main()
