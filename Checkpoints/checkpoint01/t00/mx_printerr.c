#include <unistd.h>
void mx_printerr(const char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {}
	write(2, s, i);
}

