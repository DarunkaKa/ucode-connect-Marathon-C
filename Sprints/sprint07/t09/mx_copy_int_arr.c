#include <stdlib.h>
#include <stdio.h>
int *mx_copy_int_arr(const int *src, int size) {
	int *arr_int = (int *)malloc(sizeof(int) * size);
	if (src == NULL || arr_int == NULL || size < 0) {
		return NULL;
	}	
	for (int i = 0; i < size; i++) {
		arr_int[i] = src[i];
	}
	return arr_int;
}

