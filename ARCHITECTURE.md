# HLK-LD6004 architecture

The module has two processors. The **Andar ADT6101P** radar SoC does all sensing and signal processing, and runs its firmware from an external **ZB25VQ80** SPI NOR. A **JieLi AC6323A4** Bluetooth MCU is a BLE↔UART bridge on the radar's single TinyFrame UART. It handles one command itself and relays firmware updates. It does no radar processing.

Evidence tags: **[HW]** verified on this board by reading the hardware; **[FW]** inferred from firmware disassembly or strings; **[DS]** vendor datasheet or protocol PDF; **[?]** hypothesis, not yet tested. Dated details are in `DEBUG_LOG.md`.

## Block diagram

```
                       BLE (name "LD6004-%02X%02X")                    [FW]
                                   │
                    ┌──────────────┴──────────────┐
                    │ JieLi AC6323A4 (BD19/AC632N) │  512 KiB internal flash      [HW]
                    │ HLK BLE↔UART bridge          │  chip key 0xA80F             [HW]
                    └───┬─────────────┬────────────┘
        HLK_UART PB06/PB07 115200     │ AT_CHAR_COM PA01/PA02, baud from 0x0F0F  [FW]
        (radar link)                  │ (board connection unknown)               [?]
                        │
   header TX0/RX0 ──────┤  UART0, 115200, TinyFrame                     [FW][DS]
   (P00/P01)            │  JieLi tap on this net not continuity-tested   [?]
                    ┌───┴──────────────────────────┐
   SWCLK/SWDIO ─────┤ Andar ADT6101P               │  Cortex-M3 r2p1, no read protection [HW]
   BOOT1 (pin 8) ───┤ 58–64 GHz radar SoC [DS]      │  2TX/2RX (App2 test strings) [FW]
   OUT (P20) ───────┤                               │
                    └───┬──────────────────────────┘
                        │ SPI @0x4000E000, CS = GPIO4                     [HW]
                    ┌───┴──────────────┐
                    │ Zbit ZB25VQ80     │  1 MiB, no block protection      [HW]
                    └───────────────────┘
```

## ADT6101P (radar SoC)

- **Core:** Cortex-M3 r2p1, SW-DP `0x2BA01477`, one AHB-AP. There is no readout protection [HW].
- **Memory map** [HW]:
  - `0x00000000–0x0001FFFF` is a 128 KiB code window, mirrored every 0x20000.
    - `0x0000–0x7FFF` holds the ROM-resident **Bootloader V6.3.0**. It is not in the SPI flash, so it is internal.
    - `0x8000–` is where the running application is loaded.
  - `0x20000000–0x2002FFFF` is SRAM. `0x20030000+` is unreadable. App `.data`/`.bss` sit below about `0x20006030`. `0x20008000+` is sample buffers, which change constantly.
