int mx_atoi(const char *str);
void mx_printint(int n);
void mx_printchar(char c);
int main(int argc, char *argv[]) {
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			int digit = mx_atoi(argv[i]);
			for (int j = 31; j >= 0; j--) {
				((digit >> j) & 1) ? mx_printint(1) : mx_printint(0);
			}
			mx_printchar('\n');			
		}		
	}
}

