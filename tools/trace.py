"""Find which decompiled functions reference a string (or address).

Usage: python trace.py <raw.bin> <decompiled.c> <substring | 0xADDR> [--body]
Prints the header + (optionally) full body of every function whose body
mentions the address (as DAT_xxxxxxxx or raw hex constant).
"""
import re
import sys

def functions(dec):
    txt = open(dec, encoding='utf-8', errors='replace').read()
    parts = re.split(r"/\* ===== (\S+) @ (\S+) ===== \*/", txt)
    out = []
    for i in range(1, len(parts) - 2, 3):
        out.append((parts[i], parts[i + 1], parts[i + 2]))
    return out

def main():
    img, dec, needle = sys.argv[1], sys.argv[2], sys.argv[3]
    show_body = '--body' in sys.argv
    data = open(img, 'rb').read()

    addrs = []
    if needle.startswith('0x'):
        addrs.append(int(needle, 0))
    else:
        pat = needle.encode()
        i = data.find(pat)
        while i != -1:
            addrs.append(0x8000 + i)
            i = data.find(pat, i + 1)
    if not addrs:
        print('not found'); return
    print('addresses:', [hex(a) for a in addrs])

    # Also find literal-pool words whose VALUE is the string address:
    # code reads those as DAT_<pooladdr>, so include the pool addresses too.
    import struct
    pool_addrs = []
    for a in addrs:
        pk = struct.pack('<I', a)
        j = data.find(pk)
        while j != -1:
            if j % 4 == 0:
                pool_addrs.append(0x8000 + j)
            j = data.find(pk, j + 1)
    if pool_addrs:
        print('pool words:', [hex(p) for p in pool_addrs])
    search = addrs + pool_addrs

    for name, addr, body in functions(dec):
        hit = False
        for a in search:
            forms = {
                'DAT_%08x' % a,
                'DAT_%08X' % a,
                '0x%x' % a,
                '%08x' % a,
                # short hex without leading zeros, word-boundaried
            }
            if any(f in body for f in forms) or re.search(r'\b0x0*%x\b' % a, body):
                hit = True
                break
        if hit:
            print(f'--- {name} @ {addr}')
            if show_body:
                print(body.strip())

if __name__ == '__main__':
    main()
