#include "../inc/header.h"

void mx_wc_print(int string, int words, int number_char, int argc, char *arr) {
	mx_printchar('\t');
	mx_printint(string);
	mx_printchar('\t');
	mx_printint(words);
	mx_printchar('\t');
	mx_printint(number_char);
	if (argc > 2) {
		mx_printchar('\t');
		mx_printstr("total");
		mx_printchar('\n');
	}
	if (argc == 1) {
		mx_printchar('\n');
	}
    if (argc == 2) {
    	mx_printchar('\t');
		mx_printstr(arr);
		mx_printchar('\n');
    }
}


void error1(int fd, char *arr) {
	if (fd < 0) {
		mx_printerr("mx_wc: ");
		mx_printerr(arr);
		mx_printerr(": open: ");
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(-1);
	}
}

void error2(int fd, char *arr) {
	char element;
	if (read(fd, &element, 1) < 0) {
		mx_printerr("mx_wc: ");
		mx_printerr(arr);
		mx_printerr(": read: ");
		mx_printerr(strerror(errno));
		mx_printerr("\n");
		exit(-1);
	}
}

void error3(int fd) {
	if (close(fd) < 0) {
		exit(-1);
	}
}

int main(int argc, char *argv[]) {
	int total_string = argc - 1;
	int total_words = 0;
	int total_number_char = 0;	
	if (argc == 1) {
		int string = 1;
		int words = 0;
		int number_char = 0;
		char element;
		char element1;		
		while (read(0, &element, 1)) {
			if (mx_isspace(element)) {
				string++;
			}
			if (mx_isspace(element) && !mx_isspace(element1)) {
				words++;
			}
			number_char++;
			element1 = element;
		}
		mx_wc_print(string, words, number_char, argc, argv[0]);
		exit(0);
	}
	else if (argc >= 2) {		
		for (int i = 1; i < argc; i++) {
			int string = 1;
			int words = 0;
			int number_char = 0;
			char element;
			char element1;
			int fd = open(argv[i], O_RDONLY);
			error1(fd, argv[i]);
			error2(fd, argv[i]);
			error3(fd);
			int fd1 = open(argv[i], O_RDONLY);
			while (read(fd, &element, 1)) {
				if (element == '\n') {
					total_string++;
					string++;
				}
				if (mx_isspace(element) && !mx_isspace(element1)) {
					total_words++;
					words++;
				}
				total_number_char++;
				number_char++;
				element1 = element;
			}
			if (mx_isspace(element1)) {
				total_string--;
				string--;
        	}
        	else if (!mx_isspace(element1)) {
            	total_string++;
				string++;
        	}
        	error3(fd1);
        	mx_wc_print(string, words, number_char, 2, argv[i]);
        }
	}
	if (argc == 2) {
        	exit(0);
        }
  	if (argc > 2) {
		mx_wc_print(total_string, total_words, total_number_char, 3, argv[0]);
		exit(0);
	}			
}		
