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
   | `0x40008000` | **SP805 watchdog (WDT)** | Arm PrimeCell SP805 (TRM **ARM DDI 0270B**, in `vendor/arm/`): `+0x00 WdogLoad`, `+0x04 WdogValue`, `+0x08 WdogControl` (bit0 INTEN, bit1 RESEN → live `3` = interrupt+reset enabled), `+0x0C WdogIntClr` (W, any value clears+reloads), `+0x10 WdogRIS`, `+0x14 WdogMIS`, `+0xC00 WdogLock` (unlock `0x1ACCE551`, anything else re-locks, reads return lock status). Live `Load=0x1DCD6500` (500e6), `Value` decrements at ~100e6/s → **~5.0 s timeout**; `RIS/MIS` latch `0→1` at each timeout. Live `+0xFF8/+0xFFC = 0x05/0xB1` = SP805 PCellID2/3 reset values [DDI0270B][HW]. `WDOGINT` is wired to the core **NMI**; `WDOGRES` (second uncleared timeout) is the post-halt AP death — see Debug caveat. App1 lifecycle: arm at boot (`FUN_00010c84`→`FUN_00010ce4(10)`→`FUN_00015164`, Load = 10 × `0x2FAF080`), fed from the main loop by re-writing Load (`FUN_00011368`→`FUN_0000e7d8(10)`; TRM §2.5: a Load write reloads immediately), disabled only in the TF `0x3000`/`0x4000` (OTA) handlers (`FUN_00015138` = unlock → Control=0 → re-lock) — every stock modification is unlock/re-lock bracketed [FW] |
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
- **Debug caveat - the post-halt AP death is the SP805 watchdog timeout sequence, not a lockup and not a core fault** [DDI0270B][FW][HW]: App1 arms the SP805 at boot (Load `0x1DCD6500`, Control `3` = INTEN|RESEN) and feeds it from its main loop by re-writing Load every frame. A **halted** core stops the feeding, so: first counter zero (~5 s after the halt) asserts `WDOGINT`, which this SoC wires to the core **NMI** (`ICSR` `0x00C14000` -> `0x80C02000`: NMIPENDSET + VECTPENDING = 2, exactly at the wrap), and `+0x10 WdogRIS` / `+0x14 WdogMIS` latch `0 -> 1` and stay set. With the interrupt uncleared (App1's NMI handler, vector[2] = `0xa369` -> code `0xa368`, is an empty `bx lr`, and the debugger has no way to clear a pending M3 NMI), the **next** zero asserts **`WDOGRES`** (RESEN is set) and the counter stops - that is the AP failure at t = 9.13 / 9.14 / 9.11 / 9.03 / 8.98 s across five runs (~two ~5 s timeouts after the halt) and J-Link's `Could not start CPU core. (ErrorCode: -1)` on reconnect. **Retracted 2026-10-31 (wrong decoders):** (a) "S_HALT is not trustworthy on this part" - false; per DDI 0337G Table 10-2 the status bits are S_REGRDY=16, **S_HALT=17**, S_SLEEP=18, **S_LOCKUP=19** (plus sticky S_RETIRE_ST=24, S_RESET_ST=25) and DHCSR[31:16] *reads back as status bits [25:16]*, so the recorded `0x00030003` is a textbook *halted, reg-ready, no lockup, C_HALT+C_DEBUGEN*. All 43 stored DHCSR samples in `nmi_source_probe.json` re-decode to **S_HALT=1, S_LOCKUP=0** (t=0.00-8.77 s): halting debug reported correctly throughout. (b) "ICSR bit 27 could not clear the level-asserted NMI" - bit 27 on this part is **PENDSVCLR** (DDI 0337G: 28=PENDSVSET, 27=PENDSVCLR, 26=PENDSTSET, 25=PENDSTCLR) and the M3 ICSR has **no NMI-clear bit at all**, so that experiment cleared nothing. (c) The `+0x10/+0x14` write test proved only that they ignore writes - they are read-only status registers, and writes to everything except `WdogLock` are blocked while the lock is locked (stock re-locks after every modification). **Lever for long halts: unlock `+0xC00 = 0x1ACCE551` and write any value to `+0x0C` (WdogIntClr clears WDOGINT and reloads the counter), or stop the counter with `+0x08 = 0` (stock's own disable recipe)** [HW 2026-10-31, `tools/jlink/probe_wdt.py service`: unlock read back 0, IntClr cleared the latched RIS/MIS and reloaded the counter, `+0x08=0` froze it (delta 0), re-lock read back 1, and the AP stayed halted and alive for the full 30 s across the old 9-10 s death point, S_HALT=1/S_LOCKUP=0 throughout. Counter decrements at 100.0e6/s while halted. The core-side latched NMIPENDSET never cleared and was harmless - the killer was purely the peripheral-side `WDOGRES`]. `reset(halt=True)` at the ROM vector (`PC = 0x0000E0`) remains the unlimited-halt path, because the watchdog block is not yet clocked then (reads `0xFFFFFFFF` all throughout a 20 s window). Measured decrement rate is ~100e6/s while stock's seconds constant is 50e6/tick, so the real timeout is ~5.0 s, not 10. `0x40022000` stays unimplicated: `+0x00` does freeze while halted and writes to `+0x1C` change nothing. Probes: `probe_halt_reset.py`, `probe_nmi_clear.py` (superseded - bit 27 = PENDSVCLR), `probe_nmi_source.py` (wrap-only registers = WdogRIS/MIS), `probe_lockup.py`, `probe_nmi_ack.py` (writes to RO regs, and locked), `probe_reset_halt.py` (the workaround).

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


### App1 radar bring-up, traced live (2026-10-29) [FW][HW]

Captured with `tools/jlink/trace_init.py`: `reset(halt=True)` → software breakpoints → run, logging PC/LR and a peripheral diff at every stop. Log: `dumps/2026-10-29/init_trace.json` (74 stops, t = 0 → 6.49 s). Tooling note: **J-Link reports 8192 available breakpoints and only 4 watchpoints.**

App1's reset handler is at `0x80d0` (vector[1] = `0x80d1`): `bl 0xabfc`, then tail-jump to `0x80bc`. The radar bring-up is reached from **`FUN_00013344`**, which calls `FUN_0000c014` (once-time setup) and **`FUN_0000e9d8`** (the per-frame DSP/DMA sequencer, 8 hits in 6.5 s).

Order of first execution, with the caller that reaches each:

| t (s) | callee | caller | what it writes |
|---|---|---|---|
| 0.64 | `FUN_00015164` | `FUN_00010ce4+0x14` | inside the **SP805 arm routine** (`0x40008000` still reads `0xFFFFFFFF` - domain not yet clocked) |
| **0.75** | **`FUN_0000cd64`** *(diff misattribution)* | `FUN_0000c41c+0x2c` | **watches the watchdog arm land:** `0x40008000 = 0x1DCD6500`, `0x40008008 = 3`; `+0x04` starts decrementing. Erratum 2026-10-31: the writes belong to the unlock-bracketed arm path `FUN_00010c84` -> `FUN_00010ce4(10)` -> `FUN_00015164`, seen between the 0.64 s stop (inside `FUN_00015164`) and the next stop; `FUN_0000cd64`'s body only touches `0x40003xxx` |
| 0.84 | `FUN_00011558` | `FUN_0000c2d8+0x86` | front end `0x40003110/50/60/94/98/b8` |
| 0.93 | `FUN_00012310` | `FUN_0000c2d8+0x98` | timer `0x4000c004/24/28/40/44/48/4c/50` |
| 1.0–1.8 | `FUN_0000cd38`, `0xbe0c`, `0xbea4`, `0xcdb4` | `FUN_00010a98`, `0x10b4c`, `0x10fb0` (+0x60/0x94/0xb8/0x102), `0x1c1ec+0x50` | front-end trim/calibration sweep over `0x400030dc/0e0`, `0x30f4/0f8`, `0x3108–0x3134`, `0x3158–0x3164`, `0x3184–0x319c`, `0x3204–0x3224` |
| 1.41 | `FUN_00013ff8` | `FUN_00013fbc+0x6` | **system control `0x40022000` comes alive** (`+0x24/30/34/50/54/58/5c/64`) |
| 1.9–2.1 | `FUN_0000e43c`, `FUN_0000e598` | `FUN_0000c014+0xda/+0x10a`, then `FUN_0000e9d8` ×3 each | **arms the DSP/DMA descriptors `0x40021000`** |

The two DMA channels, read straight out of the engine at `0x40021000`:

- ch A: `+0x1c = 0x9B320200` → self-clears to `0x1B320200`, `+0x20 = 0x40023000` (ADC port), `+0x24 = 0x20022800` (RAM), `+0x6c = 0x40000`
- ch B: `+0x2c = 0x9B360200` → `0x1B360200`, `+0x30 = 0x40023004` (ADC port), `+0x34 = 0x20025D00` (RAM), `+0x38 = 0x200`, `+0x70 = 0x40000`
- third descriptor: `+0x0c = 0x1B820080`, `+0x10 = 0x20022800`, `+0x14 = 0x20030000`; `+0x00 = 0x7BC0→0x7BDE` tracks the live ramp; `+0x60 = 0xA`, `+0x64 = 0xFFF`, `+0x68 = 0x40004`

**The `0x40023000` xref puzzle is solved:** the ADC port base never appears as a code literal because it is a *data value* written into the descriptor registers, i.e. it comes from a RAM/ROM settings table, not from an `ldr` pool. Bit 31 of a descriptor control word is a **start bit that self-clears** (`0x9B320200 → 0x1B320200`); channels A/B differ only in bit 18.

Per-frame pattern a replacement firmware must reproduce: `FUN_0000e9d8` calls `FUN_0000e43c` at 3 sites (`+0x5a/+0xa2/+0xec`) and `FUN_0000e598` at 3 sites (`+0x76/+0xbe/+0x102`) — ~3 DMA arms per frame, 8 frames in 6.5 s.

**Trace budget:** every breakpoint halts the core and the SP805 keeps ticking in real time, so once App1 arms it (`+0x40008008 = 3`, t ~ 0.75 s) a trace has ~two timeouts (~10 s) of headroom before `WDOGRES`. A 100-stop run died at t = 6.49 s with `CPU could not be halted` / `Failed to clear soft BP in RAM @ 0xABFC`. Keep `--max` ~ 75 or fewer until `trace_init` gains unlock+IntClr servicing (see the debug caveat and `probe_wdt.py`); note a breakpoint at `0xabfc` alone fires reliably but was not hit when 27 breakpoints were armed.



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

- ~~Which block asserts the NMI at each FMCW ramp wrap?~~ **Resolved 2026-10-31:** it is the SP805 watchdog at `0x40008000` (`WDOGINT` → NMI); the lever is on the block: unlock `+0xC00 = 0x1ACCE551` then write `+0x0C` (clears + reloads), or `+0x08 = 0` to stop. Proven by `tools/jlink/probe_wdt.py service` — 30 s halt survived across the old death point. Open remainder: what exactly `WDOGRES` resets (core vs chip), and whether the WDOGINT→NMI input is fixed or programmable.
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
- `tools/jlink/probe_halt_reset.py`: halt and poll on a fixed timebase (the AP dies at the second SP805 timeout). `tools/jlink/probe_nmi_clear.py` is the follow-up (superseded: ICSR bit 27 is PENDSVCLR on this part; the M3 has no NMI-clear bit). The earlier "lockup" reading on this tool was a mis-decoded `DHCSR`; see the debug caveat above.
- `tools/jlink/probe_reset_halt.py`: reset-and-halt at the boot vector; proves the no-time-limit halt state used by everything below.
- `tools/jlink/probe_wdt.py`: the SP805 experiments (`ids` read-only fingerprint incl. PrimeCell ID registers; `service` halt → first timeout → unlock+IntClr → stock disable → survival watch; `disable` halt → disable immediately). Writes only the WDT's own registers, mirroring stock `FUN_00015138`; ends reset-and-run.
- `tools/jlink/trace_init.py`: **reset-and-halt + software breakpoints → the live bring-up order**, with a peripheral diff at every stop. Keep `--limit` under ~8 s of target time. `tools/fnmap.py` resolves an address to its enclosing Ghidra function (`tmp/summarize_trace.py`, `tmp/read_init_trace.py` read the logs).
- `tools/xref.py`: find literal-constant cross-references in a raw image and name the enclosing Ghidra function.
- **pylink only exists on Python 3.14** here (`C:\Program Files\Python314\python.exe`); the 3.12 default has no pylink. pylink 2.0.1 has **no `go()`** — resume with `restart(num_instructions=0, skip_breakpoints=True)` or `reset(halt=False)`.
- ROM disassembly (scratch): `arm-none-eabi-objdump -D -b binary -m arm --disassembler-options=force-thumb dumps/2026-10-29/radar_swd/adt6101p_boot_0x0000.bin` → `tmp/rom_thumb.dis`.
