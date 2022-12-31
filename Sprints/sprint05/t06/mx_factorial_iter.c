int mx_factorial_iter(int n) {
    if (n < 0) {
        return 0;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        if (result > 2147483647 / i) {
            return 0;
        }
        result *= i;
    }
    return result;
}

