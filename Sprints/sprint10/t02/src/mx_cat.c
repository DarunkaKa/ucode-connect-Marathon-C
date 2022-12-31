#include "../inc/header.h"

void without_arg(int argc) {
	if (argc == 1) {
		char element;
		while (read(0, &element, 1)) {
			write(1, &element, 1);
		}
		exit(0);
	}
}

void error1(int fd, int n, char *argv[]) {
	if (fd < 0) {
		mx_printerr("mx_cat: ");
		mx_printerr(argv[n]);
		mx_printerr(": No such file or directory\n");
		exit(-1);
	}
}

void error2(int fd) {
	int close_fd = close(fd);
	if (close_fd < 0) {
		mx_printerr("error\n");
		exit(-1);
	}
	exit(0);
}

int main(int argc, char *argv[]) {
	without_arg(argc);	
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);
		error1(fd, i, argv);
		char element;
		while (read(fd, &element, 1) != 0) {
			write(1, &element, 1);
		}
		error2(fd);
	}
}		
