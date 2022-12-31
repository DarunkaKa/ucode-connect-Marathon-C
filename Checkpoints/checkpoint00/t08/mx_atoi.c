int mx_atoi(const char *str) {   
    int c = 0;
    int i = 0;
    if (str[0] == '-') {
        c = -1;
        i++;
    }
    int result = 0;
    for (int d = i; str[d] != '\0'; d++) {
        if (str[d] >= 48 && str[d] <= 57) {
            result = result * 10 + str[d] - '0';
        }
        else {
            break;
        }
        if ( str[d] == ' ' 
                 || str[d] == '\n'
                 || str[d] == '\r'
                 || str[d] == '\t'
                 || str[d] == '\f'
                 || str[d] == '\v') {
            break;         
        }    
    }
    return (c == -1) ? result *= -1 :result;
}

