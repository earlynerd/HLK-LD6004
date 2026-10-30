"""Offline unpacker for JieLi "new-format" flash images (BR23+/BD19 era).

Reads a raw flash dump, descrambles the flash header and top-level JLFS
entries (ENC cipher, key 0xFFFF), then decrypts the app area with the chip
key (SFC cipher) and extracts every file. Writes:
  <out>/decrypted.bin   whole image with every recognised region descrambled
  <out>/top/<name>      top-level files (uboot.boot, isd_config.ini, ...)
  <out>/files/<name>    app-area files (app.bin, cfg_tool.bin, ...)
  <out>/layout.json     offsets, sizes, flags, CRC checks

Format knowledge follows kagaimiq/jl-misctools (fwunpack_newfw.py); this is
an independent reimplementation with no third-party dependencies.

Usage: python jl_fw_unpack.py <flash.bin> <outdir> [--chipkey 0xA80F]
"""
import argparse
import json
import struct
from pathlib import Path


def crc16(data, crc=0):
    # CRC-16/XMODEM (poly 0x1021, init 0), as used throughout JieLi images
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) & 0xFFFF if crc & 0x8000 else (crc << 1) & 0xFFFF
    return crc


def enc_cipher(buf, off, size, key=0xFFFF):
    for i in range(size):
        buf[off + i] ^= key & 0xFF
        key = ((key << 1) ^ (0x1021 if key & 0x8000 else 0)) & 0xFFFF


def sfc_cipher(buf, off, size, base, key, block=32):
    for i in range(0, size, block):
        enc_cipher(buf, off + i, min(size - i, block), key ^ ((off + i - base) >> 2))


def chipkeybin_decode(data):
    s = sum(data[:16]) & 0xFF
    s = 0xAA if s >= 0xE0 else 0x55 if s <= 0x10 else s
    return sum(1 << i for i in range(16) if (data[16 + i] ^ data[15 - i]) < s)


def align32(v):
    return (v + 31) & ~31


def cstr(b):
    return b.split(b'\0', 1)[0].decode('ascii', 'replace')


class Entry:
    def __init__(self, buf, off, database, data_after_header=False):
        hcrc, hdr = struct.unpack_from('<H30s', buf, off)
        if crc16(hdr) != hcrc:
            raise ValueError(f'JLFS entry header CRC mismatch at 0x{off:X}')
        self.data_crc, self.offset, self.size, self.flags, self.resvd, self.index, name = \
            struct.unpack('<HIIBBH16s', hdr)
        self.hdr_off = off
        self.name = cstr(name)
        if data_after_header:
            self.data_offset = off + 32
            self.data_size = off + self.size - self.data_offset
        else:
            self.data_offset = self.offset + database
            self.data_size = self.size

    def as_dict(self, buf):
        d = dict(name=self.name, hdr_off=hex(self.hdr_off), data_off=hex(self.data_offset),
                 size=self.data_size, flags=hex(self.flags), index=self.index)
        if 0 <= self.data_offset and self.data_offset + self.data_size <= len(buf):
            d['data_crc_ok'] = crc16(buf[self.data_offset:self.data_offset + self.data_size]) == self.data_crc
        return d


def iter_entries(buf, base, off, key=None, sfc=False):
    """Walk a JLFS entry chain, descrambling in place as it goes."""
    dec_off = base
    while True:
        entoff = base + off
        if key is not None:
            if sfc:
                nxt = align32(entoff + 32)
                if dec_off < nxt:
                    sfc_cipher(buf, dec_off, nxt - dec_off, base, key)
                    dec_off = nxt
            else:
                enc_cipher(buf, entoff, 32, key)
        e = Entry(buf, entoff, base, sfc)
        last = e.index != 0
        if sfc:
            off += e.size
            if key is not None:
                nxt = base + off
                if not last:
                    nxt = align32(nxt + 32)
                if dec_off < nxt:
                    sfc_cipher(buf, dec_off, nxt - dec_off, base, key)
                    dec_off = nxt
        else:
            off += 32
        yield e
        if last:
            return


def descramble_bankcb(buf, base, key=0xFFFF):
    count, i = 1, 0
    while i < count:
        h = base + i * 16
        enc_cipher(buf, h, 16, key)
        hdr, hcrc = struct.unpack_from('<14sH', buf, h)
        if crc16(hdr) != hcrc:
            raise ValueError(f'bank {i} header CRC mismatch')
        bank_id, bank_size, _load, bank_off, _bcrc = struct.unpack('<HHIIH', hdr)
        if i == 0:
            count = bank_id
        enc_cipher(buf, base + bank_off, bank_size, key)
        i += 1


