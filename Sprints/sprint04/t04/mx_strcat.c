int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int i = 0;
    for (i = 0; i < mx_strlen(s1); i++);
    for (int j = 0; j < mx_strlen(s2); j++, i++) {
            s1[i] = s2[j];
        }
    s1[i] = '\0';   
    return s1;
}

