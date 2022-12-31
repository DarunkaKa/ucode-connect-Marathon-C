#include "../inc/matrix.h"

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
	mx_strncpy(arr, str, lenght);
	return arr;
}


