int mx_atoi(const char *str);
void mx_printint(int n);
int main(int argc, char *argv[]) {
    if (argc > 1) {
        int sum_args = 0;
        for (int i = 1; i < argc; i++) {
            sum_args += mx_atoi(argv[i]);
        }
        mx_printint(sum_args);
    }
}