- **Peripherals:**

  | Address | Block | Notes |
  |---|---|---|
  | `0x40001000` | unknown | 2 constant refs in App1/App2 [FW] |
  | `0x40002000` | unknown | 2 constant refs [FW] |
  | `0x40003000` | **radar front end** | Heavily used. Register setters at `+0x108…+0x278`, `+0x3800…+0x3968`. Live reads from `+0x100` up return non-zero config (`+0x110=E051`, `+0x150=8F8`, `+0x160=1FA3`, `+0x210=1F83E0`, `+0x218/1C=5A5`, `+0x220=02940008`×2). `+0x12C/+0x130` are 4-bit-field chirp/channel regs [FW][HW] |
  | `0x40004000` | UART0 | P00/P01. The app's only UART: 115200, TinyFrame [FW] |
  | `0x40005000` | UART1 | P10/P11. ROM bootloader console at 115200 [FW] |
  | `0x40006000` | UART2 | P20/P21. P20 is also the "OUT" presence pin [FW][DS] |
  | `0x40008000` | **RF synthesizer** | Live: `+0=500000000`, `+4=496200963` (Hz). Driver writes freq to `+0`, then `+C=1`, `+C=3`. `+4` is a **sawtooth FMCW sweep counter**: counts down from `0x1DCD6500` (500e6) at ~100e6/s and wraps every **5.0 s**; each wrap asserts the NMI (see Debug caveat). **`+0x10` and `+0x14` latch `0 → 1` at each wrap and stay set** — candidate NMI status/ack. Live `+0x08 = 3`, `+0x0C = 0`, which does not match the `+C=1` then `+C=3` sequence seen in firmware [HW][FW] |
  | `0x40009000` | I²C-style controller | Bootloader "Jump to EEPROM" path, device address 0x50 [FW][?] |
  | `0x4000C000` | timer / DSP trigger | Many app writes; live `+0x10=43FF`, `+0x14=BFF`, `+0x20=B7A2` [FW][HW] |
  | `0x4000D000` | ID-like | Live `+0=484D2312` [HW][?] |
  | `0x4000E000` | SPI (flash) | DR +0x08; SR +0x0C (b0 TX done, b2 RX ready, b4 busy); divider +0x10 [HW] |
  | `0x4000F000` | RF/PLL config | Byte writes at `+0x20…+0x25`, `+0x30`, `+0x4F`, `+0x80`, `+0x1C0`; reads 0 while idle (gated?) [FW][HW][?] |
  | `0x40010000` | config regs | Live `+0=02010802 +4=05050008 +10=77000000` [HW][?] |
  | `0x40012000` | unknown | 1 ref [FW] |
  | `0x40020000` | GPIO / pin mux / clocks | Pin mux at `+0x30 + 4*pin` (1 = UART fn, `0xB0` = boot-pin fn); GPIO set `+0x20`, clear `+0x24`, **boot-pin input status `+0x2C`** (bit 12 = P12/BOOT0, bit 19 = P19/BOOT1) [HW][FW] |
  | `0x40021000` | **DMA/DSP engine** | 5 channels: `src@+0x10+16n`, `dst@+0x14+16n`, `ctrl@+0x18+16n`; sizes `+0x60…+0x70` as `in|out<<16`; busy/status `+0x58`; ctrl words carry `0x1B…` mode bits. Second instance at `0x40021200`. FFT/Doppler kernels are engine jobs, not software FFT [FW][HW] |
  | `0x40022000` | System control | Bootloader sets `+0x10=1` before launching the app. Function unknown [FW] |
  | `0x40023000` | **ADC sample port** | Live DMA source into sample buffers (`0x40023000/04` → `0x20022800`/`0x20025D00`); live values look like packed I/Q samples [HW] |
  | `0x40024000` | unknown | 2 refs [FW] |

  Clock is 50 MHz: UART divisor = 50 MHz / baud [FW].
- **Debug caveat — the "post-halt reset" is not a reset, not a fault, and not a measured lockup** [HW]: the radar asserts an **NMI at every FMCW ramp wrap**. `0x40008004` counts down from `0x1DCD6500` (500,000,000) at ~100e6/s, i.e. a **5.0 s ramp**. App1's NMI handler (vector[2] = `0xa369` → code at `0xa368`) is an empty `bx lr`, so a running core simply takes and discards it; a **halted** core cannot, and the NMI latches pending — `ICSR` goes `0x00C14000` → `0x80C02000` (bit 31 set, VECTPENDING = 2) exactly at the wrap. It **cannot be cleared**: writing `ICSR` bit 27 (NMICLR) on all 20 polls left it pending every time, so the source is level-asserted. The AP then stops answering at the **next** wrap — t = 9.13 / 9.14 / 9.11 / 9.03 / 8.98 s across five runs, i.e. two wraps, not "5 s after halt". **The lockup hypothesis is not supported by measurement**: at the last readable sample before the AP dies `DHCSR = 0x00030003` → **`S_LOCKUP = 0`**, and `HFSR = 0` (no fault); `DFSR = 1` (DWTOPCN) is debugger residue. J-Link's reconnect prints `Could not start CPU core. (ErrorCode: -1)`. Nothing resets — `0x4000C020`, `0x40022000+0x00`, the vector table at `0x8000` and the ADC stream are all continuous and the boot chain never re-runs. **New lead:** `0x40008010` and `0x40008014` latch `0 → 1` exactly at each wrap and stay set — the prime candidate for the NMI source/ack register. **Do not trust `S_HALT` on this part:** `DHCSR` reports `S_HALT = 0` in every sample even though the core is demonstrably halted (`0x40022000+0x00` and the sample buffer are frozen). Practical rule: budget halt time against the **ramp**, not a fixed timeout — read `0x40008004` right after halting, compute time-to-wrap (≤5.0 s), finish before it. Reproduce: `tools/jlink/probe_halt_reset.py`, `probe_nmi_clear.py` (NMICLR does not help), `probe_nmi_source.py` (wrap-only registers), `probe_lockup.py`. `0x40022000` is not implicated: `+0x00` does freeze while halted and writes to `+0x1C` change nothing.

