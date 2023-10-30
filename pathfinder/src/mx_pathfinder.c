#include "../inc/pathfinder.h"

void mx_pathfinder(int argc, char **argv) {
    char *text_data;
    char *test;
    t_pathfinder *pathfinder = mx_create_pathfinder();
    if (mx_file_errors(argc, argv)) {
        mx_delete_pathfinder(pathfinder);
        return;
    }
    text_data = mx_read_data(argv[1]);
    if (text_data == NULL) {
        mx_delete_pathfinder(pathfinder);
        return;
    }
    test = mx_itoa(mx_gen_pathfinder(pathfinder, text_data));
    if (test[0] != '0') {
        mx_print_error("error: line ");
        mx_print_error(test);
        mx_print_error(" is not valid\n");
        free(text_data);
        free(test);
        mx_delete_pathfinder(pathfinder);
        return;
    }
    free(text_data);
    if (pathfinder->islands_count != pathfinder->real_islands_count) {
        mx_print_error("error: invalid number of islands\n");
        mx_delete_pathfinder(pathfinder);
        return;
    }
    if (mx_check_paths(pathfinder)) {
        mx_delete_pathfinder(pathfinder);
        return;
    }
    mx_gen_matrix(pathfinder);
    mx_calc_pathfinder(pathfinder);
    mx_print_result(pathfinder);
    mx_delete_pathfinder(pathfinder);
}

