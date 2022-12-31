double mx_pow(double n, unsigned int pow) {
	double number = 1;
	for (unsigned int i = 1; i <= pow; i++) {
		number = number * n;
	}
	return number;
}

