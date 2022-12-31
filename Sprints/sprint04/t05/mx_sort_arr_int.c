void mx_sort_arr_int(int *arr, int size) {
    int i;
    int j;
    for (i = 0; i < size; i++) {
        int element = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > element; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = element;
    }    
}


