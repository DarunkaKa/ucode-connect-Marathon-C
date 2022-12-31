#include <unistd.h>

void mx_printchar(char c);

void mx_horizontal_edge(int n) {
    mx_printchar('+');

    for (int i = 0; i < n * 2; i++)
        mx_printchar('-');

    mx_printchar('+');
}

void mx_print_space(int n) {
    for (int j = 0; j < n; j++)
        mx_printchar(' ');
}

void mx_n2_printchar(char s, int space) {
    mx_printchar(s);
    mx_print_space(space * 2);
    mx_printchar(s);
}

void mx_symbol_and_new_line(char symbol) {
    mx_printchar(symbol);
    mx_printchar('\n');
}

void mx_cube(int n) {

    if (n > 1) {
        mx_print_space(n / 2 + 1);
        mx_horizontal_edge(n);
        mx_printchar('\n');


        for (int k = 0; k < n / 2; k++) {
            mx_print_space(n / 2 - k);
            mx_n2_printchar('/', n);
            mx_print_space(k);
            mx_symbol_and_new_line('|');
        }

        mx_horizontal_edge(n);
        mx_print_space(n / 2);
        mx_symbol_and_new_line('|');
        
        int temp = (n % 2 == 0) ? 0 : 1;

        for (int p = 0; p <= n / 2 + temp; p++) {
            mx_n2_printchar('|', n);
            mx_print_space(n / 2);
            if (p == n / 2 - 1 + temp) {
                mx_symbol_and_new_line('+');
                break;
            }
            mx_symbol_and_new_line('|');
        }

        for (int s = 0; s < n / 2; s++) {
            mx_n2_printchar('|', n);
            mx_print_space(n / 2 - 1 - s);
            mx_symbol_and_new_line('/');
        }
        mx_horizontal_edge(n);
    }
    mx_printchar('\n');
}

//int main(){
//	mx_cube(12);
//}

