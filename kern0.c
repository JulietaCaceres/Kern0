#define VGABUF ((volatile char *) 0xb8000)
#include "write.h"

void comienzo(void) {
    
    vga_write("Ok",1,15);

    while (1)
        asm("hlt");
}
