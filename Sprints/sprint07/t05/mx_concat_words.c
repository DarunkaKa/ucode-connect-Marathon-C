#include <stdio.h>
void mx_strdel(char **str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_concat_words(char **words) {
    if (words == NULL) {
    	return NULL;
    }
    char *s = words[0];
    words++;
    while (*words != NULL) {
        s = mx_strjoin(mx_strjoin(s, " "), *words);
        words++;
    }
    mx_strdel(words);
    return s;
}

