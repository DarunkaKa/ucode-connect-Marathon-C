#include <stdio.h>
int mx_sqrt(int x) {
    if (x < 0) {
        return 0;
    }
    for (int i = 0; i < x; i++) {
        if ((i * i) == x) {
            return i;
        }                
    }
    return 0;
}

//int main(void) {
//	printf("%i\n", mx_sqrt(3));
//	printf("%i\n", mx_sqrt(4));
//}

