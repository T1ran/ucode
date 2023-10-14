#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char* dst_original = dst;

    while (len > 0 && *src != '\0') {
        *dst++ = *src++;
        len--;
    }

    while (len > 0) {
        *dst++ = '\0';
        len--;
    }

    return dst_original;
}

