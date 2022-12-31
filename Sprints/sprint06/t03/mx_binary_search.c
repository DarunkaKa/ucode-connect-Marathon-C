int mx_strcmp(const char *s1, const char *s2);
int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int f = 0;
	int l = size - 1;
	while (l >= f) {
		int mid = f + (l - f) / 2;
		(*count)++;			
		if (mx_strcmp(arr[mid], s) == 0) {				
			return mid;
		}
		else if (mx_strcmp(arr[mid], s) > 0) {
			l = mid - 1;
		}
		else {
			f = mid + 1;
		}		
	}
	*count = 0;
	return -1;
}

