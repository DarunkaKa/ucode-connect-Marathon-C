#include <stdio.h>
#include <stdlib.h>
int mx_count_words(const char *str, char delimiter);
void mx_strdel(char **str);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
char **mx_strsplit(char const *s, char c) {
	if (s == NULL) {
		return NULL;
	}
	int new_size = mx_count_words(s, c);
	char **new_arr = malloc(sizeof(char **) * new_size);
	int number = 0;
	for (int i = 0; i < new_size; i++) {		
		for (int j = 0; s[j]; j++) {
			if (s[i] != c) {
				number += 1;
			}
		}
		char *str = mx_strnew(number);
    }
    return new_arr;
}

		
