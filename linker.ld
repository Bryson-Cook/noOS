/* Define entry point */
ENTRY(_start)

/* Define sections of kernel image */ 
SECTIONS {
	/* load kernel beginning at 1 MiB */
	. = 1M;

	/* multiboot header must be defined first */
	.text BLOCK(4K) : ALIGN(4K) {
		*(.multiboot)
		*(.text)
	}
 
	.rodata BLOCK(4K) : ALIGN(4K) {
		*(.rodata)
	}
 
	.data BLOCK(4K) : ALIGN(4K) {
		*(.data)
	}
 
	.bss BLOCK(4K) : ALIGN(4K) {
		*(COMMON)
		*(.bss)
	} 
}
