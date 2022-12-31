#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char const *mx_return_s (char const *s1, char const *s2);

char *mx_strjoin(char const *s1, char const *s2) {
	if (s1 == NULL && s2 == NULL) {
		return NULL;
	}
	if (s1 != NULL && s2 != NULL) {
		int len = mx_strlen(s1) + mx_strlen(s2);
		char *temp = mx_strnew(len);
		temp = mx_strcat(temp, s1);
		return mx_strcat(temp, s2);
	}
	else if (s1 == NULL || s2 == NULL) {
		int lenght = mx_strlen(mx_return_s(s1, s2));
		char *s = mx_strnew(lenght);
		mx_strcat(s, mx_return_s(s1, s2));
		return s;
	}
	return NULL;
}
	
char const *mx_return_s (char const *s1, char const *s2) {
	if (s1 == NULL) {
		return s2;
	}
	else {
		return s1;
	}
}


