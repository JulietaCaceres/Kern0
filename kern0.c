#include "write.h"

void comienzo(void) {

        vga_write("OK", 8, 0x70);
        vga_write("HOLA",9,0xE0);
        while (1)
                asm("hlt");
}
