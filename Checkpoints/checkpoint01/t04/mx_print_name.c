#include <stdio.h>
#include <unistd.h>

int mx_strlen(const char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

void mx_printchar(char c) {
	write(1, &c, 1);
}

void mx_printint(int n) {
    long int number = 0;
    long int temp = (long int)n;
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    }
    else {
	    if (n < 0) {
		write(1, "-", 1);
		n *= -1;
	    }
	    else if (n == 0) {
		write(1, "0", 1);
	    } 
	    while (temp != 0) {
		temp /= 10;
		number++;
	    }
	    for (long int i = number; i > 0; i--) {
		long int power = 1;
		for (long int k = i; k > 1; k--) {
		    power *= 10;
		}		
		long int digit = n / power;		
		n %= power;
		mx_printchar(digit + 48);
	    }
    }
    write(1, "\n", 1);
}

int main(int argc, char *argv[]) {
    write(1, argv[0], mx_strlen(argv[0]));
    write(1, "\n", 1);
    mx_printint(argc);
}    

    
