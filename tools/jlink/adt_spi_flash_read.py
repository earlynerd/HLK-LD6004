"""Read the LD6004 radar's external SPI NOR (ZB25VQ80) through the ADT6101P over SWD.

Halts the core, runs adt_spi_stub.bin from SRAM to issue read-only SPI commands,
then resets the target so it reboots normally. Never sends WREN (0x06), program
or erase opcodes; the opcode allow-list below is enforced before every transaction.

Something resets the target ~5 s after a debug halt (a watchdog that keeps running
while halted, or an external supervisor), so work is split into short sessions:
halt, read for BUDGET seconds, reset, let the app boot, repeat.

Usage: python tools/jlink/adt_spi_flash_read.py OUTDIR [--dump]
"""
import argparse, hashlib, json, os, time
import pylink

HERE = os.path.dirname(os.path.abspath(__file__))
STUB = 0x20002000
TXBUF = 0x20002100
RXBUF = 0x20002200
RXMAX = 0x2000          # 8 KiB per transaction max
SP = 0x20005FF0
QUIET = (0x20002000, 0x3000)   # must not change while halted
SPI_DIV = 0x10          # app's divider
CHUNK = 0x1000          # bytes per bulk-read transaction
BUDGET = 1.5            # seconds of halt per session
SETTLE = 1.0            # seconds to let the app boot after each reset
READ_OPS = {0x03, 0x05, 0x15, 0x35, 0x48, 0x4B, 0x5A, 0x90, 0x9F, 0xAB}


def rd(jl, addr, n):
    return bytes(jl.memory_read8(addr, n))


def wr(jl, addr, data):
    jl.memory_write8(addr, list(data))


def spi(jl, tx, rxlen, init=True, timeout=1.0):
    if tx[0] not in READ_OPS:
        raise ValueError(f'opcode {tx[0]:#04x} not in read-only allow-list')
    assert rxlen <= RXMAX and len(tx) <= 0x100
    wr(jl, TXBUF, tx)
    for name, v in (('R0', TXBUF), ('R1', len(tx)), ('R2', RXBUF), ('R3', rxlen),
                    ('R4', SPI_DIV if init else 0), ('R13 (SP)', SP), ('R15 (PC)', STUB),
                    ('XPSR', 0x01000000)):
        jl.register_write(name, v)
    jl.restart(num_instructions=0, skip_breakpoints=True)
    t0 = time.time()
    while not jl.halted():
        if time.time() - t0 > timeout:
            jl.halt()
            raise TimeoutError(f'stub did not halt; PC={jl.register_read("R15 (PC)"):#x}')
        time.sleep(0.002)
    pc = jl.register_read('R15 (PC)')
    if not (STUB <= pc < STUB + 0x100):
        raise RuntimeError(f'halted outside stub at PC={pc:#x}')
    return rd(jl, RXBUF, rxlen) if rxlen else b''


def connect():
    jl = pylink.JLink()
    jl.open()
    jl.set_tif(pylink.enums.JLinkInterfaces.SWD)
    jl.set_speed(4000)
    jl.connect('Cortex-M3', verbose=False)
    return jl


class Session:
    def __init__(self):
        self.jl = connect()
        self.stub = open(os.path.join(HERE, 'adt_spi_stub.bin'), 'rb').read()
        self.count = 0

    def begin(self):
        jl = self.jl
        jl.halt()
        t0 = time.time()
        q0 = rd(jl, *QUIET)
        time.sleep(0.2)
        changed = sum(x != y for x, y in zip(q0, rd(jl, *QUIET)))
        if changed:
            raise RuntimeError(f'{changed} bytes changed in stub region while halted (DMA?)')
        wr(jl, STUB, self.stub)
        assert rd(jl, STUB, len(self.stub)) == self.stub
        self.count += 1
        return t0

    def end(self):
        self.jl.reset(halt=False)
        time.sleep(SETTLE)

    def reconnect(self):
        try:
            self.jl.close()
        except Exception:
            pass
        time.sleep(3)
        self.jl = connect()