## Boot chain

1. The ROM **Bootloader V6.3.0** checks the boot pins [FW][DS]. BOOT1 (header pin 8) must be low for a normal boot; both boot pins have pull-ups. Its alternative paths are "Load bin file to RAM" (a HyperTerminal/YMODEM upload), "Jump to EEPROM", and "debug mode". Full trace below [FW].
2. On a normal boot it reads the header at flash `0x0`, then copies the **jump code** (0xFFC bytes) to RAM `0x8000` and runs it [HW][FW].
3. The jump code loads the **Boot Area v2.0.7** from flash `0x8000`, which runs from SRAM around `0x20009000` [HW].
4. The Boot Area reads the boot settings at `0x10000`, checks the CRC32 of the selected app, and loads **App1** from `0x18000` (or **App2** from `0x38000`) into RAM `0x8000` [FW].

### ROM bootloader paths (V6.3.0, traced 2026-10-29) [FW]

Addresses are offsets in the ROM image dumped at `0x0` (`dumps/2026-10-29/radar_swd/adt6101p_boot_0x0000.bin`).

- **Entry** `0xe0` → init `0x104`: writes `0x40022000+0x1C = 1` then `2`, brings up the console UART at 115200, then (RAM-load path, `0x11c`) writes `0xFFFFFFFF` to `0xE000E180` (**NVIC ICER0**) — the ROM runs with **all interrupts disabled**.
- **Boot pins:** ROM sets mux `0x40020060` and `0x4002007C` to **`0xB0`** (boot-pin function), delays, then reads **`0x4002002C & 0x81000`** and dispatches at `0xe20`:

  | status | path | SoC pins |
  |---|---|---|
  | `0x000000` | **Load bin file to RAM** | P19=0, P12=0 |
  | `0x001000` | Jump to flash (normal boot) | P19=0, P12=1 |
  | `0x080000` | Jump to EEPROM | P19=1, P12=0 |
  | `0x081000` | "This is debug mode" | P19=1, P12=1 |

  So **BOOT1 = SoC P19 (bit 19), BOOT0 = SoC P12 (bit 12)**; the datasheet documents only the `0/1` row. RAM-load needs **both** low. Pin identity is inferred from the bit positions and the ROM's own mux writes, not continuity-tested [?].
