#include <stdio.h>
#include <stdbool.h>
int mx_strlen(const char *s);
bool mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src);
char *mx_strnew(const int size);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);
char *mx_del_extra_whitespaces(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	char *temp = mx_strnew(mx_strlen(str));
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (mx_isspace(str[i]) == false) {
			temp[k] = str[i];
			k++;
		}
		if ((mx_isspace(str[i]) == false) 
			&& mx_isspace(str[i + 1])) {
			temp[k] = ' ';
			k++;
		}								
	}
	char *s = mx_strtrim(temp);
	mx_strdel(&temp);
	return s;
}


		
