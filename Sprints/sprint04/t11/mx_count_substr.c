#include <stdio.h>

int mx_strlen(const char *c);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
	int number = 0;
	if (mx_strlen(sub) == 0 || mx_strlen(str) == 0) {
		return number;
	}
	while (mx_strstr(str, sub) != NULL) {
		number++;
		str = mx_strstr(str, sub) + mx_strlen(sub);
    	}
	return number;
}