- **Console = UART1 `0x40005000`, pins P10 (mux 1) / P11 (mux 0x81)**, 115200: init `0x580` (divisor `50000000/baud` at `+0x10`, `+0x08 = 0xb`), getc `0x170` (ack `+0xC=2`, poll `+0x04` bit1, read `+0x00`), putc `0x54a` (poll `+0x04` bit0, write `+0x00`). The ROM also contains UART0 (`0x40004000`, P00/P01, init `0x55e`) and UART2 (`0x40006000`, P20/P21, init `0x5a2`) bring-ups, but **no ROM I/O uses them**.
- **"Load bin file to RAM" protocol:** YMODEM/CRC-16-CCITT. Receiver sends `'C'` (0x43), packets are **133 bytes** (type, blk, ~blk, 128 data, CRC-16 **big-endian**), ACK `0x06`, NAK `0x15`, block 0 is the filename block (type 1), EOT is type 4. Staging buffers `0x20019000` (current record) and `0x20020000` (record array).
- **The payload is copied verbatim to `0x8000`** (`0x798`–`0x7c2`: packet data offsets 3…130 → `0x8000 + n`). **No 16-byte image header is expected or stripped on this path** — the file's byte 0 must be the vector table. After EOT the ROM restores pin muxes, `dsb`/`isb` (`0x63c`), then the launch trampoline at **`0xd4`**: `SP = [0x8000]`, `PC = [0x8004]`, `bx`. Nothing is written to flash.
- **"Jump to flash"** (`0xcb6`) is the stage-2 loader: reads 9 bytes of the flash header at `0x0` (`len`, `len`, flag `0x5A`, code offset `0x10`, SPI divider), sets the SPI divider at `0x4000E000+0x10`, reads `len` bytes from flash `0x10` into `0x8000`, then uses the same `0x63c`/`0xd4` launch. The 16-byte header belongs to **this** path and to the Boot Area OTA, not to RAM load.


## ZB25VQ80 flash map [HW]

- **Chip:** JEDEC `5E 60 14`. SFDP v1.7: 4K/32K/64K erase, quad-capable, 2.3–3.6 V. 128-bit UID. Status registers all 0. Security registers blank.
- **Image header:** every image starts with 16 bytes: `u16 len, u16 len, u8 0x5A (code exists), u24 code offset (=0x10), u8 SPI divider (=2), u32 CRC32 big-endian @+9, 3 bytes`. Verified against all four stock images: CRC32 (zlib/reflected, init `FFFFFFFF`, final invert — table-driven in the Boot Area) over `len` bytes starting at image offset `0x10`, stored **big-endian** at header `+9`. **A zero CRC field means "skip the check"** — the Boot Area prints "NO CRC check of the bin file!"; App1/App2 stock images both use 0. Same format as Hi-Link's LD6002B OTA `.bin` files.

| Offset | Size | Contents |
|---|---|---|
| `0x000000` | 0xFFC | Jump code (stage 2) |
| `0x008000` | 0x3034 | Boot Area v2.0.7: App1/App2 selection, CRC32 check, UART update over YMODEM ("SOH" frames), factory mode |
| `0x010000` | sector | Boot settings `02 AA 00 FF 02 FF 02`. Holds isUpdateFg/updateAppxFg/loadFg/factoryFg; the byte mapping is unknown [?] |
| `0x014000` | ≤0x184 read | Config log. Records start with magic `0xDEADBEFF` (at 0x14000, 0x14068, 0x140E4) and contain float32 payloads that look like detection-area bounds [?] |
| `0x018000` | 0xDABC | **App1**, "ADT6101P human detection 3d". Byte-identical to RAM `0x8000` |
| `0x038000` | 0x9E4C | **App2**, a factory test/calibration image: per-TX/RX distance/power tests, antenna phase calibration, noise, ADC bias |
| `0x048000` | 60 B | Calibration struct slot [FW]: `[u32 flag][u32 cksum][4 float phaseComp][u32 cksum][3 u32]`, cksum = `~(XOR+1)`. **Blank on this unit** [HW] → phase calibration not stored here |
| rest | — | Blank (0xFF) |

The app writes to flash itself [FW], using the commands 0x06, 0x20, 0x02, 0x03, 0x05 and 0x90:
- TF `0x3000` (OTA) rewrites the boot-settings sector (byte 1 := 0xFF), then resets.
- TF `0x4000` writes `0x02` to `0x10007`.

## Serial link and protocol

