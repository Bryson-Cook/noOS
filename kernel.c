// GCC provided files
#include <stddef.h>
#include <stdint.h>
 
// Check for cross compiler.
#if defined(__linux__)
	#error "This code must be compiled with a cross-compiler"
#elif !defined(__i386__)
	#error "This code must be compiled with an x86-elf compiler"
#endif
 
// x86's VGA textmode buffer.
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
// default VGA textmode buffer is 80x25 characters
const int VGA_COLS = 80;
const int VGA_ROWS = 25;
 
int term_col = 0;
int term_row = 0;
uint8_t term_color = 0x0F; // Black background, White foreground

void term_init() {
	// Clear the textmode buffer
	for (int col = 0; col < VGA_COLS; col ++) {
		for (int row = 0; row < VGA_ROWS; row ++) {
			const size_t index = (VGA_COLS * row) + col;
			vga_buffer[index] = ((uint16_t)term_color << 8) | ' ';
		}
	}
}
 
void term_putc(char c) {
	switch (c) {
	case '\n': // Go to beginning of the next line.
		term_col = 0;
		term_row++;	 
		break;
	default:
		const size_t index = (VGA_COLS * term_row) + term_col; 	// Calculate index
		vga_buffer[index] = ((uint16_t)term_color << 8) | c; 	// Display 'c'
		term_col++; 											// Avoid character overlap 
		break;
	}
	// If we go past the last column
	if (term_col >= VGA_COLS) {
		term_col = 0;
		term_row++;
	}
	// If we go past last row
	if (term_row >= VGA_ROWS) {
		term_col = 0;
		term_row = 0;
	}
}
 
// This function prints an entire string onto the screen
void term_print(const char* str) {
	for (size_t i = 0; str[i] != '\0'; i ++) // increment index until we find '\0'
		term_putc(str[i]);
}
 
 
 
void kernel_main() {
	// Initiate (clear) terminal
	term_init();

	// Print splash screen 
	term_print("             _____ _____ \n");
	term_print("            |  _  /  ___|\n");
	term_print(" _ __   ___ | | | \\ `--. \n");
	term_print("| '_ \\ / _ \\| | | |`--. \\\n");
	term_print("| | | | (_) \\ \\_/ /\\__/ /\n");
	term_print("|_| |_|\\___/ \\___/\\____/\n"); 	
	term_print("Welcome to noOS!\n");
	term_print("We provide a revolutionary, distraction free enviornment.\n");
	term_print("Enjoy your countless hours of productivity.\n");
}
