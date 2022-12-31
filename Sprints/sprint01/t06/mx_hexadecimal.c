#include <unistd.h>

void mx_printchar(char c);
void mx_hexadecimal(void){
	for (int i = 0; i < 16; i++){
		char hex;
		if (i <= 9){
			hex = 48 + i;
		}
		else{
			hex = 55 + i;
		}
		mx_printchar(hex);
	}
	write(1, "\n", 1);
}
