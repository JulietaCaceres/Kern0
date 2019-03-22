#include "write.h"


#define VGABUF ((volatile char *) 0xb8000)
#define VGA_COLS 80
#define VGA_FILAS 25
#define STEP 2

void vga_write(const char *s, int8_t linea, uint8_t color) {

    volatile char *buf = VGABUF;
    
    if(linea >= VGA_FILAS)
	    return;

    if(linea < 0)
	    linea = VGA_FILAS + linea - 1;
   
    buf += linea * STEP*VGA_COLS;

    while(*s != 0){
        *buf++ = *s++;
        *buf++ = color;
    }
}
