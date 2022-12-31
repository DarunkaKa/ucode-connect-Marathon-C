#include <unistd.h>
#include <stdbool.h>
bool mx_isspace(char c) {
    if (c == ' ' 
        || c == '\n'
        || c == '\r'
        || c == '\t'
        || c == '\f'
        || c == '\v') {
        return true;
    }
    return false;
}

