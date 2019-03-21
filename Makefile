CFLAGS := -g -std=c99 -Wall -Wextra -Wpedantic
CFLAGS += -m32 -O1 -fasm -ffreestanding

kern0: boot.o kern0.o
	ld -m elf_i386 -Ttext 0x100000 --entry comienzo $^ -o $@
	# Verificar imagen Multiboot v1.
	grub2-file --is-x86-multiboot $@

%.o: %.S
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f kern0 *.o core

.PHONY: clean
