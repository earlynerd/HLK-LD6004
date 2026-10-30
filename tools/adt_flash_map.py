"""Summarise an LD6004 ZB25VQ80 dump: boot header, app vs RAM image, used regions.

Usage: python tools/adt_flash_map.py FLASH.bin [APP_RAM_0x8000.bin]
"""
import struct, sys


def used_regions(d, gran=0x1000):
    out, start = [], None
    for a in range(0, len(d), gran):
        blank = d[a:a + gran] == b'\xff' * gran
        if not blank and start is None:
            start = a
        if blank and start is not None:
            out.append((start, a)); start = None
    if start is not None:
        out.append((start, len(d)))
    return out


def main():
    d = open(sys.argv[1], 'rb').read()
    print(f'size {len(d):#x}')
    ln, ln2, flag = struct.unpack_from('<HHB', d, 0)
    off = d[5] | d[6] << 8 | d[7] << 16
    print(f'boot header: len={ln:#x} len2={ln2:#x} flag={flag:#04x} code_off={off:#x} spi_div={d[8]:#x}'
          f' raw={d[:16].hex(" ")}')
    for s, e in used_regions(d):
        last = e - 1
        while last > s and d[last] == 0xff:
            last -= 1
        print(f'  used {s:#08x}-{e:#08x} (data ends {last + 1:#x})')
    if len(sys.argv) > 2:
        ram = open(sys.argv[2], 'rb').read()
        img = d[off:off + ln]
        same = sum(a == b for a, b in zip(img, ram[:ln]))
        print(f'app in flash vs RAM 0x8000: {same}/{ln} bytes equal')
        if same != ln:
            diffs = [i for i in range(ln) if img[i] != ram[i]]
            print('  first diffs at', [hex(0x8000 + i) for i in diffs[:16]])
    for base, n in ((0x10000, 0x20), (0x14000, 0x190)):
        print(f'@{base:#x}:')
        for a in range(base, base + n, 16):
            print(f'  {a:06x}: {d[a:a + 16].hex(" ")}')
    magic = struct.unpack_from('<I', d, 0x14000)[0]
    print(f'config magic {magic:#010x} ({"ok" if magic == 0xDEADBEFF else "not 0xDEADBEFF"})')


if __name__ == '__main__':
    main()
