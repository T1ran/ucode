#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *answer;
    size_t len = mx_strlen(s1);

    if(s1 == NULL || n == 0)
        return NULL;

    if(len > n)
        len = n;
    
    answer = (char*)malloc(len+1);

    mx_strncpy(answer, s1, len);
    answer[len] = '\0';

    return answer;
}