- **Physical layer:** plain asynchronous UART, 115200, 8 data bits, no 9-bit mode [FW]. The radar's baud is hard-coded. The JieLi's `HLK_UART` (PB06/PB07) runs at 115200, stored in its config as 230400 (115200<<1, a bitfield). Its RX callback `0x1E05FAE` feeds the UART→BLE handler.
- **UART register interface** [FW: Boot Area putc + app init + ROM getc/putc]: `+0x00` TX data write, `+0x04` bit0 = TX busy (poll), `+0x08` = `0xb` enable/mode, `+0x10` = clock/baud divisor (50 or 100 MHz / baud). RX: ack `+0x0C = 2`, poll `+0x04` bit1, read `+0x00`. Pinmux `0x40020030+4*pin`: UART0 P00=1, P01=0x81; UART1 P10=1, P11=0x81; UART2 P20=P21=1. App TX normally goes through the DMA engine (`0x40021000`), but polled TX works (Boot Area and ROM both use it).
- **Framing:** TinyFrame [DS][FW]. Fields are `SOF(01) ID(2) LEN(2) TYPE(2) HEAD_CKSUM(1) DATA(N) DATA_CKSUM(1)`. The header fields and checksums are big-endian, DATA is little-endian, and each checksum is the XOR of its bytes, inverted. Every command is acknowledged with an empty frame of the same TYPE. Example: `01 00 01 00 00 30 00 CF` (TYPE 0x3000).
- **Internal TF types** [FW]: App1's transmitter `FUN_0000b258(type, buf, len)` also emits `0x0A04, 0x0A08, 0x0A0B…0x0A18` — parameter/state frames whose SRAM buffers (live-read 2026-10-29) hold: area bounds as float32 (`-6,6,-6,6,0.5,6…` @`0x20000DD8`, 96 B), flags (1 B), thresholds (`0xC8=200, 3` @`0x2000003C`), phase-comp values (96 B @`0x20000E38`, all zero on this unit). App2 sends `0x0A10` with 20 B = channel + distance/speed/power floats per TX/RX pair, and `0x0A16/0x0A17` with calibration results. These are the natural hooks for a richer export.
- **Low-power mode:** when unattended the radar sleeps. Pull RX0 low, or send the configuration message, to wake it [DS].
- **What the JieLi does with the traffic** [FW]:
  - It forwards traffic transparently in both directions.
  - It handles TF `0x0F0F` itself: an index 0..5 selects 9600, 115200, 128300, 256000, 460800 or 921600 baud for its *own* `AT_CHAR_COM` port, and the setting is saved in VM item 51.
  - TF `0x000D` with non-zero data arms a 500 ms timer; its purpose is unknown.
  - It inspects `0x0A0A` presence frames.
  - It treats a lone `'C'` from the radar as the radar being in OTA mode.

There is no second data channel between the chips [FW]. The JieLi sees only what the public header carries.

## Firmware update flow [FW][?]

1. A host, over BLE through the JieLi or directly on the header, sends TF `0x3000`.
2. The radar app sets the update flag at `0x10000` and resets.
3. The Boot Area enters update mode and sends `'C'` (the YMODEM-CRC receiver start).
4. The image arrives as YMODEM packets. The JieLi only relays them and logs "6004 in OTA mode".
5. The Boot Area checks the CRC32, writes the App slot, updates the boot settings, and loads the new app.

Vendor tools: Hi-Link's app, and Andar's "ANDAR OTA.exe" (not run). Only a CRC32 integrity check was found; no signature verification was seen [FW][?].

## JieLi AC6323A4 (BLE bridge)

- **Chip** [HW]: BD19 / AC632N, 512 KiB internal flash (ID `0xCD7113`), chip key `0xA80F`. The image is encrypted with the chip key, and `tools/jl_fw_unpack.py` decrypts it.
- **Firmware** [FW]:
  - Built by HLK from project `hlk-b25` on the JieLi AC63 SDK example `spp_and_le/at_char_com`.
  - FW string `HLK-LD6004(b.1.04.120250905150452)`.
  - Its modules are `HLK_UART` (the radar link) and `HLK_CMDS` (command interception), plus RCSP OTA for the JieLi itself.
- **Pins** [FW]: `isd_config.ini` sets the JieLi log output to PA05 at 1 Mbaud; that the app actually uses it is unverified. Reset is `PB01_08_0`.

## Access points

