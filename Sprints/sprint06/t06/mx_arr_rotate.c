void mx_arr_rotate(int *arr, int size, int shift) {
	if (shift < 0) {
		shift += size;
	}
	for (int i = 0; i < shift; i++) {	
		int last = arr[size - 1];
		int j;
		for (j = size - 1; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = last;
	}
}

