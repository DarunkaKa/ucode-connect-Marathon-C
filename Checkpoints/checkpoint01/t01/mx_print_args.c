#include <unistd.h>
#include <stdio.h>

int mx_strlen(const char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i= 1; i < argc; i++) {
            write(1, argv[i], mx_strlen(argv[i]));
            write(1, "\n", 1);
        }
    }
}

