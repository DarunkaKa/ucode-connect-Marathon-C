#include "file_to_str.h"

char *mx_strdup(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	int len = mx_strlen(str);
	char *temp = mx_strnew(len);
	return mx_strcpy(temp, str);
}

