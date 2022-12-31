#include <stdbool.h>

int mx_tolower(int c);
bool mx_isupper(int c);
bool mx_islower(int c);
int mx_toupper(int c);

void mx_reverse_case(char *s) {
	int count = 0;
	char *char_arr;
	char_arr = s;
	while (*char_arr) {
		char_arr++;
		count++;
	}
	for (int i = 0; i < count; i++) {
		char temp = s[i];
		if (mx_isupper(s[i]) == true) {
			s[i] = mx_tolower(temp);

		}
		else if (mx_islower(s[i]) == true) {
			s[i] = mx_toupper(temp);
		}
	}		
}
	
			
