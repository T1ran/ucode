#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int answer = 0;
    int in_word = 0;

    if (str == NULL) {
        return -1;
    }

    if (!mx_strcmp(str, "")) {
        return 0;
    }

    while (*str) {
        if (*str == c) {
            if (in_word)
                answer++;
            in_word = 0;
        } else {
            in_word = 1;
        }
        str++;
    }
    
    if (in_word)
        answer++;

    return answer;
}

