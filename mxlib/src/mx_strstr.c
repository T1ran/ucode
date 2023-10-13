#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!*needle)
        return (char*)haystack;

    while (*haystack)
    {
        const char* temp_haystack = haystack;
        const char* temp_needle = needle;

        while (*temp_needle && *temp_haystack && (*temp_needle == *temp_haystack)) {
            temp_haystack++;
            temp_needle++;
        }

        if (*temp_needle == '\0')
            return (char*)haystack;

        haystack++;
    }

    return NULL;
}
