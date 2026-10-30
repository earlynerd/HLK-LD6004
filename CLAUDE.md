# HLK-LD6004 firmware rewrite

## Purpose

We own several HLK-LD6004 60 GHz presence-radar modules and are writing replacement firmware for them. The stock firmware only reports finished presence/target results over a 115200-baud TinyFrame UART. We want the modules to output richer data, such as range/Doppler/angle data or raw samples, for our own sensing work.

The radar SoC (Andar ADT6101P) has no public datasheet, register map or SDK. The only way to learn how to configure its radar front end and peripherals is to study the hardware and the firmware shipped on our own units. That analysis is the means; the deliverable is new firmware.

## Scope and ground rules

- **Our hardware only.** All reading, debugging and flashing is done on modules we bought and physically hold. The chips have no readout protection; no security mechanism is being bypassed.
- **Clean rewrite, not a patched vendor image.** Vendor firmware is studied to document hardware behaviour: register addresses, init sequences, timing, data formats and calibration storage. Findings go into our own docs (`ARCHITECTURE.md`, `DEBUG_LOG.md`), and the new firmware is written from those docs. The stock flash dumps in `dumps/` are published in the repo so others can analyse them; `analysis/` outputs (extracted images, disassembly, decompiled C, Ghidra project) and `vendor/` downloads stay local (see `.gitignore`).
- **Reversible.** Verified stock backups of every flash are kept in `dumps/` (hashes in `ARCHITECTURE.md`), so any unit can be restored to factory firmware.
- **Interfaces stay as designed.** The rewrite uses the module's existing header UART/SWD and, optionally, the onboard BLE bridge. It is a sensor for our own use, not something deployed on others' devices or networks.

## Where things are

- `ARCHITECTURE.md`: what is known about the hardware, with evidence tags ([HW]/[FW]/[DS]/[?]).
- `DEBUG_LOG.md`: dated log of bench sessions and findings.
- `dumps/2026-10-29/`: stock flash backups and RAM reads (restore baseline; never modify).
- `analysis/adt6101p/`: extracted radar images, disassembly listings and strings.
- `tools/`: our own scripts (SWD flash reader, image unpackers, flash-map summariser).
- `vendor/`: vendor documents and public downloads, kept as received.

## Working environment (read before scripting)

- **Shell is PowerShell 7 on Windows — heredocs do not exist.** `python - <<'PY'` fails with `Missing file specification after redirection operator`. Inline `python -c "..."` also breaks on `$`, backticks and nested quotes. **Write the script to a file and run the file.**
- **pylink is installed only for Python 3.14.** Run SWD tools as `& "C:\Program Files\Python314\python.exe" tools\jlink\<tool>.py`; the default `python` (3.12) has no pylink.
- pylink 2.0.1 has **no `go()`** — resume with `restart(num_instructions=0, skip_breakpoints=True)` or `reset(halt=False)`. There is no `is_connected()` — use `target_connected()`.
- Scratch scripts live in `tmp/`; anything worth keeping goes in `tools/`.

## Current focus

1. **Radar front end:** how App1 (production) and App2 (factory test/calibration) configure the ADT6101P: chirp/ADC setup, TX/RX channel selection, sample buffers in SRAM, and where antenna-phase calibration lives.
2. **Data export:** which interfaces can carry a richer stream: UART0 at higher baud (50 MHz clock), UART1/UART2, the second SPI, the I²C-style controller, and whether the JieLi BLE bridge's fixed 115200 link is a bottleneck.
