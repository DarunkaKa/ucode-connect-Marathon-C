int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
int main( int argc, char *argv[]) {
	if (argc == 3) {
		int min_elem = mx_atoi(argv[1]);
		int max_elem = mx_atoi(argv[2]);
		if (min_elem < 0 
			|| max_elem < 0
			|| min_elem > 9
			|| max_elem > 9) {
			return 0;
		}
		if (min_elem > max_elem) {
			max_elem = min_elem;
			min_elem = mx_atoi(argv[2]);
		}
		for (int i = min_elem; i <= max_elem; i++) {
			for (int j = min_elem; j <= max_elem; j++) {
				mx_printint(i * j);
				if (j != max_elem) {
					mx_printchar('\t');
				}
			}
			mx_printchar('\n');	
		}			
	}
	else {
		return 0;
	}
}
				
		
