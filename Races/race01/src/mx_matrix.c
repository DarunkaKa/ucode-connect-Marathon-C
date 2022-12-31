#include "../inc/matrix.h"


int pow_two(int a, int b) {
	int result = 1;
	for (int x = 1; x <= b; x++) {
		result *= a;	
}
	if (b == 0) {
		return 0;
	}
return result;
}
 
int mx_str(char s, char i) {
	if (s == i) {
		return 0;
	}
	return -1;
}

void mx_print_result(int a, int b, char *c, int res) {
	mx_printint(a);
	mx_printchar(' ');
	mx_printstr(c);
	mx_printchar(' ');
	mx_printint(b);
	mx_printchar(' ');
	mx_printchar('=');
	mx_printchar(' ');
	mx_printint(res);
	mx_printchar('\n');
}

void error_usage(int n) {
	if (n != 5) {
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
		exit(-1);
	}	
}

void error_operation(char *oper, char *oper2) {
	if (mx_strncmp(oper, "-", 1) != 0
		&& mx_strncmp(oper, "+", 1) != 0
		&& mx_strncmp(oper, "*", 1) != 0
		&& mx_strncmp(oper, "/", 1) != 0
		&& mx_strncmp(oper, "?", 1) != 0) {
		mx_printerr("Invalid operation: ");
		mx_printerr(oper);
		mx_printerr("\n");
		exit(-1);
	}
	if ((int)*oper == 47 && *oper2 == '0') {
		exit(-1);
	}
}

void error_operand(char *oper1, char *oper2) {
	if (mx_atoi(oper1) == -1) {
		for (int i = 0; i < mx_strlen(oper1); i++) {
			if (mx_str(oper1[i], '?') == -1) {			
				mx_printerr("Invalid operand: ");
				mx_printerr(oper1);
				mx_printerr("\n");
				exit(-1);
			}
		}
	}
	if (mx_atoi(oper2) == -1) {
		for (int i = 0; i < mx_strlen(oper2); i++) {
			if (mx_str(oper2[i], '?') == -1) {			
				mx_printerr("Invalid operand: ");
				mx_printerr(oper2);
				mx_printerr("\n");
				exit(-1);
			}
		}
	}
}

void error_result(char *res) {
	if (mx_atoi(res) == -1){
		for (int i = 0; i < mx_strlen(res); i++) {
			if (mx_str(res[i], '?') == -1) {			
				mx_printerr("Invalid result: ");
				mx_printerr(res);
				mx_printerr("\n");
				exit(-1);
			}
		}
	}
}

void all_error(int n, char *oper1, char *oper, char *oper2, char *res) {
	error_usage(n);
	error_operation(oper, oper2);
	error_operand(oper1, oper2);
	error_result(res);
}

void one_plus_unknown(char *oper1, char *oper, char *oper2, char *res, int q1, int q2, int q_r) {
	if (mx_strncmp(oper, "+", 1) == 0) {
		if (q1 == 0 && q2 == 0 && q_r == -1) {
			mx_print_result(mx_atoi(oper1), mx_atoi(oper2), oper, mx_add(mx_atoi(oper1), mx_atoi(oper2)));
		}
		if (q1 == 0 && q2 == -1 && q_r == 0){
			mx_print_result(mx_atoi(res), mx_atoi(oper1), oper, mx_sub(mx_atoi(res), mx_atoi(oper1)));
		}
		if (q1 == -1 && q2 == 0 && q_r == 0) {
			mx_print_result(mx_sub(mx_atoi(res), mx_atoi(oper2)), mx_atoi(oper2), oper, mx_atoi(res));
		}
	}
}

void one_minus_unknown(char *oper1, char *oper, char *oper2, char *res, int q1, int q2, int q_r) {
	if (mx_strncmp(oper, "-", 1) == 0) {
		if (q1 == 0 && q2 == 0 && q_r == -1) {
			mx_print_result(mx_atoi(oper1), mx_atoi(oper2), oper, mx_sub(mx_atoi(oper1), mx_atoi(oper2)));
		}
		if (q1 == 0 && q2 == -1 && q_r == 0) {
			mx_print_result(mx_atoi(oper1), mx_atoi(res), oper, mx_sub(mx_atoi(oper1), mx_atoi(res)));
		}
		if (q1 == -1 && q2 == 0 && q_r == 0) {
			mx_print_result(mx_atoi(oper2), mx_atoi(res), oper, mx_add(mx_atoi(oper2), mx_atoi(res)));
		}
	}
}

void one_mul_unknown(char *oper1, char *oper, char *oper2, char *res, int q1, int q2, int q_r) {
	if (mx_strncmp(oper, "*", 1) == 0) {
		if (q1 == 0 && q2 == 0 && q_r == -1) {
			mx_print_result(mx_atoi(oper1), mx_atoi(oper2), oper, mx_mul(mx_atoi(oper1), mx_atoi(oper2)));
		}
		if (q1 == 0 && q2 == -1 && q_r == 0){
			mx_print_result(mx_atoi(res), mx_atoi(oper1), oper, mx_div(mx_atoi(res), mx_atoi(oper1)));
		}
		if (q1 == -1 && q2 == 0 && q_r == 0) {
			mx_print_result(mx_atoi(res), mx_atoi(oper2), oper, mx_div(mx_atoi(res), mx_atoi(oper2)));
		}
	}
}

