ENTRY(boot)

SECTIONS {
    . = 0x80200000;

    /* code section */
    .text :{
        KEEP(*(.text.boot));
        *(.text .text.*);
    }

    /* read only data section */
    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);
    }

    /* read and write data section */
    .data : ALIGN(4) {
        *(.data .data.*);
    }

    /* read and write data with zero initialization section */
    .bss : ALIGN(4) {
        __bss = .;
        *(.bss .bss.* .sbss .sbss.*);
        __bss_end = .;
    }

    . = ALIGN(4);
    . += 128 * 1024; /* 128KB */
    __stack_top = .;

    . = ALIGN(4096);
    __free_ram = .;
    . += 64 * 1024 * 1024; /* 64MB */
    __free_ram_end = .;
}