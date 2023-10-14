#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    char* answer = NULL;
    char buffer;
    int file_size = -1;
    int descriptor = open(file, O_RDONLY);

    if (descriptor == -1)
        return NULL;
    while (read(descriptor, &buffer, 1) > 0)
        file_size++;
    if (file_size <= 0)
        return NULL;

    answer = mx_strnew(file_size);
    close(descriptor);
    if (answer == NULL)
        return NULL;

    descriptor = open(file, O_RDONLY);
    if (read(descriptor, answer, file_size) == -1) {
        free(answer);
        close(descriptor);
        return NULL;
    }

    answer[file_size] = '\0';
    close(descriptor);

    return answer;
}

