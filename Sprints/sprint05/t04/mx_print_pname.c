char *mx_strchr(const char *s, int c);
void mx_printstr(const char *s);
void mx_printchar(char c);
int main(int argc, char *argv[]) {
    if (argc > 0) {
        while (mx_strchr(argv[0], '/')) {
            argv[0]++;
        }
        mx_printstr(argv[0]);
        mx_printchar('\n');
	}
}