void one_div_unknown(char *oper1, char *oper, char *oper2, char *res, int q1, int q2, int q_r) {
	if (mx_strncmp(oper, "/", 1) == 0) {
		if (q1 == 0 && q2 == 0 && q_r == -1) {
			mx_print_result(mx_atoi(oper1), mx_atoi(oper2), oper, mx_div(mx_atoi(oper1), mx_atoi(oper2)));
		}
		if (q1 == 0 && q2 == -1 && q_r == 0) {
			mx_print_result(mx_atoi(res), mx_atoi(oper1), oper, mx_div(mx_atoi(res), mx_atoi(oper1)));
		}
		if (q1 == -1 && q2 == 0 && q_r == 0) {
			
			if (mx_atoi(oper2) > 1) {
				for (int i = mx_mul(mx_atoi(oper2), mx_atoi(res)); i < (mx_mul(mx_atoi(oper2), mx_atoi(res)) + mx_atoi(oper2)); i++) {
					mx_print_result(i, mx_atoi(oper2), oper, mx_div(i, mx_atoi(oper2)));
				}
			}
		}
	}
}

void one_unknown(char *oper1, char *oper, char *oper2, char *res) {
	int q1 = 0;
	int q2 = 0;
	int q_r = 0;	
	for (int i = 0; i < mx_strlen(oper1); i++) {
		if (oper1[i] == '?') {
			q1 = -1;
		}
	}
	for (int i = 0; i < mx_strlen(oper2); i++) {
		if (oper2[i] == '?') {
			q2 = -1;
		}
	}
	for (int i = 0; i < mx_strlen(res); i++) {
		if (res[i] == '?') {
			q_r = -1;
		}
	}
	one_plus_unknown(oper1, oper, oper2, res, q1, q2, q_r);
	one_minus_unknown(oper1, oper, oper2, res, q1, q2, q_r);
	one_mul_unknown(oper1, oper, oper2, res, q1, q2, q_r);
	one_div_unknown(oper1, oper, oper2, res, q1, q2, q_r);	
}

void two_plus1(int q1, int q2, int q_r, int number_q1, int number_q2, int r, char *oper) {
	if (q1 == 1 && q2 == 1 && q_r == 0) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q2); j++) {
					if (j >= pow_two(10, number_q2 - 1)){
						if (mx_add(i, j) == r) {
							mx_print_result(i, j, oper, r);
						}
					}
				}
			}
		}
	}
}