- **Radar SWD** (header: GND, SWCLK, SWDIO, BOOT1, 3V3): full memory read/write and the SPI flash through a RAM stub. J-Link is set as a generic Cortex-M3 [HW].
- **Radar UART0** (header TX0/RX0 = P00/P01): TinyFrame commands and Boot Area YMODEM updates [DS][FW].
- **Radar UART1** (P10/P11): the **ROM** console and the "Load bin file to RAM" port [FW]. **Not brought to the module header** — using that ROM path needs a tap on P10/P11 (test-point mapping unknown) [?].
- **Radar BOOT1 / BOOT0** (header pins 8 / 12 = SoC P19 / P12): select the ROM bootloader path [DS][FW].
- **JieLi USB UBOOT:** uses the JieLi programmer with DIP 1 on and a separate 3.3 V supply for the radar; the radar's power cycle enters UBOOT. `kagaimiq/jl-uboot-tool` then reads or writes the internal flash [HW].

## Stock backups

| Device | Location | sha256 |
|---|---|---|
| JieLi flash | `dumps/2026-10-29/jieli_flash_{a,b}.bin` | `83e2dfd0…4484ed9` |
| Radar SPI flash | `dumps/2026-10-29/radar_spi_flash/zb25vq80_{a,b}.bin` | `e9a61b63…1719b104` |
| Radar RAM code | `dumps/2026-10-29/radar_swd/` | — |

Each pair was read twice and is byte-identical.

## Open questions

- Which block asserts the NMI at each FMCW ramp wrap, and can it be masked or acked so that long halt sessions become possible? The core's pending bit cannot be cleared while the source is asserted, so the lever has to be on the source side (`0x4000C000` timer or the DSP engine are the candidates).
- Which of the 12 board test points reach **P10/P11** (the ROM console / RAM-load port) and P12/P19 (boot pins)? Without that, the ROM "Load bin file to RAM" path is not reachable from the header.
- Byte meanings in the boot settings at `0x10000`; what TF `0x4000` (write to `0x10007`) does; how factory mode selects App2.
- Where the factory calibration results (antenna phase compensation) are stored: the config log, App1 constants, or radar SoC registers?
- Physical wiring: whether JieLi PB06/PB07 tap the radar UART0 / header nets, and where `AT_CHAR_COM` (PA01/PA02) goes.
- What the 7 trailing header bytes are (CRC32?) and how the Boot Area validates App1/App2.
- What the second SPI instance in the radar driver (CS on pin 14) and the `0x40009000` controller are connected to.
- What TF `0x000D` (the JieLi's 500 ms timer) is for.

## Tools

- `tools/jlink/adt_spi_flash_read.py` + `adt_spi_stub.S/.bin`: read-only SPI flash access through SWD.
- `tools/adt_flash_map.py`: summarises a ZB25VQ80 dump.
- `tools/jl_fw_unpack.py`: decrypts and unpacks the JieLi image.
- `tools/bin2elf.py`: wraps the JieLi app for `llvm-objdump` (q32s).
- `tools/jlink/*.jlink`: J-Link Commander scripts for the read-only SWD identification and dumps.
- `tools/jlink/probe_halt_reset.py`: halt and poll on a fixed timebase. Shows the post-halt failure is a **lockup at the second FMCW ramp wrap**, not a reset. `tools/jlink/probe_nmi_clear.py` is the follow-up (ICSR NMICLR does not help).
- `tools/xref.py`: find literal-constant cross-references in a raw image and name the enclosing Ghidra function.
- **pylink only exists on Python 3.14** here (`C:\Program Files\Python314\python.exe`); the 3.12 default has no pylink. pylink 2.0.1 has **no `go()`** — resume with `restart(num_instructions=0, skip_breakpoints=True)` or `reset(halt=False)`.
- ROM disassembly (scratch): `arm-none-eabi-objdump -D -b binary -m arm --disassembler-options=force-thumb dumps/2026-10-29/radar_swd/adt6101p_boot_0x0000.bin` → `tmp/rom_thumb.dis`.
