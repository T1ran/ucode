#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *answer;
    int len = 0;
    unsigned long temp = nbr;

    if (nbr == 0)
        return "0";

    while (temp != 0) {
        len++;
        temp /= 16;
    }
    answer = mx_strnew(len);

    for (int i = len - 1; i >= 0; --i) {
        unsigned int t = nbr % 16;

        if (t >= 10) {
            answer[i] = t + 87;
        } else {
            answer[i] = t + 48;
        }

        nbr /= 16;
    }

    return answer;
}

