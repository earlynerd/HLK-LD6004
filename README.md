# HLK-LD6004 firmware rewrite

Replacement firmware and hardware notes for the Hi-Link **HLK-LD6004** 60 GHz presence-radar module.

The stock firmware only reports finished presence/target results as TinyFrame packets on a 115200-baud UART. The goal here is to get richer data out of the module, such as range/Doppler/angle maps or raw ADC samples. The radar SoC is an **Andar ADT6101P**, which has no public datasheet, register map or SDK. Everything known about it comes from studying the hardware and the stock firmware on modules we own.

> **Status:** reverse-engineering is well along; the replacement firmware is a scaffold. `firmware/hello_radar.c` builds but has **not been run on hardware** yet. Nothing here is a working drop-in firmware.

## What's known so far

[`ARCHITECTURE.md`](ARCHITECTURE.md) has the full write-up. Each finding is tagged by how it was established: **[HW]** read from the board, **[FW]** inferred from firmware, **[DS]** vendor datasheet, **[?]** untested hypothesis. Highlights:

- **Two processors.** The ADT6101P (Cortex-M3, 58–64 GHz, 2TX/2RX) does all radar sensing and processing and boots from an external Zbit ZB25VQ80 1 MiB SPI NOR. A JieLi AC6323A4 is only a BLE↔UART bridge on the radar's UART; it does no radar processing.
- **Open debug access.** The ADT6101P has no readout protection. Over SWD you can read and write all memory, and a small RAM stub reads the SPI flash through the SoC.
- **Peripheral map.** Addresses and partial register layouts for the radar front end, RF synthesizer (FMCW sweep), DMA/DSP engine, ADC sample port, three UARTs, SPI and GPIO/pin mux.
- **Boot chain.** ROM bootloader V6.3.0 → jump code → Boot Area v2.0.7 → App1 (production) or App2 (factory test/calibration). The image header format and CRC32 are documented. Updates are YMODEM over UART0 with an integrity check but no signature. A ROM "load bin file to RAM" path runs code without touching flash.
- **Signal chain.** 256 ADC samples per chirp. App1 builds a 32 range × 106 Doppler map; App2 builds 32×60 maps over 4 virtual channels.
- **Debug quirk.** The radar raises an NMI at every 5-second FMCW ramp wrap. A halted core can't take it, and the debug port stops answering about two wraps later. Halts have to be timed against the ramp.

[`DEBUG_LOG.md`](DEBUG_LOG.md) is the dated bench log behind these findings.

## Repository layout

| Path | Contents |
|---|---|
| `ARCHITECTURE.md` | Hardware reference: memory map, peripherals, boot chain, flash map, serial protocol, open questions |
| `DEBUG_LOG.md` | Dated log of bench sessions and findings |
| `dumps/2026-10-29/` | Stock flash backups (radar SPI flash, radar ROM/RAM via SWD, JieLi flash) and probe logs. sha256 hashes are in `ARCHITECTURE.md` |
| `analysis/adt6101p/` | Extracted radar images, disassembly, Ghidra decompilation and project, and the Ghidra scripts used to produce them |
| `firmware/` | Replacement firmware (`hello_radar` scaffold and linker script) |
| `tools/` | SWD flash reader and probes (`tools/jlink/`), JieLi image unpacker, image header builder, flash-map and cross-reference helpers |

## Hardware and tools used

- HLK-LD6004 modules
- SEGGER J-Link on the module's SWD header (GND, SWCLK, SWDIO, BOOT1, 3V3), set up as a generic Cortex-M3
- [pylink](https://github.com/square/pylink) for the Python SWD tools
- JieLi USB programmer and [kagaimiq/jl-uboot-tool](https://github.com/kagaimiq/jl-uboot-tool) for the BLE chip's flash
- Ghidra 11 (headless) and `arm-none-eabi` binutils/gcc

### Building `hello_radar`

```sh
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -nostdlib -T firmware/hello_radar.ld \
    -o firmware/hello_radar.elf firmware/hello_radar.c
arm-none-eabi-objcopy -O binary firmware/hello_radar.elf firmware/hello_radar.bin
python tools/mk_image.py firmware/hello_radar.bin firmware/hello_radar_img.bin   # adds the 16-byte Boot Area header
```

`DEBUG_LOG.md` lists known defects in v0 that need fixing before it is loaded.

## Safety and restoring stock firmware

The SPI flash is not write-protected, and the stock app rewrites its own boot-settings sector. Keep a verified backup of every unit before writing anything; the hashes of the stock images are in `ARCHITECTURE.md`. The SWD flash reader in `tools/jlink/` is read-only by design (it uses a fixed allow-list of SPI opcodes).

## Disclaimer

This is an independent project. It is not affiliated with or endorsed by Hi-Link, Andar or JieLi. Vendor firmware images in `dumps/` and `analysis/` are the property of their respective owners and are included for interoperability research. Everything else is released under the [MIT License](LICENSE).