def read_ids(s, outdir):
    jl = s.jl
    s.begin()
    ids = {}
    ids['RES_AB'] = spi(jl, b'\xAB\x00\x00\x00', 1).hex()
    ids['JEDEC_9F'] = spi(jl, b'\x9F', 3).hex()
    ids['REMS_90'] = spi(jl, b'\x90\x00\x00\x00', 2).hex()
    ids['UID_4B'] = spi(jl, b'\x4B\x00\x00\x00\x00', 16).hex()
    ids['SR1_05'] = spi(jl, b'\x05', 1).hex()
    ids['SR2_35'] = spi(jl, b'\x35', 1).hex()
    ids['SR3_15'] = spi(jl, b'\x15', 1).hex()
    sfdp = spi(jl, b'\x5A\x00\x00\x00\x00', 256)
    open(os.path.join(outdir, 'sfdp.bin'), 'wb').write(sfdp)
    ids['SFDP_head'] = sfdp[:16].hex()
    for n in range(4):
        sec = spi(jl, bytes([0x48, 0, n << 4, 0, 0]), 256)
        open(os.path.join(outdir, f'secreg{n}.bin'), 'wb').write(sec)
        ids[f'SECREG{n}_48'] = 'all FF' if sec == b'\xff' * 256 else sec[:32].hex() + '...'
    s.end()
    return ids


def read_array(s, size):
    chunks, pending, retries = {}, list(range(0, size, CHUNK)), 0
    while pending:
        try:
            t0 = s.begin()
            while pending and time.time() - t0 < BUDGET:
                addr = pending[0]
                cmd = bytes([0x03, addr >> 16 & 0xff, addr >> 8 & 0xff, addr & 0xff])
                chunks[addr] = spi(s.jl, cmd, CHUNK)
                pending.pop(0)
            s.end()
        except Exception as e:
            retries += 1
            print(f'  session lost at {pending[0]:#08x} ({e}); reconnecting', flush=True)
            if retries > 10:
                raise
            s.reconnect()
        done = size - len(pending) * CHUNK
        if done % 0x20000 == 0 or not pending:
            print(f'  {done:#08x}/{size:#x}', flush=True)
    return b''.join(chunks[k] for k in sorted(chunks))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('outdir')
    ap.add_argument('--dump', action='store_true', help='read the whole array twice')
    a = ap.parse_args()
    os.makedirs(a.outdir, exist_ok=True)

    s = Session()
    log = {}
    try:
        ids = read_ids(s, a.outdir)
        log['ids'] = ids
        for k, v in ids.items():
            print(f'{k:12s} {v}')
        if a.dump:
            jedec = bytes.fromhex(ids['JEDEC_9F'])
            size = 1 << jedec[2] if 0x10 <= jedec[2] <= 0x18 else 0x100000
            imgs = []
            for p in range(2):
                print(f'pass {p}: reading {size:#x} bytes', flush=True)
                imgs.append(read_array(s, size))
            for p, img in enumerate(imgs):
                open(os.path.join(a.outdir, f'zb25vq80_{"ab"[p]}.bin'), 'wb').write(img)
            log['dump_size'] = size
            log['dump_identical'] = imgs[0] == imgs[1]
            log['sha256'] = [hashlib.sha256(i).hexdigest() for i in imgs]
            print('identical:', log['dump_identical'], log['sha256'][0])
    finally:
        try:
            s.jl.reset(halt=False)
            log['reset'] = 'reset and run'
        except Exception as e:
            log['reset'] = f'failed: {e}'
        log['sessions'] = s.count
        json.dump(log, open(os.path.join(a.outdir, 'probe_log.json'), 'w'), indent=2)
        s.jl.close()


if __name__ == '__main__':
    main()
