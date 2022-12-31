#include "../inc/list.h"

t_list *mx_create_node(void *data) {
    t_list *new_node = malloc(sizeof(t_list));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

void without_arg(int argc) {
	if (argc < 3 || argc > 5) {
		mx_printerr("usage: ./playlist [file] [command] [args]\n");
		exit(0);
	}
}

void error1(int fd) {
	if (fd < 0) {
		mx_printerr("ERROR\n");
		exit(0);
	}
}

void error2(int fd) {
	int close_fd = close(fd);
	if (close_fd < 0) {
		mx_printerr("ERROR\n");
		exit(0);
	}
	exit(0);
}

void mx_add(int argc, char *argv[]) {
	if (argc == 5) {
		if (mx_strcmp(argv[2], "add") == 0)	{
			int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
			error1(fd);
			write(fd, argv[3], mx_strlen(argv[3]));
			write(fd, " - ", 3);
			write(fd, argv[4], mx_strlen(argv[4]));
			write(fd, "\n", 1);
			error2(fd);
		}
	}
	mx_printerr("ERROR\n");

}

int main(int argc, char *argv[]) {
	without_arg(argc);
	mx_add(argc, argv);
}
	
