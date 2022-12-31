#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size) {
	if (size >= 0) {
		char *s = (char *)malloc((size + 1) * sizeof(char));
		for (int i = 0; i < size + 1; i++) {
			s[i] = '\0';
		}
		return s;
	}
	return NULL;
} 

int mx_strlen(const char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

char *mx_strdup(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	int len = mx_strlen(str);
	char *temp = mx_strnew(len);
	int i;
	for (i = 0; str[i] != '\0'; i++) {
        	temp[i] = str[i];
    }
    temp[i] = '\0';
   	return temp;
}


