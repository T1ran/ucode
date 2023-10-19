#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = (unsigned char*)dst;
    const unsigned char *s = (const unsigned char *)src;
    unsigned char ch = (unsigned char)c;

    while (n-- > 0) {
        *d++ = *s++;
        if (*s == ch)
            return d;
    }

    return NULL;
}

