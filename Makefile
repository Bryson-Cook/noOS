CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -g -c

noOS.iso: noOS.elf
	rm ./isoroot/boot/noOS.elf
	cp noOS.elf ./isoroot/boot/
	grub-mkrescue -o noOS.iso isoroot

noOS.elf: boot.o kernel.o
	$(CC) -ffreestanding -nostdlib -g -T linker.ld boot.o kernel.o -o noOS.elf -lgcc

boot.o: boot.s
	${CC} $(CFLAGS) boot.s -o boot.o

kernel.o: kernel.c
	$(CC) $(CFLAGS) kernel.c -o kernel.o

clean:
	rm -f *.o *.elf *.iso
