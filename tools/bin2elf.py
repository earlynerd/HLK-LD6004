"""Wrap a raw code image in a minimal ELF32 so the JieLi llvm-objdump can disassemble it.

Usage: python bin2elf.py <in.bin> <out.elf> --addr 0x1E00120 [--machine 0xF2]
e_machine 0xF2 is what the JieLi 2.5.2 clang emits for -target q32s (BD19/BD29).
"""
import argparse
import struct
from pathlib import Path

ap = argparse.ArgumentParser()
ap.add_argument('input', type=Path)
ap.add_argument('output', type=Path)
ap.add_argument('--addr', type=lambda s: int(s, 0), required=True)
ap.add_argument('--machine', type=lambda s: int(s, 0), default=0xF2)
ap.add_argument('--flags', type=lambda s: int(s, 0), default=0)
a = ap.parse_args()

code = a.input.read_bytes()
shstr = b'\0.text\0.shstrtab\0'
ehsize, shentsize = 52, 40
text_off = 0x100
shstr_off = text_off + len(code)
sh_off = (shstr_off + len(shstr) + 3) & ~3

ehdr = b'\x7fELF' + bytes([1, 1, 1, 0]) + bytes(8)
ehdr += struct.pack('<HHIIIIIHHHHHH', 2, a.machine, 1, a.addr, 0, sh_off, a.flags,
                     ehsize, 0, 0, shentsize, 3, 2)
sections = [
    bytes(shentsize),
    # .text: PROGBITS, ALLOC|EXECINSTR
    struct.pack('<IIIIIIIIII', 1, 1, 0x6, a.addr, text_off, len(code), 0, 0, 2, 0),
    # .shstrtab
    struct.pack('<IIIIIIIIII', 7, 3, 0, 0, shstr_off, len(shstr), 0, 0, 1, 0),
]
out = bytearray(ehdr.ljust(text_off, b'\0')) + code + shstr
out = out.ljust(sh_off, b'\0') + b''.join(sections)
a.output.write_bytes(out)
