#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void) {
	char symbol;
	for (int i = 1; i <= 26; i++){
		if (i % 2 != 0) {
			symbol = 64 + i;
		}
		else {
			symbol = 96 + i;
		}
		mx_printchar(symbol);
	}
	write(1, "\n", 1);
}	

