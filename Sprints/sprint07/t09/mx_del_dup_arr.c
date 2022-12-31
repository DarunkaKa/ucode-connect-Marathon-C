#include <stdlib.h>
#include <stdio.h>
int *mx_copy_int_arr(const int *src, int size);
int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
	if (src == NULL) {
		return NULL;
	}
	for (int i = 0; i < src_size; i++) {
    	for (int j = i + 1; j < src_size; j++) {
        	if (src[i] == src[j]) {
            	for (int k = j; k < src_size - 1; k++) {  
                    src[k] = src[k + 1];  
                }
                src_size--;
                j--;      
            }  
        }  
    }  
    int *new_arr = mx_copy_int_arr(src, *dst_size);
    return new_arr;
}

