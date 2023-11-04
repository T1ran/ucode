#include "../inc/pathfinder.h"

long mx_atoi(const char *number) {
    int i = -1;
    long result = 0;

    while (number[++i]) {
        if (mx_isdigit(number[i]))
            result = result * 10 + number[i] - '0';
        if (!mx_isdigit(number[i]))
            return result;
    }
    return result;
}
