void mx_printchar(char c);

void mx_printint(int n) {
	if (n < 0) {
		mx_printchar('-');
		n = -n;
	}
	int counter = 0;
	int temp = n;
	while (temp != 0) {
		temp /= 10;
		counter++;
	}	
	for (int i = counter; i > 0; i--) {
		int power = 1;		
		for (int k = i; k > 1; k--) {
			power *= 10;
		}		
		int digit = n / power;		
		n %= power;
		mx_printchar(digit + 48);
	}	
	mx_printchar('\n');	
}	

