#include <stdio.h>
#include <stdbool.h>
int mx_strlen(const char *s);
bool mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src);
char *mx_strnew(const int size);
void mx_strdel(char **str);

char *mx_strtrim(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	while (mx_isspace(*str)) {
		str += 1;
	}
	int lenght = mx_strlen(str);
	while (mx_isspace(str[lenght - 1])) {
		lenght -= 1;
	}
	char *arr = mx_strnew(lenght);
	mx_strncpy(arr, str);
	return arr;
}


