LD6004 radar external SPI NOR (ZB25VQ80) read through the ADT6101P over SWD, 2026-10-29
Tool: tools/jlink/adt_spi_flash_read.py + adt_spi_stub.bin (RAM stub at 0x20002000).
Read-only: opcode allow-list {03 05 15 35 48 4B 5A 90 9F AB}; no WREN/program/erase sent.
Core halted in 38 short sessions (<=1.5 s each), each ended with reset-and-run; the target
otherwise drops off SWD ~5 s after a halt (cause not identified; 0x40022000 block is not it).

Chip
  JEDEC 9F      5E 60 14   Zbit, 2^0x14 = 1 MiB (8 Mbit)
  REMS 90       5E 13      RES AB: 13
  UID 4B (16B)  f5b87a9665b770 5350504a3336324131  (tail ASCII "SPPJ362A1")
  SR1/SR2/SR3   00 00 00   no block protection, QE=0, SRP=0 -> array is writable
  SFDP          JESD216 v1.7, 16 dwords @0x30: 4K/32K/64K erase = 20/52/D8, 1-1-2/1-2-2/1-1-4/1-4-4
                Zbit vendor table (id 5E) @0x70: VCC 2.3-3.6 V          -> sfdp.bin
  Security regs 0x48 @ 0x1000/0x2000/0x3000: all FF (0x0000 page = SFDP)  -> secreg*.bin
SPI host (from boot/app disasm): SPI @0x4000E000 (DR +8, SR +C: b0 tx done, b2 rx ready, b4 busy),
  pins 3,5,6 mux 0x601 at 0x40020030+4*pin, CS = GPIO4 (set +0x20, clear +0x24).

Dumps
  zb25vq80_a.bin / zb25vq80_b.bin  identical, sha256 e9a61b63e6149494effda28f77472219bfb0afe165c3f6f9125b728f1719b104

Layout. Every image has a 16-byte header: u16 len, u16 len, u8 0x5A (code exists), u24 code offset (0x10),
u8 SPI divider (2), then 7 bytes (non-zero only for 0x0 and 0x8000; probably CRC32). Same as LD6002B OTA files.
  0x000000  hdr len 0xFFC   "jump code" stage 2; ROM-resident Bootloader V6.3.0 loads it to RAM 0x8000.
  0x008000  hdr len 0x3034  "Boot Area" v2.0.7 (runs in RAM ~0x20009000): App1/App2 selection, CRC32 check,
                            YMODEM-style UART update ("SOH" frames), factory mode.
  0x010000  boot settings:  02 AA 00 FF 02 FF 02 FF ... (isUpdateFg/updateAppxFg/loadFg/factoryFg; field
                            mapping unverified). App TF cmd 0x3000 rewrites this sector (byte1 := FF) then
                            resets -> enter update mode. App TF cmd 0x4000 writes 02 at 0x10007 (currently FF).
  0x014000  config log, records start with magic 0xDEADBEFF (at 0x14000, 0x14068, 0x140E4); payloads are
                            float32 (-6.0, 6.0, 0.5 ...) - looks like detection-area bounds. App reads 0x184 B.
  0x018000  App1, len 0xDABC: "ADT6101P human detection 3d" - byte-identical to the RAM image at 0x8000.
  0x038000  App2, len 0x9E4C: factory test/calibration image (per-TX/RX distance/power, phase calibration,
                            noise, ADC bias tests).
  everything else FF.
