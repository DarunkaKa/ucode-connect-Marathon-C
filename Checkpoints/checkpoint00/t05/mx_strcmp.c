int mx_strcmp(const char *s1, const char *s2) {
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s2++;
        s1++;
    }
    if (*s1 == *s2) {
        return 0;
    }
    return (*s1 - *s2);
}
