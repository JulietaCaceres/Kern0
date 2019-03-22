#include "c99int.h"
static volatile uint64_t* VGABUF = (volatile char*) 0xb8000;

void comienzo(void) {

        volatile uint64_t *p = VGABUF + 160;
        *p =0xE04FE048;
        p ++;
        *p =0xE041E04C;
        while (1)
                asm("hlt");
}
