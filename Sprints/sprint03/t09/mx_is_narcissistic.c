#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
	int counter = 0;
	int temp = num;
	if (num < 0) {
		return false;
	}
	while (temp != 0) {
		temp /= 10;
		counter++;
	}
	temp = num;
	double result = 0;
	for (int i = counter; i > 0; i--) {
		int power = 1;		
		for (int k = i; k > 1; k--) {
			power *= 10;
		}		
		int digit = temp / power;		
		temp %= power;
		result += mx_pow(digit, counter);
	}
	if (result == num) {
		return true;
	}
	return false;
}


