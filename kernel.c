typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef uint32_t size_t;

extern char __bss[], __bss_end[], __stack_top[];

/* memset: set n bytes starting at buf to c */
void *memset(void *buf, char c, size_t n){
    uint8_t *p = (uint8_t *)buf;
    while (n--)
        *p++ = c;
    return buf;
}

void kernel_main(void){
    memset(__bss, 0, (size_t) __bss_end - (size_t) __bss);

    for (;;);
}

__attribute__((section(".text.boot"))) /* put this function in the .text.boot section */
__attribute__((naked)) /* no prologue/epilogue code */
void boot(void){
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n" /* set stack pointer to the top of the stack */
        "j kernel_main\n" /* jump to kernel_main */
        :
        : [stack_top] "r"(__stack_top) /* __stack_top is stored in a general purpose register named stack_top */
    );
}