#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr;

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, size);

    free(ptr);

    return new_ptr;
}

