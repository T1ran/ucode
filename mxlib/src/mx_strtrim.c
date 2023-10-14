#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    char *answer;
    int start = 0;
    int end = mx_strlen(str) - 1;

    if (str == NULL)
        return NULL;

    while (mx_isspace(str[start]))
        start++;
    while (end > start && mx_isspace(str[end]))
        end--;

    answer = mx_strnew(end - start + 1);

    mx_strncpy(answer, &str[start], end - start +1);

    return answer;
}

