/*
 * hello_radar v0 — HLK-LD6004 / Andar ADT6101P replacement firmware scaffold.
 *
 * Clean-room scaffold written from our own documented findings
 * (ARCHITECTURE.md / DEBUG_LOG.md). v0 is READ-ONLY: it brings up UART0 with
 * polled TX and dumps a live snapshot of the radar engine state. It writes
 * only to UART0/pinmux registers; no front-end or DSP registers are touched.
 *
 * Load address: 0x00008000 (RAM code window, per Boot Area contract).
 * Image header (16 B) is prepended by tools/mk_image.py.
 *
 * Register facts are evidence-tagged in ARCHITECTURE.md:
 *   UART0 0x40004000: +0x00 TX data, +0x04 bit0 = TX busy, +0x08 = 0xb enable,
 *                     +0x10 = clock/baud divisor.  [FW: Boot Area putc + app uart init]
 *   Pinmux 0x40020030 + 4*pin: P00=1, P01=0x81 for UART0.                    [FW][HW]
 *   DSP engine 0x40021000 (channels src/dst/ctrl, status +0x58).             [FW][HW]
 *   ADC sample port 0x40023000 (DMA source).                                 [HW]
 *   RF synth 0x40008000 (+0/+4 = Hz).                                        [HW]
 *   Front end 0x40003000 (config regs from +0x100 up).                       [FW][HW]
 *   Range-Doppler map (stock App2 profile) at 0x20010000.                    [FW]
 */

#include <stdint.h>

#define UART0           ((volatile uint32_t *)0x40004000)
#define PINMUX          ((volatile uint32_t *)0x40020030)   /* + 4*pin */

#define CLK_HZ          50000000u
#define BAUD            115200u

static void uart_init(void)
{
    PINMUX[0] = 1;      /* P00 -> UART0 */
    PINMUX[1] = 0x81;   /* P01 -> UART0 */
    UART0[4] = CLK_HZ / BAUD;   /* +0x10 divisor */
    UART0[2] = 0xb;             /* +0x08 mode/enable */
}

static void putc_(char c)
{
    while (UART0[1] & 1)        /* +0x04 bit0 = TX busy */
        ;
    UART0[0] = (uint32_t)(uint8_t)c;
}

static void puts_(const char *s)
{
    while (*s)
        putc_(*s++);
}

static void puthex(uint32_t v)
{
    static const char d[] = "0123456789abcdef";
    for (int i = 28; i >= 0; i -= 4)
        putc_(d[(v >> i) & 0xf]);
}

static void dump_block(const char *title, const volatile uint32_t *base, int words)
{
    puts_(title);
    puts_(":\r\n");
    for (int i = 0; i < words; i += 4) {
        puthex((uint32_t)(uintptr_t)(base + i));
        puts_(" ");
        for (int j = 0; j < 4 && i + j < words; j++) {
            puthex(base[i + j]);
            puts_(" ");
        }
        puts_("\r\n");
    }
}

void reset_handler(void)
{
    /* zero our small .bss (Boot Area does not clear it) */
    extern uint32_t __bss_start__, __bss_end__;
    for (uint32_t *p = &__bss_start__; p < &__bss_end__; p++)
        *p = 0;

    uart_init();
    puts_("\r\nhello-radar v0 (ADT6101P) read-only snapshot\r\n");

    /* Live radar engine state (read-only). */
    dump_block("front-end 0x40003100", (const volatile uint32_t *)0x40003100, 0x60);
    dump_block("rf synth  0x40008000", (const volatile uint32_t *)0x40008000, 4);
    dump_block("timer   0x4000C000",   (const volatile uint32_t *)0x4000C000, 0x20);
    dump_block("dsp     0x40021000",   (const volatile uint32_t *)0x40021000, 0x20);
    dump_block("adc port 0x40023000",  (const volatile uint32_t *)0x40023000, 8);
    dump_block("map     0x20010000",   (const volatile uint32_t *)0x20010000, 0x40);

    puts_("snapshot done, idling\r\n");
    for (;;)
        ;
}

void default_handler(void)
{
    for (;;)
        ;
}

/* Vector table: Boot Area loads SP from +0 and branches through +4.
 * 16 entries mirrors the stock layout closely enough for bring-up. */
__attribute__((section(".vectors"), used))
void (* const vectors[])(void) = {
    (void (*)(void))0x20007C00,   /* initial SP (below sample buffers at 0x20008000) */
    reset_handler,
    default_handler,              /* NMI */
    default_handler,              /* HardFault */
    default_handler, default_handler, default_handler, default_handler,
    default_handler, default_handler, default_handler, default_handler,
    default_handler, default_handler, default_handler, default_handler,
};
