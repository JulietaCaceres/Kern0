static volatile unsigned int* VGABUF = (volatile char*) 0xb8000;

void comienzo(void) {

        volatile unsigned int *p = VGABUF;
        *p =0x2F4B2F4F;
        while (1)
                asm("hlt");
}