void two_plus2(int q1, int q2, int q_r, int opr1, int number_q2, int number_q_r, char *oper) {
	if (q1 == 0 && q2 == 1 && q_r == 1){
		for (int i = 0; i < pow_two(10, number_q2); i++) {
			if (i >= pow_two(10, (number_q2 - 1)) && i <= pow_two(10, number_q2)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1)){
						if (mx_add(opr1, i) == j) {
							mx_print_result(opr1, i, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_plus3(int q1, int q2, int q_r, int number_q1, int opr2, int number_q_r, char *oper) {
	if (q1 == 1 && q2 == 0 && q_r == 1) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1)){
						if (mx_add(i, opr2) == j) {
							mx_print_result(i, opr2, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_minus1(int q1, int q2, int q_r, int number_q1, int number_q2, int r, char *oper) {
	if (q1 == 1 && q2 == 1 && q_r == 0) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q2); j++) {
					if (j >= pow_two(10, number_q2 - 1)) {
						if (mx_sub(i, j) == r) {
								mx_print_result(i, j, oper, r);
						}
					}
				}
			}
		}
	}
}

void two_minus2(int q1, int q2, int q_r, int number_q2, int number_q_r, int opr1, char *oper) {
	if (q1 == 0 && q2 == 1 && q_r == 1) {
		for (int i = 0; i < pow_two(10, number_q2); i++) {
			if (i >= pow_two(10, (number_q2 - 1)) && i <= pow_two(10, number_q2)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1)) {
						if (mx_sub(opr1, i) == j) {
							mx_print_result(opr1, i, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_minus3(int q1, int q2, int q_r, int number_q1, int number_q_r, int opr2, char *oper) {
	if (q1 == 1 && q2 == 0 && q_r == 1) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1)) {
						if (mx_sub(i, opr2) == j) {
							mx_print_result(i, opr2, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_mul1(int q1, int q2, int q_r, int number_q1, int number_q2, int r, char *oper) {
	if (q1 == 1 && q2 == 1 && q_r == 0) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q2); j++) {
					if (j >= pow_two(10, number_q2 - 1) || j == 0) {
						if (mx_mul(i, j) == r) {
							mx_print_result(i, j, oper, r);
						}
					}
				}
			}
		}
	}
}

void two_mul2(int q1, int q2, int q_r, int number_q2, int number_q_r, int opr1, char *oper) {
	if (q1 == 0 && q2 == 1 && q_r == 1){
		for (int i = 0; i < pow_two(10, number_q2); i++) {
			if (i >= pow_two(10, (number_q2 - 1)) && i <= pow_two(10, number_q2)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1) || j == 0) {
						if (mx_mul(opr1, i) == j) {
							mx_print_result(opr1, i, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_mul3(int q1, int q2, int q_r, int number_q1, int number_q_r, int opr2, char *oper) {
	if (q1 == 1 && q2 == 0 && q_r == 1) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {				
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1) || j == 0) {
						if (mx_mul(i, opr2) == j) {						
							mx_print_result(i, opr2, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_div1(int q1, int q2, int q_r, int number_q1, int number_q2, int r, char *oper) {
	if (q1 == 1 && q2 == 1 && q_r == 0) {
		for (int i = 0; i < pow_two(10, number_q1); i++) {				
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q2); j++) {
					if (j >= pow_two(10, number_q2 - 1) || j == 0) {
						if (mx_div(i, j) == r) {						
							mx_print_result(i, j, oper, r);
						}
					}
				}
			}
		}
	}
}

void two_div2(int q1, int q2, int q_r, int number_q2, int number_q_r, int opr1, char *oper) {
	if (q1 == 0 && q2 == 1 && q_r == 1) {
		for (int i = 0; i < pow_two(10, number_q2); i++) {				
			if (i >= pow_two(10, (number_q2 - 1)) && i <= pow_two(10, number_q2)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1) || j == 0) {
						if (mx_div(opr1, i) == j) {						
							mx_print_result(opr1, i, oper, j);
						}
					}
				}
			}
		}
	}
}

void two_div3(int q1, int q2, int q_r, int number_q1, int number_q_r, int opr2, char *oper) { 
	if (q1 == 1 && q2 == 0 && q_r == 1) {			
		for (int i = 0; i < pow_two(10, number_q1); i++) {				
			if (i >= pow_two(10, (number_q1 - 1)) && i <= pow_two(10, number_q1)) {
				for (int j = 0; j < pow_two(10, number_q_r); j++) {
					if (j >= pow_two(10, number_q_r - 1) || j == 0) {
						if (mx_div(i, opr2) == j) {						
							mx_print_result(i, opr2, oper, j);
						}
					}
				}
			}
		}
	}
}		
		
void two_unknown(char *oper1, char *oper, char *oper2, char *res) {
	int q1 = 0;
	int q2 = 0;
	int q_r = 0;
	int number_q1 = 0;
	int number_q2 = 0;
	int number_q_r = 0;
	for (int i = 0; i < mx_strlen(oper1); i++) {
		if (oper1[i] == '?') {
			q1 = 1;
			number_q1++;
		}
	}
	for (int i = 0; i < mx_strlen(oper2); i++) {
		if (oper2[i] == '?') {
			q2 = 1;
			number_q2++;
		}
	}
	for (int i = 0; i < mx_strlen(res); i++) {
		if (res[i] == '?') {
			q_r = 1;
			number_q_r++;
		}
	}
	int opr1 = mx_atoi(oper1);
	int opr2 = mx_atoi(oper2);
	int r = mx_atoi(res);
	if (mx_strncmp(oper, "+", 1) == 0) {
		two_plus1(q1, q2, q_r, number_q1, number_q2, r, oper);
		two_plus2(q1, q2, q_r, opr1, number_q2, number_q_r, oper);
		two_plus3(q1, q2, q_r, number_q1, opr2, number_q_r, oper);
	}	
	if (mx_strncmp(oper, "-", 1) == 0) {
		two_minus1(q1, q2, q_r, number_q1, number_q2, r, oper);
		two_minus2(q1, q2, q_r, number_q2, number_q_r, opr1, oper);
		two_minus3(q1, q2, q_r, number_q1, number_q_r, opr2, oper);
	}	
	if (mx_strncmp(oper, "*", 1) == 0) {
		two_mul1(q1, q2, q_r, number_q1, number_q2, r, oper);
		two_mul2(q1, q2, q_r, number_q2, number_q_r, opr1, oper);
		two_mul3(q1, q2, q_r, number_q1, number_q_r, opr2, oper);
	}	
	if (mx_strncmp(oper, "/", 1) == 0) {
		two_div1(q1, q2, q_r, number_q1, number_q2, r, oper);
		two_div2(q1, q2, q_r, number_q2, number_q_r, opr1, oper);
		two_div3(q1, q2, q_r, number_q1, number_q_r, opr2, oper);
	}	
}  

int main(int argc, char *argv[]) {
	char *oper1 = mx_strtrim(argv[1]);
	char *oper = mx_strtrim(argv[2]);
	char *oper2 = mx_strtrim(argv[3]);
	char *res = mx_strtrim(argv[4]);
	all_error(argc, oper1, oper, oper2, res);
	one_unknown(oper1, oper, oper2, res);
	two_unknown(oper1, oper, oper2, res);
}
	
	
