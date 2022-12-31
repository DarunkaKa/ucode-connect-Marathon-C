#include <stdio.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {

    if (size <= 0 || src == NULL) return NULL;

    int *new_array = (int *)malloc(sizeof(int) * size);

    for (int k = 0; k < size; k++)
        new_array[k] = src[k];

    return new_array;
}

