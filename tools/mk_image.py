"""Wrap a raw app binary in the ADT6101P Boot Area image header.

Header (16 B, verified against stock images, see DEBUG_LOG 2026-10-29):
  +0  u16 len          (payload length)
  +2  u16 len          (repeated; must match, non-zero)
  +4  u8  0x5A         code-exists flag
  +5  u24 code offset  (0x10 -> payload right after header)
  +8  u8  SPI divider  (stock: 2)
  +9  u32 CRC32 big-endian of payload (zlib CRC-32); 0 = skip check
  +13 3 bytes 0        (unused in stock images)

Usage: python mk_image.py <payload.bin> <out.bin> [--crc]
"""
import argparse
import struct
import zlib
from pathlib import Path

ap = argparse.ArgumentParser()
ap.add_argument('payload', type=Path)
ap.add_argument('output', type=Path)
ap.add_argument('--crc', action='store_true', help='fill CRC32 instead of 0 (skip)')
ap.add_argument('--div', type=int, default=2)
a = ap.parse_args()

p = a.payload.read_bytes()
if len(p) > 0xFFFF:
    raise SystemExit('payload too long for u16 length field')

crc = zlib.crc32(p) & 0xFFFFFFFF if a.crc else 0
hdr = struct.pack('<HH', len(p), len(p))
hdr += bytes([0x5A, 0x10, 0x00, 0x00])          # flag + u24 code offset 0x10 LE
hdr += bytes([a.div & 0xFF])
hdr += struct.pack('>I', crc)                   # CRC32 big-endian @ +9
hdr += bytes(3)
assert len(hdr) == 16
a.output.write_bytes(hdr + p)
print(f'{a.output}: header len={len(p)} flag=5A coff=0x10 div={a.div} crc={"filled" if a.crc else "0 (skip)"}')