def unpack(fw, out, chipkey_override=None):
    layout = {}
    base = None
    for off in (0, 0x1000, 0x10000, 0x80000, 0x100000, 0x180000):
        hdr = bytearray(fw[off:off + 32])
        enc_cipher(hdr, 0, 32)
        hcrc = int.from_bytes(hdr[:2], 'little')
        if hcrc and crc16(hdr[2:]) == hcrc:
            # VID (4..8) and PID (16..32) are stored in the clear
            hdr = hdr[:4] + fw[off + 4:off + 8] + hdr[8:16] + fw[off + 16:off + 32]
            base = off
            break
    if base is None:
        raise RuntimeError('flash header not found')
    _, burner, vid, flash_size, fsver, align, _, specopt, pid = struct.unpack('<HH4sIBBBB16s', hdr)
    layout['header'] = dict(base=hex(base), burner_size=burner, vid=cstr(vid), flash_size=hex(flash_size),
                            fs_version=fsver, block_align=align, special_opt=hex(specopt), pid=cstr(pid))

    top = out / 'top'
    top.mkdir(parents=True, exist_ok=True)
    chipkey_fw, app_base, layout['top'] = None, None, []
    for i, e in enumerate(iter_entries(fw, base, 32, key=0xFFFF)):
        layout['top'].append(e.as_dict(fw))
        if i == 0:
            descramble_bankcb(fw, e.data_offset)  # first entry is the SPL (uboot.boot)
        elif e.flags == 0x81:
            if e.name == 'app_dir_head' and app_base is None:
                app_base = e.data_offset
            continue
        elif e.flags & 0x10:
            continue  # reserved area (e.g. key_mac)
        elif e.name == 'isd_config.ini':
            ck, ckcrc = struct.unpack_from('<32sH', fw, e.data_offset)
            if crc16(ck) == ckcrc:
                chipkey_fw = chipkeybin_decode(ck)
        (top / e.name).write_bytes(fw[e.data_offset:e.data_offset + e.data_size])

    layout['chipkey_from_isd_config'] = None if chipkey_fw is None else hex(chipkey_fw)
    key = chipkey_override if chipkey_override is not None else chipkey_fw
    if app_base is None or key is None:
        raise RuntimeError(f'app_base={app_base} key={key}: cannot decrypt app area')
    layout['chipkey_used'] = hex(key)

    files = out / 'files'
    files.mkdir(exist_ok=True)
    layout['app'], layout['res'] = [], []
    for i, e in enumerate(iter_entries(fw, app_base, 0, key=key, sfc=True)):
        if i == 0:
            layout['entry_point'] = hex(e.offset)
            for a in iter_entries(fw, e.hdr_off, e.data_offset - e.hdr_off):
                layout['app'].append(a.as_dict(fw))
                if not a.flags & 0x10:
                    (files / a.name).write_bytes(fw[a.data_offset:a.data_offset + a.data_size])
        else:
            layout['res'].append(e.as_dict(fw))
            if e.flags & 0x10:
                continue
            if e.flags == 0x82:
                (files / e.name).write_bytes(fw[e.data_offset:e.data_offset + e.data_size])
            else:
                (files / e.name).write_bytes(fw[e.hdr_off:e.hdr_off + e.size])
                if e.flags == 0x83:  # directory
                    sub = files / f'{e.name}-extracted'
                    sub.mkdir(exist_ok=True)
                    for a in iter_entries(fw, e.hdr_off, e.data_offset - e.hdr_off):
                        (sub / a.name).write_bytes(fw[a.data_offset:a.data_offset + a.data_size])
    return layout


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('input', type=Path)
    ap.add_argument('outdir', type=Path)
    ap.add_argument('--chipkey', type=lambda s: int(s, 0))
    a = ap.parse_args()
    fw = bytearray(a.input.read_bytes())
    a.outdir.mkdir(parents=True, exist_ok=True)
    layout = {}
    try:
        layout = unpack(fw, a.outdir, a.chipkey)
    finally:
        (a.outdir / 'decrypted.bin').write_bytes(fw)
        (a.outdir / 'layout.json').write_text(json.dumps(layout, indent=2))
    print(json.dumps(layout, indent=2))


if __name__ == '__main__':
    main()
