#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    double answer = 1;

    for (unsigned int i = 0; i < pow; ++i) {
        answer *= n;
    }

    return answer;
}

