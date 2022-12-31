#include "../inc/matrix.h"
int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] == s2[i]) {
        return 0;
    }
    return (s1[i] - s2[i]); 
}

