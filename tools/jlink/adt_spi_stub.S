@ RAM stub: one SPI transaction on the ADT6101P flash SPI (0x4000E000), CS = GPIO4.
@ Mirrors the stock app's driver (spi init 0x13d84, cs 0x13d2c/0x13d58, xfer 0x13e04).
@ In:  r0 = tx ptr, r1 = tx len, r2 = rx ptr, r3 = rx len, r4 = SPI divider (0 = skip init)
@ Out: halts on BKPT. Sends only the bytes in tx, then clocks 0xFF for rx.
    .syntax unified
    .thumb
    .text
    .global _start
_start:
    cpsid   i
    ldr     r5, =0x4000E000         @ SPI
    ldr     r6, =0x40020000         @ GPIO / pinmux
    cbz     r4, cs_low
    movw    r7, #0x601              @ pins 3..6 -> SPI function, as app does
    str     r7, [r6, #0x3c]
    str     r7, [r6, #0x40]
    str     r7, [r6, #0x44]
    str     r7, [r6, #0x48]
    movs    r7, #7
    str     r7, [r5, #0x00]
    movs    r7, #4
    str     r7, [r5, #0x04]
    str     r4, [r5, #0x10]
    movs    r7, #2
    str     r7, [r5, #0x04]
    str     r7, [r5, #0x14]
cs_low:
    movs    r7, #0
    str     r7, [r6, #0x40]         @ pin4 -> GPIO
    ldr     r7, [r6, #0x24]
    orr     r7, r7, #0x10
    str     r7, [r6, #0x24]
tx_loop:
    cbz     r1, rx_loop
    ldrb    r7, [r0], #1
    bl      xfer
    subs    r1, r1, #1
    b       tx_loop
rx_loop:
    cbz     r3, done
    movs    r7, #0xff
    bl      xfer
    strb    r7, [r2], #1
    subs    r3, r3, #1
    tst     r3, #0xff
    bne     rx_loop
    ldr     r7, =0x40022000         @ same write the app makes after each flash read
    movs    r4, #1
    str     r4, [r7, #0x1c]
    b       rx_loop
done:
    ldr     r7, [r5, #0x0c]         @ wait busy clear
    tst     r7, #0x10
    bne     done
    movs    r7, #0
    str     r7, [r6, #0x40]
    ldr     r7, [r6, #0x20]         @ CS high
    orr     r7, r7, #0x10
    str     r7, [r6, #0x20]
    bkpt    #0
    b       .

xfer:
    str     r7, [r5, #0x08]
1:  ldr     r12, [r5, #0x0c]
    tst     r12, #1
    beq     1b
2:  ldr     r12, [r5, #0x0c]
    tst     r12, #4
    beq     2b
    ldr     r7, [r5, #0x08]
    uxtb    r7, r7
    bx      lr

    .ltorg
