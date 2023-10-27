#include "../inc/pathfinder.h"

int mx_file_errors(int argc, char **argv) {
    if (argc != 2) {
        mx_print_error("usage: ./pathfinder [filename]\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_print_error("error: file ");
        mx_print_error(argv[1]);
        mx_print_error(" does not exist\n");
        return 1;
    }
    close(fd);
    return 0;
}

