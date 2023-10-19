#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *answer;
    int temp = number;
    int len = 1;

    if (number == 0)
        return "0";
    if (number == MX_INT_MIN)
        return "-2147483648";

    while (temp != 0) {
        temp /= 10;
        len++;
    }

    len += number < 0 ? 1 : 0;
    answer = mx_strnew(len);

    if (number < 0) {
        answer[0] = '-';
        number *= -1;
    }

    answer[len - 1] = '\0';
    --len;

    while (number != 0) {
        answer[--len] = (number % 10) + '0';
        number /= 10;
    }

    return answer;
}

