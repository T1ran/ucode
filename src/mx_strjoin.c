#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char* answer;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);

    answer = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    if (answer == NULL)
        return NULL;

    mx_strcpy(answer, s1);
    mx_strcat(answer, s2);

    return answer;
}

