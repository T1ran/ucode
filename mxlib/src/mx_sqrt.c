#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int answer = 1;

    if (x <= 0) {
        return 0;
    }

    while (answer <= x) {
        if (answer * answer == x) {
            return answer;
        }
        answer++;
    }

    return 0;
}

