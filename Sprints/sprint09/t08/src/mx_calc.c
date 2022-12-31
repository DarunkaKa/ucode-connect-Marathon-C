#include "../inc/calculator.h"

void error_input(enum e_error error) {
	switch (error) {
		case DIV_BY_ZERO:
			mx_printerr("error: division by zero\n");
			break;
		case INCORRECT_OPERATION:
            mx_printerr("error: invalid operation\n");
            break;
		case INCORRECT_OPERAND:
            mx_printerr("error: invalid number\n");
            break;
        default:
        	break;
	}
	exit(-1);
}
        

int main(int argc, char *argv[]) {
	if (argc != 4) {
		mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
		exit(-1);
	}
	char *first = mx_strdup(argv[1]);
	char *two = mx_strdup(argv[3]);
	if ((mx_atoi(two) == 0) && (mx_strncmp(argv[2], "/", 1) == 0)) {
		error_input(DIV_BY_ZERO);
	}
	for (int i = 0; first[i] != '\0' && two[i] != '\0'; i++) {
		if (!mx_isdigit(first[i]) || ! mx_isdigit(two[i])) {
			error_input(INCORRECT_OPERAND);
		}
	}
	if (mx_strncmp(argv[2], "+", 1) != 0
		&& mx_strncmp(argv[2], "-", 1) != 0
		&& mx_strncmp(argv[2], "*", 1) != 0
		&& mx_strncmp(argv[2], "/", 1) != 0
		&& mx_strncmp(argv[2], "%", 1) != 0) {
		error_input(INCORRECT_OPERATION);
	}
	t_operation end;
	if (mx_strncmp(argv[2], "+", 1) == 0) {
		end.op = ADD;
	}
	if (mx_strncmp(argv[2], "-", 1) == 0) {
		end.op = SUB;
	}
	if (mx_strncmp(argv[2], "*", 1) == 0) {
		end.op = MUL;
	}
	if (mx_strncmp(argv[2], "/", 1) == 0) {
		end.op = DIV;
	}
	if (mx_strncmp(argv[2], "%", 1) == 0) {
		end.op = MOD;
	}
	switch (end.op) {
		case ADD:
			end.f = mx_add;
			break;
		case SUB:
            end.f = mx_sub;
            break;
		case MUL:
            end.f = mx_mul;
            break;
        case DIV:
            end.f = mx_div;
            break;
        case MOD:
            end.f = mx_mod;
            break;
        default:
        	break;
	}
	int number = end.f(mx_atoi(first), mx_atoi(two));
	mx_printint(number);
	mx_printchar('\n');
	exit(0);
}
	
