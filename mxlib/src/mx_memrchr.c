#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char* src = (const unsigned char*)s + n - 1;

    while (n-- > 0) {
        if (*src == c)
            return (void *)src;
        src--;
    }

    return NULL;
}

