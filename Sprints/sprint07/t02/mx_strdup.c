#include <stdlib.h>
#include <stdio.h>
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str) {
	int len = mx_strlen(str);
	char *temp = mx_strnew(len);
	return mx_strcpy(temp, str);
}

