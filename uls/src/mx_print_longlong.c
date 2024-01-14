#include "../inc/uls.h"

void mx_printlonglong(long long n) {
    if (n == LLONG_MIN) {
        write(STDOUT_FILENO, "-9223372036854775808", 20);
        return;
    }

    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    if (n > 9) {
        mx_printlonglong(n / 10);
    }

    mx_printchar(n % 10 + '0');
}

