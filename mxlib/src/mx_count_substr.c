#include "../inc/libmx.h"

int mx_count_substr(const char* str, const char* sub) {
    int answer = 0;
    int sub_len = 0;

    if (str == NULL || sub == NULL)
        return -1;

    while (sub[sub_len] != '\0')
        sub_len++;

    if (sub_len == 0)
        return 0;

    while (*str) {
        int match = 1;
        for (int i = 0; i < sub_len; i++) {
            if (*(str + i) != sub[i]) {
                match = 0;
                break;
            }
        }

        if (match)
            answer++;

        str++;
    }

    return answer;
}

