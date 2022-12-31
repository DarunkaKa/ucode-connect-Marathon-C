#include <time.h>
#include <stdlib.h>
double mx_timer(void (*f)()) {
	if (clock() < 0) {
		return -1;
	}
	if (*f == NULL) {
		return -1;
	}
	clock_t start = clock();
	f();
	clock_t end = clock();
	double total = (double)((end - start) / CLOCKS_PER_SEC);
	return total;
}
	
