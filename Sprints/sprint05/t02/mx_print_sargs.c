void mx_printstr(const char *s);
void mx_printchar(char c);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int j = 1; j + 1 <= argc - 1; j++) {            
            for (int i = j + 1; i + 1 <= argc; i++) {
                char *element = argv[j];
                if (mx_strcmp(argv[j], argv[i]) > 0) {                        
                    argv[j] = argv[i];
                    argv[i] = element;
                }
            }
        }
        for (int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    }
}

