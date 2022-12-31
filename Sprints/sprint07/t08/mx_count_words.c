int mx_count_words(const char *str, char delimiter) {
    int i = 0;
    int count_words = 0;
    if (str[i] != delimiter && str[i] != '\0') {
        count_words += 1;
    }
    for (int i = 1; str[i + 1] != '\0'; i++) {
        if (str[i] == delimiter && str[i + 1] != delimiter) {   
            count_words += 1;
        }
    }
    return count_words;    
}

