#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int answer = 0;

    while (*s1 != '\0'
           && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    answer = ((unsigned char)(*s1) - (unsigned char)(*s2));
    /*if (answer < 0)
        return -1;
    if (answer > 0)
        return 1;
    */

    return answer;
}

