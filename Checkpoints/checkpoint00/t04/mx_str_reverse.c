#include <stdio.h>
void mx_str_reverse(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    for (int k = 0; k <= i / 2; k++) {
        char temp = s[k];
        s[k] = s[i - 1- k];
        s[i - 1 - k] = temp;
    }
}

//int main() {
//	char str[210] = "ohs1l3PU5T5he3VnEPKAAaVBEGXt6rXoiPjAqrRsTO4F	hKpTB4";
//	mx_str_reverse(str);
//	printf("%s\n", str);
//}
