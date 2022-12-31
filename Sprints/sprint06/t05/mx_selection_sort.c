int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_selection_sort(char **arr, int size) {
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (mx_strlen(arr[min_index]) > mx_strlen(arr[j])
				|| (mx_strlen(arr[min_index]) == mx_strlen(arr[j])
				&& mx_strcmp(arr[min_index], arr[j]) > 0)) {
				min_index = j;
			}
		}
		if (min_index != i) {
			char *swap = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = swap;
			count++;
		}
	}
	return count;
}

