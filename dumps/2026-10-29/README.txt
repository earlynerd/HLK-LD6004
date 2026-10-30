LD6004 radar - JieLi AC6323A4 (BD19 / AC632N) internal flash dump, 2026-10-29

Method: kagaimiq/jl-uboot-tool @ adb3f18 over USB UBOOT (BD19 UBOOT1.00, VID 4C4A PID 3442),
        entered via JieLi USB Updater V4.x programmer, DIP 1 ON, radar on separate 3.3 V supply.
Loader: bd19loader.bin in RAM, arg 0x0001 (SPI NOR, 3-wire). No flash erase/write performed.
Chip key: 0xA80F    Flash ID: 0xCD7113 (512 KiB)

jieli_flash_a.bin  524288 bytes  sha256 83e2dfd0b84550a552031263fba9bae7bff67dcdb7798e7e558335d6d4484ed9
jieli_flash_b.bin  524288 bytes  sha256 83e2dfd0b84550a552031263fba9bae7bff67dcdb7798e7e558335d6d4484ed9
Two consecutive reads are byte-identical.

Contents: last non-FF byte at 0x7D009; ~188 KiB used. Header at 0x0 carries "AC632N";
bulk of image is encrypted (expected: JieLi chip-key / CRC cipher). Plaintext config strings
near 0x13A6 (e.g. UPDATE_JUMP, PB01_08_0).
This is the stock HLK image - keep as the restore baseline.

--- Decryption (2026-10-29, tools/jl_fw_unpack.py, offline) ---
unpack/decrypted.bin, unpack/top/*, unpack/files/*, unpack/layout.json
Flash header: VID "0.01", PID "AC632N", flash size 0x7F000, burner 544.
Top: uboot.boot @0xA0 (4831 B), isd_config.ini @0x137F, app_dir_head @0x2000, key_mac @0x7F000.
isd_config chip key 0xA80F matches the chip. isd_config: SPI 2_3_0_0, UTTX=PA05, UTBD=1000000,
  UTRX=PP00, RESET=PB01_08_0.
App (entry 0x1E00120): app.bin 182716 B (CRC OK), cfg_tool.bin 722 B (CRC OK), p11_code.bin (CRC OK),
  VM @0x32000 (308 KiB), PRCT, BTIF @0x7F000, EXIF.
app_rodata_strings.txt: readable log/format strings from app.bin.

Findings: HLK project "E:\baker\LD6004\hlk-b25", built from JieLi AC63 SDK example
apps/spp_and_le/examples/at_char_com (BLE<->UART transparent bridge + AT commands + RCSP OTA),
board_ac632n_demo.c. BLE name format "LD6004-%02X%02X". HLK_UART/HLK_CMDS module intercepts
radar commands; "[LD6004]*****6004 in OTA mode*****" / "[LD6004]FW ver:%s" suggest it can relay
updates to the radar SoC. No radar signal processing in this image. Full debug log strings present.
SDK update lib tag: UPDATE-@20221123-$330d72d.
