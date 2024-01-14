#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int answer = 1;

    if (x <= 0) {
        return 0;
    }

    while (answer <= x) {
        if (answer == x / answer) {
            return answer;
        }
        if (answer > x / answer)
            break;
        answer++;
    }

    return 0;
}

