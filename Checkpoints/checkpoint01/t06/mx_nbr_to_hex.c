#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size) {    
    if (size < 0) {
    	return NULL;
    }
    char *str = (char *) malloc((size + 1) * sizeof(char));
    if (str == NULL) {
    	return NULL;
    }    
    for (int i = 0; i <= size; i++) {
    	str[i] = '\0';
    }
    return str;
}

int count_nbr(unsigned long nbr) {
	int count = 0;
	while (nbr) {
		nbr /= 16;
		count++;
	}
	return count;
}

char *mx_nbr_to_hex(unsigned long nbr) {
	int count = count_nbr(nbr);
	char *result = mx_strnew(count);
	for (int j = count - 1; j >= 0; j--) {
		int n = nbr % 16;
		if (n < 10) {
			result[j] = n + 48;
		}
		else {
			result[j] = n + 87;
		}
		nbr /= 16;
		
	}
	return result;
} 


