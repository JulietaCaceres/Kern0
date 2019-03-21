CFLAGS := -g -std=c99 -Wall -Wextra -Wpedantic
CFLAGS += -m32 -O1 -fasm -ffreestanding

SRCS := $(wildcard *.c)
OBJS := $(patsubst lib/, , $(SRCS:.c=.o))

kern0: boot.o $(OBJS)
	ld -m elf_i386 -Ttext 0x100000 --entry comienzo $^ -o $@
	grub2-file --is-x86-multiboot $@

%.o: %.S
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f kern0 *.o core

.PHONY: clean
