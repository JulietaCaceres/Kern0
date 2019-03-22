#include <stdio.h>

int main(void) {
    unsigned int i = 0x646C72;
    printf("H%x Wo%s\n", 57616, (char *) &i);
}
