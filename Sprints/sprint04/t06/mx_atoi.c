#include <stdbool.h>
bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int number = 0;
    int count = 0;
    if (str[0] == '-') {
        count = -1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isdigit(str[i])) {
            number = number * 10 + str[i] - '0';
        }
        else if (mx_isspace(str[i])) {
            return 0;         
        }    
    }
    return (count == -1) ? number *= -1 : number;
}

