#include <unistd.h>

void mx_print_digit(long int n) {
    long int temp = n;
    long int lenght = 0;
    while (temp != 0) {
        temp /= 10;
        lenght += 1;
    }
    for (long int i = lenght; i > 0; i--) {
        long int c = 1;
        for (long int j = i; j > 1; j--) {
            c = c * 10;
        }
        long int number = n / c;
        n = n % c;
        number += 48;
        write(1, &number, 1);
    }
}

void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    }
    else {
        if (n == 0) {
            write(1, "0", 1);
        }
        else if (n < 0) {
            write(1, "-", 1);
            n = n * -1;
        }        
        mx_print_digit(n);        
    }
}

