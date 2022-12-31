#include <stdbool.h>
bool mx_is_prime(int num);
double mx_pow(double n, unsigned int pow);
bool mx_is_mersenne(int n) {
	for (int i = 2; i <= n; i++) {
		if (mx_is_prime(i)) {
			double number = mx_pow(2, i) - 1;
			if (number == n) {
				return true;
			}
		}
		else if (n <= 0) {
			return false;
		}
	}
	return false;
}


