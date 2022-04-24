/* Declare multiboot variables */
.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)
 
 /* Declare multiboot header */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
tt
/* Allocate the stack */
.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
	/* Set esp register to point to top of the stack */
	mov $stack_top, %esp

	/* Enable paging and load GDT before entering kernel. */
	/* Very useful for ISRs (Interrupt Service Routines) */

	/* Call kernel_main from kernel.c */
	call kernel_main

	/* Nothing more to do, enter infinite loop */
	cli
1:	hlt
	jmp 1b

/* Useful for debugging and if call tracing is implemented. */
.size _start, . - _start
