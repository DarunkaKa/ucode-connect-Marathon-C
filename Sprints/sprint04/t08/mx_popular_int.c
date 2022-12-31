int mx_popular_int(const int *arr, int size) {
    int count = 0;
    int max_element = 0;
    int number = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size;) {    
            if (arr[i] == arr[j++]) {
                count += 1;    
                if (count > max_element) {
                    max_element = count;
                    number = arr[i];
                }   
            }
        }
    }
    return number;
}

