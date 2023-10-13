#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int answer = 0;
    
    while (s[answer] != '\0') {
        ++answer;
    }

    return answer;
}

