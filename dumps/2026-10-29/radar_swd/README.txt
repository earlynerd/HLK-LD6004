LD6004 radar SoC (Andar ADT6101P) memory read over SWD, 2026-10-29
Probe: SEGGER J-Link BASE Compact V12 (S/N 822007774), J-Link V9.68, SWD 4 MHz, device Cortex-M3.
Read-only: no halt, reset, erase or write. Scripts: tools/jlink/{identify,probe_size,dump_code}.jlink

Target: SW-DP 0x2BA01477, one AHB-AP, CPUID 0x412FC231 = Cortex-M3 r2p1, ROM table 0xE00FF000 (SCS/DWT/FPB).
No readout protection.

Memory map (observed):
  0x00000000-0x0001FFFF  128 KiB SRAM code/data window, mirrored every 0x20000 (seen to 0x01000000,
                         and at 0x08000000/0x10000000/0x18000000). 0x60000000 not readable.
    0x0000-0x7FFF  "Bootloader V6.3.0" (used 0x1727 B). SP 0x20004038, reset 0xE1.
                   Strings: Load bin file to RAM / Jump to flash / Jump to EEPROM / boot pin status /
                   "Please send user code through HyperTerminal" (=> YMODEM upload).
    0x8000-0x17FFF Application (used ~0xDABC B). SP 0x20006030, reset 0x80D1.
                   Banner "Andar ADT6101P human detection 3d V%d.%d.%d", TinyFrame.
    0x18000-0x1FFFF changes between reads (live data / stack).
  0x20000000-0x2003FFFF  SRAM (0x20040000 not readable); 0x2001xxxx holds 16-bit I/Q-like samples.
  Code at 0..0x17FFF is identical across two reads and the 0x20000 alias, so it is a stable image.
  Inference: code is copied from the external ZB25VQ80 into this RAM at boot.

Files:
  code_00000_a.bin / code_00000_b.bin  raw 0x0-0x1FFFF reads (differ only >= 0x18000)
  code_20000.bin                       alias read
  adt6101p_boot_0x0000.bin  sha256 3da4383bebe734a0c1876b350497872ebea0d0b1b54daa2adcb2a52193e171d9
  adt6101p_app_0x8000.bin   sha256 d96b2d756283ebb7e81a61040cd4c71647d2682d6408402814fa93e52ef71120
    (0x10000 B window; load address 0x8000)

Comparison: LD6002B v3.9.0 OTA image = 16-byte header {u16 len, u16 len, u32 0x105A (unknown), u32 2, u32 0}
+ raw app for 0x8000 (len 0xC850). The LD6004 app is ~90% similar (difflib, first 20 KB): same
"human detection 3d" codebase, newer/larger build.
