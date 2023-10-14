#include "../inc/libmx.h"

char* mx_strcat(char* restrict s1, const char* restrict s2) {
    char *answer = s1;

    while (*s1)
        s1++;

    while (*s2)
        *s1++ = *s2++;

    return answer;
}
