#include "../inc/header.h"

void error1(int argc) {
	if (argc != 3) {
		mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
		exit(-1);
	}
}

void fd1_or_fd2(int n, char *argv[]) {
	if (n == 2) {
		mx_printerr(argv[1]);
	}
	else if (n == 3) {
		mx_printerr(argv[2]);
	}
}

void error2(int fd, int n, char *argv[]) {
	if (fd < 0) {
		mx_printerr("mx_cp: ");
		fd1_or_fd2(n, argv);
		mx_printerr(": No such file or directory\n");
		exit(-1);
	}
}

void error3(int fd) {
	int close_fd = close(fd);
	if (close_fd < 0) {
		mx_printerr("error\n");
		exit(-1);
	}
	exit(0);
}

int main(int argc, char *argv[]) {
	error1(argc);
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IWUSR | S_IRUSR); 
	error2(fd1, 2, argv);
	char element;
	while (read(fd1, &element, 1) != 0) {
		write(fd2, &element, 1);
	}
	error3(fd1);
	error3(fd2);
}	
		
