#include "../inc/pathfinder.h"

char *mx_read_data(char *file) {
    int fd = open(file, O_RDONLY);
    char *data;
    char buf;
    int file_size = 0;

    while (read(fd, &buf, 1) > 0)
        ++file_size;
    if (file_size <= 1)
    {
        mx_print_error("error: file ");
        mx_print_error(file);
        mx_print_error(" is empty\n");
        return NULL;
    }
    data = mx_strnew(file_size); 
    close(fd);
    if (data == NULL)
        return NULL;
    fd = open(file, O_RDONLY);
    if (read(fd, data, file_size) == -1) {
        free(data);
        close(fd);
        return NULL;
    }

    data[file_size] = '\0';
    close(fd);

    return data;

}

