#include <stdio.h>
int mx_strlen(const char *c);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2) { 
    for (int i = 0; i < (mx_strlen(s1) - mx_strlen(s2)); i++) {
        char s3[mx_strlen(s2) + 1];
        s3[mx_strlen(s2)] = '\0';        
        for (int k = 0; k < mx_strlen(s2); k++) {
            s3[k] = s1[k];
        }
        if (mx_strncmp(s3, s2, mx_strlen(s2)) == 0) {
            return (char *)s1;
        }
        s1++;
    }
    return NULL;
}


