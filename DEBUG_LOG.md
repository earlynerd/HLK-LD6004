# LD6004 debugging evidence

## 2026-10-20 — Programmer attempt followed by USB enumeration failure

- **Observation:** User reports the programmer's red LED went out, followed by Windows reporting an unrecognized USB device. This followed discussion of DIP 3 continuous-handshake mode with separate 3.3 V radar power; exact as-tested switch and wiring state remains unverified.
- **Host evidence:** A read-only Windows PnP query found a retained `Unknown USB Device (Device Descriptor Request Failed)` entry, hardware ID `USB\DEVICE_DESCRIPTOR_FAILURE`, instance `USB\VID_0000&PID_0002\5&12764A93&0&7`. Windows reported arrival `2026-10-20 00:03:14` and removal `00:03:15`. Association with the user's attempt is plausible from timing, but the failed descriptor provides no device identity. No matching failed USB device was present at inspection.
- **Firmware audit:** No radar or programmer firmware was edited or flashed in this investigation. The workspace is not a Git repository. Earlier LD2450 firmware and pin assignments are not applicable evidence for this target.
- **Root cause:** Unresolved. The retained record establishes an enumeration failure, not a missing vendor driver, chip-family identification, or successful bootloader entry.
- **Next isolation check:** With the radar detached, use the documented V4 programmer self-enumeration mode (only DIP 7 ON, then reconnect programmer power). JieLi documents a USB drive containing instructions/tools. This tests the PC cable and the programmer's own USB function separately from target wiring and bootloader entry; it does not validate the target pass-through path.
- **Fix:** None applied.
- **Class:** usb-enumeration-unresolved
- **Recently-touched?** No device firmware changes; only connection/mode guidance.
- **Sources:** [JieLi V4 tool guide](https://doc.zh-jieli.com/Tools/zh-cn/dev_tools/forced_upgrade/index.html), [LED states](https://doc.zh-jieli.com/Tools/zh-cn/dev_tools/forced_upgrade/led_status.html), [Microsoft enumeration diagnosis](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/case-study--troubleshooting-an-unknown-usb-device-by-using-etw-and-netmon).

## 2026-10-20 — Programmer self-enumeration succeeds and virtual disk scanned

- **Observation:** Following the programmer-only DIP 7 test, the user reports a virtual disk. Host inspection confirms `H:` volume `JLDebug_V0.1` (CDFS) and programmer USB identity `VID_1544&PID_464B`. Mass-storage interface `MI_01` is working. The separate `Jieli Debug` interface `MI_00` has ProblemCode 28 (missing driver); this is distinct from the earlier descriptor failure.
- **Root cause:** Target-mode enumeration failure remains unresolved. Successful programmer self-enumeration establishes a working PC cable and programmer USB device function, but does not prove target-side wiring or the programmer's pass-through path.
- **Scan:** At the user's request, Microsoft Defender scanned `H:\`. Matching start/finish events 1000/1001 confirm completion for scan `{0E73C7FA-0F6F-4484-A699-2774613BE658}`. No detections were reported. Signatures: `1.461.112.0`, updated 2026-10-19 12:35:17 -07:00.
- **Scope:** Seven on-disk files scanned and preserved with SHA-256 hashes under `vendor/jieli/programmer/2026-10-20/`. Scripts reference remote installers which were not downloaded, scanned, or executed. No bundled tool or installer was run. The version file contains only the date `2026/07/21 14:54`, not a hardware-version identifier.
- **Evidence:** `vendor/jieli/programmer/2026-10-20/scan_report.json`.
- **Fix:** None applied; no driver installation or firmware change.
- **Class:** usb-enumeration-isolation
- **Recently-touched?** No device firmware changes.

## 2026-10-20 — Download-mode LED indication but live descriptor failure

- **Observation:** User confirms only DIP 3 ON, radar connected, green LED off and red LED steady. User also confirms a malfunctioning USB device remains present.
- **Host evidence:** At `2026-10-20 00:22:33 -07:00`, Windows reports `USB\VID_0000&PID_0002\5&12764A93&0&7` present with status Error, name `Unknown USB Device (Device Descriptor Request Failed)`, hardware ID `USB\DEVICE_DESCRIPTOR_FAILURE`, and last arrival `00:21:34.536644 -07:00`.
- **Interpretation:** The LED state matches JieLi's documented download-mode indication, but target USB enumeration has not succeeded. No usable target VID/PID or chip-family identity has been recovered. This differs from the programmer's own successfully enumerated debug interface with missing driver.
- **Next check:** Verify the complete target cable/connector path: programmer DM to candidate AC6323A pin 11, DP to pin 12, and common ground. The prior successful programmer-only test did not exercise this section. Connection fault remains a hypothesis, not an established cause.
- **Root cause:** Unresolved.
- **Fix:** None applied.
- **Class:** usb-descriptor-failure-after-handshake-indication
- **Recently-touched?** No firmware changes.

## 2026-10-20 — Both data-wire orientations tried; enumeration trace prepared

- **Observation:** User reports trying both data-wire orientations and using a cut USB cable. These observations do not establish a cable fault.
- **Host evidence:** The failed device has Code 43 and connects through the PC root hub at `ACPI(_SB_)#ACPI(PC00)#ACPI(XHCI)#ACPI(RHUB)#ACPI(HS07)`. No external hub appears in this device's parent path.
- **Next check:** `tools/capture_usb_enumeration.ps1` records a 60-second USBHUB3 trace while the user repeats one failing connection. It enables enumeration/state/error metadata, without transfer-payload keywords, and stops its own trace session. Windows requires an administrator token for this capture; the current session does not have one.
- **Validation:** PowerShell parser validation passed. The capture script has not been executed and no ETL has been collected.
- **Root cause:** Unresolved; no firmware or driver changes.

## 2026-10-29 — JieLi UBOOT enumerated; JL virtual serial driver installed

- **Host evidence:** `USB\VID_4C4A&PID_3442` (bus description `BR34UBOOT1.00`), arrived 2026-10-29 00:27:43 on the same root-hub port (`HS07`) as the earlier descriptor failures. It exposes USB mass storage disk `BD19 UBOOT1.00`. The programmer's own identity (`1544:464B`) is not present.
- **Interpretation:** A JieLi ROM bootloader is in download mode. The SCSI vendor `BD19` matches the AC632N platform, consistent with the AC6323A4 identification. **Unconfirmed:** this could instead be the programmer's own JieLi MCU in its self-upgrade mode (button held during plug-in). Confirm the setup before any write.
- **Virtual serial:** `JLVirtualJtagSerial Device (COM53)` is root-enumerated (`ROOT\PORTS\0000`, UMDF driver 11.9.25.917, installed 00:28:01). It is not tied to hardware until bound to the programmer's `Jieli Debug` interface, which requires DIP 7.
- **Root cause of the earlier descriptor failure:** Unresolved, but enumeration now succeeds.
- **Fix:** None applied. Nothing has been read from or written to the UBOOT device.

## 2026-10-29 — Radar JieLi chip identified via UBOOT (read-only)

- **Setup:** Programmer DIP 1 ON (others off), radar on separate 3.3 V supply; the radar power-cycle triggers UBOOT entry. So the UBOOT device is the radar's chip, not the programmer's.
- **Result (kagaimiq/jl-uboot-tool @ adb3f18, run by the user):** `BD19 UBOOT1.00`, AC632N series. RAM loader `bd19loader.bin` installed with argument 0x0001 (SPI NOR, 3-wire). Chip key **0xA80F**. Online device: SPI NOR on SPI0, ID **0xCD7113**. Density byte 0x13 means 512 KiB, consistent with AC6323A4 (4 Mbit internal flash).
- **Writes:** None to flash. Loader went to RAM only.
- **Note:** DIP 1+7 together did not expose the programmer's own USB device; COM53 binding needs DIP 7 without DIP 1.

## 2026-10-29 — Stock JieLi flash backed up

- **Result:** The user ran two full 512 KiB reads via jl-uboot-tool. They are byte-identical, SHA-256 `83e2dfd0…4484ed9`. Stored in `dumps/2026-10-29/` with a README.
- **Contents:** About 188 KiB used; data ends at 0x7D009. Header names AC632N; the bulk is encrypted, as expected for a chip-key-encrypted JieLi image.
- **Writes:** None.

## 2026-10-29 — JieLi image decrypted and identified

- **Tool:** `tools/jl_fw_unpack.py`, an independent reimplementation of the kagaimiq new-fw format. Running the downloaded unpacker was blocked by the auto-mode classifier.
- **Result:** Decryption is verified. app.bin, cfg_tool.bin and p11_code.bin all pass their CRC-16 checks, and the chip key in isd_config.ini (0xA80F) matches the chip.
- **Identity:** The JieLi firmware is HLK's BLE↔UART bridge (`hlk-b25`, JieLi SDK `spp_and_le/at_char_com`), not radar processing. Radar processing lives on the ADT6101P side; the ZB25VQ80 is likely that chip's flash. Possible debug log on PA05 at 1 Mbaud (isd_config UTTX); unverified for the app.
- **Details:** `dumps/2026-10-29/README.txt`.

## 2026-10-29 — Radar OTA path traced; radar SoC firmware format identified

- **JieLi disassembly:** Used `tools/bin2elf.py` with the JieLi 2.5.2 `llvm-objdump` (q32s) from the HLK-LD2450 cache. Output is in `dumps/2026-10-29/disasm/`. JieLi FW string: `HLK-LD6004(b.1.04.120250905150452)`.
  - The BLE→UART handler at 0x1E03D9A parses TF frames with LEN=1. TYPE 0x0F0F (set BT serial baud) is handled locally: index 0..5 maps to 9600/115200/128300/256000/460800/921600, saved to VM. TYPE 0x000D with nonzero data arms a 500 ms timer (purpose TBD).
  - The UART→BLE handler at 0x1E05F04 treats a single 'C' (0x43) byte from the radar as "6004 in OTA mode". That is the YMODEM/XMODEM-CRC receiver start character. It also inspects 0x0A0A presence frames, then forwards to BLE.
  - **Inference:** Radar OTA is TF 0x3000, then the radar bootloader answers 'C', then YMODEM over the transparent JieLi bridge. The JieLi only relays.
- **Radar SoC:** The LD6002B firmware from Hi-Link's public Drive is plaintext ARM Cortex-M, has an ADT6101P banner, and is TinyFrame-based. The updater is "ANDAR OTA.exe". See `vendor/hilink/ld6002b_drive_2026-10-29/README.txt`.
- **Writes:** None to hardware.

## 2026-10-29 — ADT6101P read over SWD (J-Link)

- **Result:** Cortex-M3 r2p1 with no read protection. A 128 KiB RAM code window at 0x0 holds Bootloader V6.3.0 at 0x0 and the "human detection 3d" app at 0x8000. Both are stable across reads and saved in `dumps/2026-10-29/radar_swd/` with a README.
- **Inference:** The code is loaded into RAM from the external ZB25VQ80 at boot. The bootloader accepts YMODEM ("HyperTerminal") uploads. The app is about 90% similar to the published LD6002B v3.9.0.
- **Not yet captured:** The raw external flash (config/calibration beyond the RAM image). That needs the ADT6101P SPI-flash controller registers, which can be recovered from the bootloader.
- **Writes:** None.

## 2026-10-29 — ZB25VQ80 identified and dumped through the ADT6101P (SWD)

- **Method:** A RAM stub drives the ADT6101P's flash SPI (`0x4000E000`, CS on GPIO4); this mirrors the stock driver. `tools/jlink/adt_spi_flash_read.py` uses a read-only opcode allow-list.
- **Halt constraint:** About 5 s after a debug halt, the target resets and drops off SWD. It is not the `0x40022000` block: its `+0x00` freezes while halted, and writing `+0x1C=1` did not prevent the reset. Cause is unidentified. The workaround is halt sessions of ≤1.5 s, each ending in reset-and-run.
- **Chip:** JEDEC `5E 60 14` (Zbit, 1 MiB), SFDP v1.7, 128-bit UID. Status registers are all 0, so there is **no write protection**. Security registers are blank.
- **Dump:** Two full reads are identical, sha256 `e9a61b63…1719b104`. Saved in `dumps/2026-10-29/radar_spi_flash/` with a README.
- **Layout:** Boot chain is ROM Bootloader V6.3.0 → jump code @0x0 → Boot Area v2.0.7 @0x8000 → App1 @0x18000 or App2 @0x38000 (both CRC32-checked). App1 is byte-identical to the RAM app. App2 is a factory test/calibration image. Boot flags are @0x10000; a 0xDEADBEFF config log is @0x14000.
- **Writes:** None to flash. Target RAM 0x20002000–0x200041FF was overwritten, and the target was reset after every session.

## 2026-10-29 — JieLi ↔ radar serial link identified (firmware analysis)

- **Radar side (ADT6101P App1):** The generic UART init at app `0x14D58` takes (base, baud, clksel). Pin mux is at `0x40020030 + 4*pin`, value 1 then 0x81, and the divisor is 50 or 100 MHz / baud at `+0x10`.
  - UART0 `0x40004000` uses pins P00/P01.
  - UART1 `0x40005000` uses pins P10/P11. The ROM bootloader uses it for its 115200 console.
  - UART2 `0x40006000` uses pins P20/P21. P20 is the module "OUT" pin.
  - The app initialises **only UART0, hard-coded at 115200** (call sites `0x11DBA`, `0x11DE6`, `0x11E10`, `0x130D4`). It carries TinyFrame (TF tx at `0xB258`). The datasheet maps header TX0/RX0 to P00/P01, so the radar's one active UART is the public header UART.
- **JieLi side (AC6323A4 app.bin):** Two UARTs are opened with `uart_platform_data` (baud is a bitfield stored <<1).
  - `HLK_UART` (`0x1E033F2`): TX IO 22 / RX IO 23 (PB06/PB07 in JieLi numbering), 512 B buffer, 6 ms RX timeout, **115200** (raw 230400 = 115200<<1). Its RX callback `0x1E05FAE` sits next to the UART→BLE handler `0x1E05F04`, which detects the radar's YMODEM 'C' and 0x0A0A presence frames. This is the radar link.
  - `AT_CHAR_COM` (`0x1E038CA`): TX IO 1 / RX IO 2 (PA01/PA02), baud taken from `gov_fdt.baud` (VM item 51). That is the value TF 0x0F0F sets; the default index is 1 (115200). This is the SDK's AT/transparent port; its board connection is unknown.
- **Conclusion:** The inter-chip link is plain async UART at 115200 (8-bit, `is_9bit=0`) carrying the same TinyFrame protocol as the public header. The radar has no second data link. This supports "radar SoC does processing, JieLi only bridges BLE", so the JieLi has no richer-data interception point.
- **Unverified:** Physical wiring. Whether JieLi PB06/PB07 tap the radar UART0 / header TX0-RX0 nets (shared bus) has not been continuity-tested, nor has the live UART register state been read.
- **Writes:** None.

## 2026-10-29 — App1/App2/Boot Area decompiled with Ghidra; radar peripheral blocks found

- **Tooling:** Ghidra 11.1.2 (`C:\Users\mmsyl\Documents\ghidra`) headless. This build's `AnalyzeHeadless` has no `-base-address`/`-language` options; raw-binary import is impossible. Workaround: wrap images with `tools/bin2elf.py --machine 40 --flags 0x05000102` (ELF32, EM_ARM, EF_ARM_V7M) at load address `0x8000`, import with `-processor "ARM:LE:32:Cortex"`. Scripts: `analysis/adt6101p/ghidra_scripts/SeedVectors.java` (vector-table seeding), `DumpDecompiled.java` (pseudo-C dump). Project: `analysis/adt6101p/ghidra/ld6004`.
- **Output:** `analysis/adt6101p/elf/app1_decompiled.c` (389 functions), `app2_decompiled.c` (323), `bootarea_decompiled.c` (89), 0 decompile failures. Helper: `tools/func_periph_map.py` (resolves literal-pool `DAT_` indirection to peripheral addresses).
- **Peripheral map expanded** [FW constants + HW live reads]: new blocks beyond the known ones — `0x40001000`, `0x40002000`, **`0x40003000`** (heavily used; dozens of small register setters at offsets `0x108–0x278`, `0x3800–0x3968`; live reads return non-zero config values → radar front-end/ADC/DSP block), **`0x40008000`** (live: `+0=0x1DCD6500`=500 000 000, `+4=0x1D931903`≈496 200 963 → RF synthesizer frequencies; accessors write `+0`, then `+C=1`, `+C=3` handshake), `0x4000C000` (timer/DSP trigger, live values), `0x4000D000` (`+0=0x484D2312`, ID-like), `0x4000F000` (byte writes at `0xF020–0xF025`, `0xF030`, `0xF04F`, `0xF080`, `0xF1C0`; reads all-zero while idle → RF/PLL config, possibly power-gated), `0x40010000` (config regs, live), `0x40021000` (holds RAM pointers `0x20030000`/`0x2002FB80` → DMA descriptors?), `0x40023000` (`0xF6DD1B7F`, `0x074E06C9`×7 → ID/calibration constants?).
- **Live probe:** `tools/jlink/probe_regs.jlink` (read-only, no halt, sub-second), log `dumps/2026-10-29/periph_probe_2026-10-29.log`. `0x40003000+0x100` onward returns live values (e.g. `+0x110=E051`, `+0x150=8F8`, `+0x160=1FA3`, `+0x210=1F83E0`, `+0x218/0x21C=5A5`, `+0x220=02940008`×2, `+0x3940/0x3948=F83E0` duplicated pair).
- **Front-end driver shape** [FW]: channel-enable fan-out `FUN_00010fb0`/`FUN_000110c0` take per-channel flags and call ~14 setters in the `0x40003000` block; `FUN_0000be0c` is a 12-parameter bitfield writer for `+0x12C`/`+0x130` (4-bit fields at bits 16–31); values scaled `param<<3`; channel-count×15 appears as a common multiplier. Config profile read from a RAM descriptor (`DAT_00010fac`).
- **Export surface** [FW]: TF transmitter `FUN_0000b258(type, buf, len)` is called with types `0x0A04, 0x0A08, 0x0A0B…0x0A18` (payloads 1–96 bytes) — far more message types than the public protocol documents. Candidate hooks for richer data.
- **Writes:** None to hardware. New files: `analysis/adt6101p/elf/`, `analysis/adt6101p/ghidra/`, `analysis/adt6101p/ghidra_scripts/`, `tools/func_periph_map.py`, `tools/jlink/probe_regs.jlink`, probe log.

## 2026-10-29 — Image format settled; calibration storage and TF payload map

- **Image header solved** [FW+HW]: the 16-byte header's "mystery 7 bytes" = **u32 CRC32 stored big-endian at `+9`** (zlib CRC-32 over `len` bytes from image offset `0x10`). Verified on all four stock images (jump `C2FA860E`, boot area `56848E93`). **CRC field = 0 → Boot Area skips the check** ("NO CRC check of the bin file!"); stock App1/App2 are 0. Boot Area validator `FUN_00008a42`: flag must be `0x5A`, the two length fields must match and be non-zero. CRC routine `FUN_000099f4` = table-driven reflected CRC-32.
- **Calibration storage** [FW+HW]: App2 phase calibration (`FUN_0000c9c0`) scans a 4-channel × 32-bin matrix, averages 4 phase differences, and on success `FUN_00010afc` stores `[flag][cksum][4 float][cksum][3 u32]` (cksum `~(XOR+1)`, `FUN_0000c70c`) to flash **`0x48000`** via SPI read/write helpers (`FUN_00008fa0` = cmd 0x03 + 24-bit addr). **Slot is blank (0xFF) on our unit** → phase-comp values are zero; App1's `0x0A16` buffer (`0x20000E38`) reads all-zero, consistent.
- **TF payload map** [FW+HW]: App1's `0x0A0B…0x0A18` frames carry config/state, not raw samples: area bounds float32s (`-6,6,-6,6,0.5,6…`) at `0x20000DD8`/`0x20000D78`, thresholds `200,3` at `0x2000003C`, flags at `0x20000088/89`, `0x200000A1`. App2's `0x0A10` (20 B) = per-TX/RX channel + distance/speed/power floats — the factory measurement frame. Live dump: `tools/jlink/probe_tfbufs.jlink`, log `dumps/2026-10-29/tfbufs_probe_2026-10-29.log`.
- **Config log** [HW]: `0xDEADBEFF` entries at `0x14000/0x14068/0x140E4` contain the same area-bound floats.
- **Not yet done:** FFT/angle code path in App1 (App2 references format strings indirectly via RAM pointers, e.g. `DAT_0000cc6c`, so string-trace misses them); sample-buffer DMA chain (`0x40021000` descriptors).
- **Writes:** None to hardware. New: `tools/trace.py`, `tools/jlink/probe_tfbufs.jlink`.

## 2026-10-29 — Radar processing chain reconstructed from decompilation

- **App2 (factory) frame pipeline** `FUN_0000fc9c` [FW]: per chirp, `FUN_0000ece0(src,dst,4,4,0x100)` over 256 samples (raw buffer stride `0x400` = 1 KiB/chirp) → range processing; `FUN_0000d7f4(0x100,0x20,buf,buf,4,4)` ×4 → 32 bins for 4 phase-center buffers; `FUN_000119d4(0x20,0x3c,…,0x400,4)` reshape → 32×60 maps; `FUN_0000a688(0x20,0x3c,…)` ×4 map transforms; element-wise sum of the 4 channel maps (`0x780` = 32×60 words); `FUN_0000d6c0(0x20,0x3c,map)` peak/CFAR detect. A 64-bin variant exists (`FUN_0000fc0c`, `0x40` bins). `FUN_0000fec4` = 3×3 neighbourhood peak interpolation.
- **App2 result map** lives at RAM `0x20010000` (row stride `0x80`, rows 3..59 scanned for peaks, 32 bins/row). Phase extraction `FUN_0000f384(bin,bin2,&4 floats)`, angle from phases `FUN_0000b410`. Averaging constants: floats 10.0 and 9.0 (average over 9 frames).
- **App1 (production) pipeline** `FUN_00010ebc` [FW]: `FUN_0000e818(0x100,0x10,…,4,4)` (256 samples, 16 chirps?), `FUN_00013ed8(buf,0x100,0x6a,0x10,4)`, reshape `FUN_00015074(0x20,0x6a,…,0x400,4)`, transform `FUN_0000bcb4(0x20,0x6a,…)`, detect `FUN_0000e5f8(0x20,0x6a,map)` → **32 range × 106 Doppler** map. Target array stride `0x14` (20 B/target). Presence rule (`FUN_00010e64`): count of valid targets ≥ 6 → presence; else emit zeroed TF `0x0A0A` (16 B payload) and re-arm via `FUN_0000d4bc(200,0)`.
- **Shape summary:** 256 ADC samples/chirp; App2 profile 32 chirps/frame, 32×60 map, 4 channels; App1 profile 32×106 map. Exact FFT sizes inside `FUN_0000ece0/d7f4` not yet verified [?].
- **Writes:** None to hardware.

## 2026-10-29 — Peripheral enumeration + IRQ map

- **Static scan of all images** (`tools/../tmp/periph_enum.py`): peripheral-page constants across ROM/Boot Area/App1/App2. New blocks beyond the known set: `0x40000000` (Boot Area writes 9/0 to `+0`; IRQ3 acks `+0xC=1`), `0x40007000` (`+0x108`), `0x4001E000`/`0x4001F000` (Boot Area only, `0x1EA40`), `0x4002E000` (`0x2EA40`, all apps).
- **Live probe** (`tools/jlink/probe_periphs.jlink`, log `dumps/2026-10-29/periph_enum_2026-10-29.log`): NVIC ISER0 = `0x24B9` → enabled IRQs **0,3,4,5,7,10,13** (none ≥32). SysTick unused (LOAD/CTRL=0) — frame timing is hardware timers. No faults active.
- **Vendor block-ID registers**: many blocks return `+0xFF8=5, +0xFFC=0xB1` (a shared IP family: `0x40000,1,2,4,5,6,8,D,E,F,0x40012`); radar (`0x40003`), I²C (`0x40009`), timer (`0x4000C`), GPIO/DSP/sysctl (`0x40020-2`) return 0 (custom IP). `0x40023000` returns live sample data even at `+0xFD8` — confirms it is a sample stream. Blocks `0x4000A000/0x4000B000` respond to reads but are referenced by **no** firmware image — hidden IP [?].
- **IRQ handlers** (from flat disassembly; vectors point mid-function in Ghidra's merged listing): **IRQ0 = UART0 RX** (`+0xC=2` ack, bit1 of `+4` = RX ready, byte from `+0x00` into a 127-byte ring buffer, parser kick). **IRQ3** acks `0x4000000C=1`. **IRQ4** acks `0x4001000C=1` then reads a value via `0x14a10`/`0x8bca`. Every block's ack register is at `+0xC` (write bit to clear). IRQ5/13 sit in the `0xE5F8/0xE7D8` cluster (DSP/timer completion path, pending deeper work).
- **Ghidra caveat confirmed again**: this build lacks `splitFunction` and part of `FunctionManager` API; vector-seeded ISRs must be read from the flat `app1.dis`.
- **Writes:** None to hardware.

- **The FFTs are hardware** [FW+HW]: `FUN_0000ece0`/`FUN_0000d7f4` are job wrappers around the DMA/DSP engine at **`0x40021000`** (second instance `0x40021200`): per channel `src@+0x10+16n`, `dst@+0x14+16n`, `ctrl@+0x18+16n`; sizes at `+0x60…` as `in|out<<16`; status `+0x58` polled until done; ctrl words OR in a `0x1B…` mode field. Live engine state captured: `tools/jlink/probe_dsp.jlink` → `dumps/2026-10-29/dsp_probe_2026-10-29.log` (channels point at `0x40023000` = **ADC sample port**, sample buffers `0x20008000/0x2000C000/0x20010000/0x20014000/0x20018000/0x2001C000/0x20020000/0x20022800/0x20025D00/0x20026100/0x20028000/0x2002C000/0x20030000`).
- **UART polled interface** [FW: Boot Area `FUN_00009278`]: write byte to `UART+0x00`, poll `UART+0x04` bit0 clear; init = pinmux P00=1/P01=0x81, `+0x10` divisor, `+0x08=0xb`.
- **RF synth live drift** [HW]: `0x40008000+4` changed between reads (`1D931903`→`1D880337`, ≈495.5–496.2 MHz) → active sweep register.
- **New: `firmware/` scaffold.** `hello_radar.c` + `hello_radar.ld` (link at `0x8000`, vectors, polled UART0, read-only live snapshot of front-end/synth/timer/DSP/ADC/map), `tools/mk_image.py` (prepends the verified 16-byte header, CRC=0 → Boot Area skips check). Built with arm-none-eabi-gcc: `hello_radar_img.bin` 631 B; objdump confirms vectors (SP `0x20007C00`, reset `0x80D9` Thumb) and the poll-`+0x04`-write-`+0x00` TX loop. **Not flashed.** Load paths when we choose to test: ROM bootloader "Load bin file to RAM" (YMODEM, RAM-only, safest) or TF `0x3000` → YMODEM → App slot.
- **Writes:** None to hardware.

## 2026-10-29 — ROM bootloader V6.3.0 traced: boot-pin table, RAM-load contract, launch trampoline

- **Method:** Static analysis of the ROM image already dumped at `0x0` (`dumps/2026-10-29/radar_swd/adt6101p_boot_0x0000.bin`, 32 KiB). `arm-none-eabi-objdump -D -b binary -m arm --disassembler-options=force-thumb` → `tmp/rom_thumb.dis`; constant scan `tmp/rom_consts.py`. No Ghidra, no hardware.
- **Boot pins** [FW]: ROM init `0x104` sets mux `0x40020060`/`0x4002007C` = `0xB0`, then reads **`0x4002002C & 0x81000`** and dispatches at `0xe20`: `0x000000` → Load bin file to RAM, `0x001000` → Jump to flash, `0x080000` → Jump to EEPROM, `0x081000` → "This is debug mode". So **BOOT1 = P19 (bit 19), BOOT0 = P12 (bit 12)**; RAM-load needs **both low**, not just BOOT1. Datasheet documents only the `0/1` row. Pin↔silicon identity inferred from bit positions + the ROM's own mux writes, not continuity-tested [?].
- **Console** [FW]: ROM getc `0x170` / putc `0x54a` / init `0x580` use **UART1 `0x40005000`, P10 (mux 1) / P11 (mux 0x81), 115200**. ROM also carries UART0 (`0x40004000`, init `0x55e`) and UART2 (`0x40006000`, init `0x5a2`) bring-ups that no ROM I/O path calls. Before the loader the ROM writes `0xFFFFFFFF` to `0xE000E180` (**NVIC ICER0**) — it runs with all IRQs disabled.
- **RAM-load protocol** [FW]: YMODEM/CRC-16-CCITT — `'C'` start, **133-byte packets** (type, blk, ~blk, 128 data, CRC-16 big-endian), ACK `0x06`, NAK `0x15`, filename block type 1, EOT type 4; staging at `0x20019000` / `0x20020000`.
- **Load address and launch** [FW]: packet data (offsets 3…130) is copied **verbatim** to `0x8000` (`0x798`–`0x7c2`); **no 16-byte image header is expected or stripped on this path**, so the file's byte 0 must be the vector table. After EOT: pin-mux restore, `dsb`/`isb` (`0x63c`), then trampoline **`0xd4`**: `SP=[0x8000]`, `PC=[0x8004]`, `bx`. Nothing is written to flash. The 16-byte header belongs to the **"Jump to flash"** path (`0xcb6`: header at flash `0x0`, flag `0x5A`, code offset `0x10`, SPI divider byte written to `0x4000E000+0x10`, then flash `0x10..` → `0x8000`) and to Boot Area OTA.
- **Consequence for the plan:** the module header exposes only P00/P01 (UART0), P20 (OUT), SWD, power and the two boot pins. The ROM's YMODEM port is **P10/P11, which is not on the header**, so "BOOT1 low → YMODEM over UART1" additionally needs BOOT0 low **and** a physical tap on P10/P11. A SWD RAM load (write `0x8000`, disable NVIC, set SP/PC or branch to ROM `0xd4`) reaches the same end state using pins we already have.
- **hello_radar v0 review** [FW]: three defects found by inspection, none tested on hardware — (1) the stock app leaves `ISER0 = 0x24B9` and its vector table at `0x8000`, which our image overwrites, so any UART0 RX IRQ lands in `default_handler` forever; (2) `.bss` at `0x20000000`–`0x20000600` overlaps the live app's `.data`/`.bss` (app SP `0x20006030`); (3) the `0x20010000` "map" dump is **App2's** map address, not App1's.
- **Writes:** None to hardware. New: `tmp/rom_thumb.dis`, `tmp/rom_consts.py`. Docs updated: `ARCHITECTURE.md` (ROM bootloader paths subsection, `0x40020000+0x2C`, UART interface paragraph, access points, open questions).

## 2026-10-29 — RESOLVED: the "post-halt reset" is an NMI-re-entry core lockup, not a reset

- **Method:** new `tools/jlink/probe_halt_reset.py` — connect, sample without halting, halt, then poll a fixed detector set every 0.25 s for 12 s, then a reconnect phase. Run three times (twice with a mis-wired boot pin still attached, once after removing it). Follow-up `tools/jlink/probe_nmi_clear.py`. Logs: `dumps/2026-10-29/halt_reset_probe{,_wired}.json`, `nmi_clear_probe.json`.
- **The target never reset.** Across the failure everything stays continuous: frame counter `0x4000C020` (`0xC083` at halt → `0xC082` after, not reloaded), `0x40022000+0x00`, the app vector table at `0x8000` (`20006030 / 000080D1`), and the ADC stream at `0x20008000`. The boot chain never re-runs. The old note "the target resets and drops off SWD" was wrong.
- **Timing is two FMCW ramp wraps, not 5 s.** `0x40008004` counts down from `0x1DCD6500` (500,000,000) at ~100e6/s → a **5.0 s ramp**. AP read failures at **t = 9.13 / 9.14 / 9.11 s** in the three runs — i.e. the second wrap. The earlier "~5 s" impression was the *first* wrap (t≈4.06 s), which is when `ICSR` flips `0x00C14000` → **`0x80C02000`** (bit 31 set, VECTPENDING = 2 = **NMI**).
- **Mechanism** [HW][FW]: the radar asserts an **NMI at every ramp wrap**. App1's NMI handler (vector[2] = `0xa369`, code at `0xa368`) is an empty `bx lr`, so a running core takes and discards it; a halted core cannot, so it latches pending. The next wrap delivers a second NMI into an already-pending NMI → **Cortex-M3 lockup**. J-Link's reconnect prints `Could not start CPU core. (ErrorCode: -1)`, the lockup signature. Nearby at `0xa350`–`0xa35c` is the app's VTOR writer (literal `0xE000ED08` at `0xa364`, ending `cpsie i`).
- **Negative result — clearing the NMI does not work** [HW]: `probe_nmi_clear.py` wrote `ICSR` bit 27 (NMICLR) on all 20 polls from the first wrap onward; `ICSR` read `0x80C02000` every single time and the AP still died at t=9.11 s. The source is **level-asserted**, so the pending bit re-latches instantly. Any fix has to mask/ack the source (`0x4000C000` timer or the DSP engine are the candidates), not the core.
- **Not a watchdog, and not the mis-wire.** The user had connected a boot pin to what they thought was reset (the pin on the SWD end = pin 8 = BOOT1 = P19). Removing it changed nothing: identical t=9.13 vs 9.14 s. `0x40022000` stays unimplicated (`+0x00` does freeze while halted).
- **Also corrected:** my interim claim that `0x4002002C = 0` meant both boot pins were being held low was wrong — read-only pinmux scan (`tmp/pinmux_read.py`) shows App1 leaves **P12/P19 at mux `0`**, so that register is not sampling those pads. Same scan: **P10/P11 sit at mux `0x10`** (the idle value the ROM itself restores at `0x7d2`/`0xd3c`), so UART1 exists on those pads only during the ROM loader phase, never while the app runs.
- **Practical rule for SWD work:** budget halt time against the **ramp**, not a fixed timeout. Read `0x40008004` immediately after halting, compute time-to-wrap, and finish before it. The old ≤1.5 s budget was over-cautious; the real ceiling is the next wrap (0–5 s away), and the hard failure is at the one after.
- **Writes:** `ICSR` (bit 27 NMICLR) only, in `probe_nmi_clear.py`, plus debugger resets. No flash, no radar register writes. Every session ended with reset-and-run; the module was power-cycled once by hand mid-investigation and confirmed running afterwards.

## 2026-10-29 — lockup hypothesis measured and NOT supported; NMI source narrowed to the synth block

- **Method:** two more probes. `tools/jlink/probe_lockup.py` (halt, wait for the AP to die, reconnect, read DHCSR/DFSR/HFSR/ICSR before any reset) and `tools/jlink/probe_nmi_source.py` (halt, then sample DHCSR/ICSR/HFSR/DFSR plus `0x4000C000`, `0x40008000`, `0x40021000`, `0x40010000/11000/12000`, `0x40000000`, `0x40022000`, `0x40020000` every 0.2 s and diff each word against wrap timestamps). Logs: `lockup_probe.json`, `nmi_source_probe.json`.
- **My first read of this was wrong and is retracted:** I decoded DHCSR status as bits 16/17/19. Those are the **C_\* control bits**; the status bits are 1–4 (`S_REGRDY/S_SLEEP/S_HALT/S_LOCKUP`). Both scripts are fixed. Always re-check bit positions before writing a conclusion.
- **Not a lockup** [HW]: live, at the last sample before the AP dies (t=8.77 s), `DHCSR = 0x00030003` → `DBGACT, S_REGRDY, C_DEBUGEN, C_INTSTATUS`; **`S_LOCKUP = 0`**, `S_SLEEP = 0`. `HFSR = 0` (no fault). `DFSR = 1` (DWTOPCN) looks like debugger residue. The post-reconnect read is useless anyway — reconnect resets the core, which is why the pending NMI had already cleared to `ICSR = 0x00400000`.
- **`S_HALT` is not trustworthy on this part** [HW]: `DHCSR` reports `S_HALT = 0` in *every* sample even though the core is demonstrably halted (`0x40022000+0x00` and the `0x20008000` sample buffer are frozen). Don't use it as a halt indicator; use a known app-written RAM word instead.
- **NMI source narrowed** [HW]: scanning for words that change **only** at a ramp wrap returns exactly two — **`0x40008010` and `0x40008014`**, both latching `0 → 1` at the wrap and staying set. Everything else that moves (`0x4000C020`, `0x40000004`, `0x40008004`) moves between wraps too. So the FMCW wrap event is recorded inside the RF synthesizer block, which is now the prime candidate for the NMI source and its ack.
- **Also seen:** `0x40011000` and `0x40012000` blocks read all zero while App1 runs; `0x40010000` holds data. In the DSP block, `0x40021050 = 0x20004000` and `0x40021054 = 0x40010000` (a RAM→peripheral pair) — worth revisiting for the DMA-descriptor item.
- **Failure timing, five runs:** AP dies at 9.13 / 9.14 / 9.11 / 9.03 / 8.98 s after the halt — always immediately before a wrap.
- **Writes:** `ICSR` only, plus debugger resets. No radar register writes yet — masking `0x40008010/0x40008014` is the next experiment and needs sign-off. Board left running (confirmed via `tmp/reset_run.py`).
- **Docs:** `ARCHITECTURE.md` Debug caveat rewritten to the measured result, `0x40008000` row extended, `CLAUDE.md` gained a "Working environment" section (PowerShell has no heredocs; pylink only on Python 3.14; pylink 2.0.1 has no `go()`).

## 2026-10-29 — Source-ack attempt fails; found the real workaround: halt before the radar starts

- **Method:** `tools/jlink/probe_nmi_ack.py` with `--mode clear|set|set+nmi` (halt, then write `0x40008010`/`0x40008014` on every poll, optionally with `ICSR` NMICLR), then `tools/jlink/probe_reset_halt.py` (reset-and-halt at the boot vector, poll 20 s). Logs: `nmi_ack_{clear,set,set+nmi}.json`, `reset_halt_probe.json`.
- **`0x40008010`/`0x40008014` are read-only status** [HW]: writing `0` reads back `1/1`; writing `1` also reads back `1/1`. AP died at t = 9.09 s (clear) and 9.12 s (set). Masking the NMI at its suspected source does not work.
- **A trap worth recording:** the `set+nmi` run reported `survived 22 s = True`, which looks like success — but `ack_writes: 0`, `ICSR = 0` throughout, no wraps, and the **whole `0x40008000` block read `0xFFFFFFFF` from t=0.0**. It never wrote anything; the radar domain was simply not running because the previous run's reset had left us halting before the app started the sweep. Read the mechanism, not just the boolean.
- **The workaround, measured twice** [HW]: `reset(halt=True)` stops the core at the **ROM reset vector `PC = 0x0000E0`** and the AP stays alive for the full 20 s poll window — `ICSR = 0`, no NMI, every watched register static, and **no watchdog of any kind fires**. `restart()` then ran the boot chain normally (re-halted at `PC = 0x010730`). So the ceiling on halt time is not a timer: it is *whether the FMCW sweep engine ever got started*.
- **In the halted-at-reset state the entire `0x40008000` block reads `0xFFFFFFFF`** [HW] — the classic dead/clock-gated slave signature. The radar domain is powered or clocked only once the boot chain gets to it. Useful as a "has the app initialised the front end yet" indicator.
- **Consequences for the open items:** (1) init-sequence tracing (front-end order, the `0x40021000` descriptor chain) can now be done by reset-and-halt plus step / run-to-breakpoint with **no time limit**; (2) live-register work on a running app still has to finish before the next wrap — compute it from `0x40008004` after halting (≤5.0 s), not from the old 1.5 s guess; (3) the "unidentified watchdog" theory is now fully dead — nothing bad happened across 20 s halted at reset.
- **Writes:** `0x40008010`, `0x40008014` (values 0 and 1, both ignored by the hardware) and `ICSR`, plus debugger resets. No flash touched. Board left running.

## 2026-10-29 — App1 bring-up traced live: init order, synth start, DMA descriptors, and the `0x40023000` literal puzzle

- **Method:** new `tools/jlink/trace_init.py` — `reset(halt=True)` → software breakpoints → run; at each stop log PC/LR, snapshot `0x40003000/0x40008000/0x4000C000/0x40021000/0x40022000`, print only the changed words, then step over and resume. Support: `tools/fnmap.py` (address → enclosing Ghidra function), `tmp/summarize_trace.py`, `tmp/read_init_trace.py`. Log: `dumps/2026-10-29/init_trace.json` (74 stops, 0 → 6.49 s).
- **The predicted workflow works.** Reset-and-halt at `PC = 0xE0`, then run, reaches App1's init **0.64 s** later. Confirmed the reset handler at `0x80d0` is `bl 0xabfc` / `bx 0x80bc` — first stop was `PC = 0xabfc`, `LR = 0x0080d4`, exactly that call's return address.
- **Init order measured:** synth probe `FUN_00015164` (t=0.64) → **`FUN_0000cd64` writes `0x40008000 = 0x1DCD6500` and `0x40008008 = 3`, starting the ramp (t=0.75)** → front end `FUN_00011558` (0.84) → timer `FUN_00012310` (0.93) → a ~1 s front-end trim sweep through `FUN_0000cd38/0be0c/0bea4/0xcdb4` driven by `FUN_00010fb0` → system control alive via `FUN_00013ff8` (1.41) → DMA/DSP armed by `FUN_0000e43c`/`FUN_0000e598` (1.9+). Root: `FUN_00013344` → `FUN_0000c014` (once) and `FUN_0000e9d8` (per-frame, 8 in 6.5 s, ~3 DMA arms each).
- **`0x40023000` xref puzzle RESOLVED:** it has **zero code-literal references** because the ADC port base is a *data value* written into the DMA descriptors — `0x40021020 = 0x40023000` → RAM `0x20022800`, `0x40021030 = 0x40023004` → RAM `0x20025D00`. Control words `0x9B320200`/`0x9B360200` **self-clear bit 31** to `0x1B320200`/`0x1B360200` after starting; the two channels differ only in bit 18.
- **New facts:** J-Link reports **8192 breakpoints / 4 watchpoints** available here. `0x40008000` = ramp length and `0x40008004` = the live countdown (previously inferred); `0x40008008 = 3` is the start bit. `0x400030dc`/`0x400030f4` change on *every* stop even across unrelated calls — live readback (AGC/return), not configuration.
- **Trap hit, worth remembering:** breakpoints halt the core, so the wrap-NMI limit still applies. Raising `--max` from 30 to 100 died at t = 6.49 s with `CPU could not be halted` / `Failed to clear soft BP in RAM @ 0xABFC` / `Could not start CPU core (-1)`. The AP recovered by itself and `tmp/reset_run.py` confirmed the board running again. **Also self-inflicted: the rerun overwrote the previous good log** — output is now timestamped (`init_trace_<UTC>.json`) and the default `--limit` is 8 s.
- **Anomaly not yet explained:** a lone breakpoint at `0xabfc` fires reliably, but with all 27 breakpoints armed the first stop was `0x15164` and `0xabfc` was never hit.
- **Writes:** debugger breakpoints + resets only. No flash, no radar-register writes. Board left running.

## 2026-10-31 — Third-party review audited: `0x40008000` is an Arm SP805 watchdog; the post-halt AP death is proven to be `WDOGRES`, cleared; unlimited halt headroom obtained

- **Method:** external review (Codex) claims checked against the repo plus three ARM documents now in `vendor/arm/`: SP805 TRM **DDI 0270B** (file `DDI0270 (4) 2 (1).pdf`), Cortex-M3 r2p0 TRM **DDI 0337G**, CoreSight spec **IHI 0029G**. Static: byte-level literal scans of the images, Ghidra call graph, re-decode of stored probe JSON. Live: new `tools/jlink/probe_wdt.py` (`ids`, `service` modes). Logs: `dumps/2026-10-31/wdt_ids_*.json`, `wdt_service_*.json`.
- **Identification [DDI0270B][FW][HW]:** `0x40008000` is an Arm PrimeCell **SP805 watchdog**. Register map matches exactly (`+0x00 WdogLoad`, `+0x04 WdogValue`, `+0x08 WdogControl` bit0=INTEN/bit1=RESEN, `+0x0C WdogIntClr`, `+0x10 WdogRIS`, `+0x14 WdogMIS`, `+0xC00 WdogLock` key `0x1ACCE551`, ITCR/ITOP `+0xF00/04`, IDs `+0xFE0…+0xFFC`). Live PCellID0-3 = `0D F0 05 B1` = the TRM values **exactly**. PeriphID0-2 = `24/B8/1B` vs the r1p0 reset values `05/18/14` → an AMBA-legal **vendor-customized variant** (custom PartNo, LSB of PeriphID0=0), not the stock r1p0 die-for-die.
- **Grep trap recorded:** ASCII-searching listings for the key literal fails — objdump renders `0x1ACCE551` as halfword "instructions" (`e551`/`1acc`). Byte-scan the binaries: 3 copies in `app1.bin` (VA `0xe7f8`, `0x10d04`, `0x15150`), 3 in `ld6002b.bin`.
- **App1 watchdog lifecycle [FW]:** arm at boot: banner `FUN_00010c84` → `FUN_00010ce4(10)` = unlock → IntClr → `Load = 10 × 0x2FAF080 = 0x1DCD6500` (the live value) → `Control = 3` → re-lock (`FUN_00015178` writes `+0xC00`; `FUN_00015164` writes `+C=1, +0=v, +8=3`). Feed: main loop `FUN_00011368` → `FUN_0000e7d8(10)` = unlock → rewrite `Load` → re-lock (TRM §2.5: a Load write reloads immediately; stock never needs IntClr while fed). Disable: `FUN_00015138` = unlock → `Control=0` → re-lock, called **only** from the TF `0x3000` (OTA) and `0x4000` handlers. Erratum: the init trace's "FUN_0000cd64 writes 0x40008000…" was a misattribution; the writer is the arm path above (`cd64` touches only `0x40003xxx`).
- **Mechanism, now proven on bench [HW 2026-10-31, service run]:** halt mid-run → counter keeps decrementing at **100.0e6/s** (so the real timeout is ~5.0 s, not the 10 s the stock `50e6/tick` constant suggests); at t=3.99 s first timeout: `RIS/MIS → 1/1`, `ICSR → 0x80C02000` (NMIPENDSET + VECTPENDING=2), counter **auto-reloaded** per §2.3. Unlock `+0xC00=0x1ACCE551` → lock reads `0`. Write `+0x0C=1` → **RIS/MIS → 0/0, Value reloaded** — the interrupt source cleared for the first time. Stock disable `+0x08=0` → counter frozen (delta 0 over 1 s), re-lock reads `1`. Core stayed halted and the **AP survived the full 30 s**, straight through the 8.98–9.14 s death point of every earlier probe, with `S_HALT=1 / S_LOCKUP=0` throughout. The core-side latched `NMIPENDSET` never cleared (expected: M3 cannot clear it while halted) and was **harmless** — the killer was purely the peripheral-side second-timeout `WDOGRES`. Ended reset-and-run; board boots normally.
- **Retracted — "S_HALT is not trustworthy on this part"** (2026-10-29): decoder artifact. DDI 0337G Table 10-2: S_REGRDY=16, **S_HALT=17**, S_SLEEP=18, **S_LOCKUP=19**, sticky S_RETIRE_ST=24/S_RESET_ST=25, and DHCSR[31:16] *reads back as status [25:16]* — `0x00030003` is a textbook halted/no-lockup read. All 43 stored samples in `nmi_source_probe.json` re-decode to S_HALT=1, S_LOCKUP=0.
- **Retracted — "the NMI source is level-asserted (ICSR bit 27 could not clear it)"**: bit 27 on this part is **PENDSVCLR** (DDI 0337G Table 8-15: PENDSVSET=28, PENDSVCLR=27, PENDSTSET=26, PENDSTCLR=25; ISRPREEMPT=23 explains the `0x00C00000` bits we kept seeing). The M3 ICSR has **no NMI-clear bit**; that experiment cleared nothing, and the persisting pending bit proved nothing about the source.
- **Reinterpreted — "masking at the source failed"** (`+0x10/+0x14` writes ignored): doubly expected to fail — RIS/MIS are read-only, **and** every write except `WdogLock` is ignored while the lock is locked (live `lock=1` while App1 runs, as stock re-locks after each change).
- **New practical rules:** for long halt sessions on a running app: `+0xC00=0x1ACCE551` → `+0x0C=anything` (clear + reload; repeatable, can re-arm later via `+0x00/+0x08`) or `+0x08=0` to stop. `reset(halt=True)` remains the zero-risk path (block is clock-gated until the app arms it, reads all-`0xFFFFFFFF`). The trace budget rule ("stay under ~8 s") is now a choice, not a hard ceiling — long traces can service the dog.
- **Live feed observed [HW]:** in the read-only `ids` run the counter went UP between two samples (0.5 s apart) — a main-loop feed caught in the act, consistent with the `FUN_0000e7d8(10)` model and feeds landing well under 0.1 s apart at that moment.
- **Still open [?]:** what exactly `WDOGRES` resets (core-only vs the full chip — our continuity observations only show the boot chain re-ran); whether WDOGINT→NMI is fixed or programmable SoC wiring; whether `+0xFE0` PeriphID reads are static config or aliasing.
- **Files:** new `tools/jlink/probe_wdt.py`; decoders fixed in `probe_nmi_source.py` (was bits 1-4 — wrong in both conventions), `probe_nmi_clear.py` superseded-tagged; `firmware/hello_radar.c` comments now describe the SP805 and the handover problem; `ARCHITECTURE.md` (0x40008000 row, debug caveat, trace budget, tools, open questions); `tmp/arm_docs/*.txt` (extracted TRM text). No flash writes; only SP805 registers (`+0xC00`, `+0x0C`, `+0x08`), mirroring stock's own TF-0x3000 disable sequence. Board left running.
