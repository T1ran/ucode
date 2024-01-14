#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int s1_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);
    int total_len = s1_len + s2_len;
    char *answer = mx_strnew(total_len);

    if (answer == NULL) {
        return NULL;
    }

    int i = 0;
    for (i = 0; i < s1_len; i++) {
        answer[i] = s1[i];
    }
    for (int j = 0; j < s2_len; j++) {
        answer[i + j] = s2[j];
    }

    answer[i + s2_len] = '\0';

    return answer;
}
