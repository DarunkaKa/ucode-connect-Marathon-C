#include <stdio.h>

char *mx_strchr(const char *s, int c) {
    if (c < 0 || c > 127) {
        return NULL;
    }
    for (int i = 0; s[i] != 0; i++) {
        if (s[i]  == c) {
            return (char *)(&s[i]);
	}
    }
    return NULL;
}

