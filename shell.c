#include "user.h"

void main(void) {
    *((volatile int *)0x80200000) = 0x1234; // this causes a page fault
    for (;;)
        ;
}