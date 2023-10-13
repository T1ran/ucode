#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *str1 = (const unsigned char*)s1;
    const unsigned char *str2 = (const unsigned char*)s2;

    while (n-- > 0) {
        if (*str1 != *str2)
            return *str1 - *str2;

        str1++;
        str2++;
    }

    return 0;
}
