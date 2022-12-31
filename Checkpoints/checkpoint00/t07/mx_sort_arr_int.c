void mx_sort_arr_int(int *arr, int size) {
    for (int k = 0; k < size; k++) {
        int elem_int = arr[k];
        int d = 0;
        for (d = k - 1; d >= 0 && arr[d] > elem_int; d--) {
            arr[d + 1] = arr[d];
        }
        arr[d + 1] = elem_int;
    }    
}

