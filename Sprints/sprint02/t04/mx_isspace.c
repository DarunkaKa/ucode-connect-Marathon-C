#include <stdbool.h>
#include <stdio.h>
bool mx_isspace(char c) {
	if (c == ' ' 
	    || c == '\n' 
	    || c == '\t' 
	    || c == '\v' 
	    || c == '\f' 
	    || c == '\r') {
		return true;
	}
	return false;
}

int main(){
printf("%i\n", mx_isspace(' ');
}

