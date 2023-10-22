#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    int test = 0;
    char *data;
    t_pathfinder *pathfinder;
    pathfinder = malloc(sizeof(t_pathfinder));
    pathfinder->isl_count = 0;
    pathfinder->path_count = 0;
    pathfinder->islands = NULL;
    pathfinder->paths = NULL;
    if (mx_file_errors(argc, argv))
        return 0;
    data = mx_read_data(argv[1]);
    if (data == NULL)
        return 0;

    test = mx_data_pathfinder(data, pathfinder);
    if (test > 0) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(test));
        mx_printerr(" is not valid \n");
        return 0;
    }
    free(data);
    return 0;
}

