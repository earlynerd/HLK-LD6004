/* ADT6101P: app is loaded to and runs from the RAM code window at 0x8000.
 * RAM data/stack at 0x20000000; keep the stack below 0x20008000 (sample buffers). */
MEMORY
{
    CODE (rx)  : ORIGIN = 0x00008000, LENGTH = 0x7800
    RAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 0x0600
}

ENTRY(reset_handler)

SECTIONS
{
    .text : {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
    } > CODE

    .data : {
        __data_start__ = .;
        *(.data*)
    } > CODE

    .bss (NOLOAD) : {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    } > RAM

    /DISCARD/ : { *(.ARM.exidx*) *(.ARM.attributes) }
}
