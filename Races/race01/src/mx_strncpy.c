#include "../inc/matrix.h"
char *mx_strncpy(char *dst, const char *src, int len) {
    if (len <= 0) {
        return NULL;
    }
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {        
        if (mx_isspace(src[i]) && mx_isspace(src[i + 1])) {
        	len--;
        	continue;
        }
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

