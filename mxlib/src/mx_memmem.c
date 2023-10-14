#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,size_t little_len) {
    const unsigned char *b = (const unsigned char*)big;
    const unsigned char *l = (const unsigned char*)little;
    size_t last = big_len - little_len;

    for (size_t i = 0; i < last; ++i) {
        if (!mx_memcmp(b + i, l, little_len))
            return (void *)(b + i);
    }
    
    return NULL;
}

