void mx_printchar(char c);
void mx_head_pyramid(int n);
void mx_top_body_pyramid(int n, int k);
void mx_bottom_body_pyramid(int n, int d);
void mx_bottom_pyramid(int n);

void mx_pyramid(int n) {
    if (n <= 0 || n % 2 != 0) {
        mx_printchar('\n');
    }
    else {
        mx_head_pyramid(n);
        int k;
        for (k = 0; k < (n / 2) - 1; k++) {
            mx_top_body_pyramid(n, k);
        }
        for (int d = n - k; d < n; d++) {
            mx_bottom_body_pyramid(n, d);
        }
        mx_bottom_pyramid(n);		
    }	
}

//int main() {
//    mx_pyramid(12);
//}

void mx_head_pyramid(int c) {
    for (int i = 1; i <= c; i++) {
        if (i == c) {
            mx_printchar('/');
            for (int k = 0; k < c / 2; k++) {
                mx_printchar('\\');
                break;
            }
            break;
        }
        mx_printchar(' ');
    }
    mx_printchar('\n');
}

void mx_top_body_pyramid(int n, int k) {
    for (int i = 1; i < n - 1 - k; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    for (int i = 0; i < k * 2 + 1; i++) {
        mx_printchar(' ');
    }
    mx_printchar('\\');
    for (int i = 0; i < k + 1; i++) {
        mx_printchar(' ');
    }
    mx_printchar('\\');
    mx_printchar('\n');
}

void mx_bottom_body_pyramid(int n, int k) {
    for (int i = 1; i <= n - k; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    for (int i = 0; i < k * 2 - 3; i++) {
        mx_printchar(' ');
    }
    mx_printchar('\\');
    for (int i = n - k; i > 0; i--) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');
}			

void mx_bottom_pyramid(int n) {
    mx_printchar('/');
    for (int i = 0; i < 2 * n - 3; i++) {
        mx_printchar('_');
    }
    mx_printchar('\\');
    mx_printchar('|');
    mx_printchar('\n');
}


