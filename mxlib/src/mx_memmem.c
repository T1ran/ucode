#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,size_t little_len) {
    const unsigned char *b;
    const unsigned char *l;
    size_t last = big_len - little_len;

    if (!little || !big)
        return NULL;

    b = (const unsigned char*)big;
    l = (const unsigned char*)little;

    for (size_t i = 0; i < last; ++i) {
        if (!mx_memcmp(b + i, l, little_len))
            return (void *)(b + i);
    }

    return NULL;
}

