int mx_strlen(const char *s);
int mx_insertion_sort(char **arr, int size) {
	int count = 0;
    for (int i = 0; i < size; i++) {
    	char *element = arr[i];
        int j;
        for (j = i - 1; (j >= 0 
        	&& mx_strlen(arr[j]) > mx_strlen(element)); 
        	j--) {
            arr[j + 1] = arr[j];
            count++;
        }
        arr[j + 1] = element;
    }
    return count;    
}

