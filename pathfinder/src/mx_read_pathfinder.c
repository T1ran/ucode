#include "../inc/pathfinder.h"

int mx_read_pathfinder(t_pathfinder *pathfinder, char *file) {
    int fd = open(file, O_RDONLY);
    char *data;
    char buf;
    int file_size = 0;

    if (fd == -1)
        return 1;
    while (read(fd, &buf, 1) > 0)
        ++file_size;
    mx_printint(file_size);
    if (file_size <= 1)
        return 2;

    data = mx_strnew(file_size); 
    close(fd);
    if (data == NULL)
        return 2;

    fd = open(file, O_RDONLY);
    if (read(fd, data, file_size) == -1) {
        free(data);
        close(fd);
        return 2;
    }

    data[file_size] = '\0';
    close(fd);
    
    return mx_data_pathfinder(pathfinder, data);
}

