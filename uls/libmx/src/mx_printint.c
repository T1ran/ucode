#include "../inc/libmx.h"

void mx_printint(int n) {
    char digits[10] = { 0 };
    int length = 0;

    if (n == 0)
        mx_printchar('0');
    if (n == MX_INT_MIN) {
        mx_printstr("-2147483648");
        return;
    }

    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    while (n != 0) {
        digits[length] += (n % 10 + 48);
        n /= 10;
        length++;
    }

    for (int i = length-1; i >= 0; i--)
        mx_printchar(digits[i]);
}

