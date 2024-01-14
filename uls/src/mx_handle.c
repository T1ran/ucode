#include "../inc/uls.h"

void mx_handle_files(int argc, char *argv[], bool flag_l, int flags_count) {
    struct stat path_stat;
    char **argv_sorted = NULL;
    int argv_count = 0;
    int i = 0;
    bool error = false;

    if (flag_l) {
        argv_count = argc - flags_count - 1;
        i = flags_count + 1;
    } else {
        argv_count = argc - 1;
        i = 1;
    }
    argv_sorted = (char **)malloc((argv_count) * sizeof(char *));
    for (int j = 0; i < argc; j++) {
        argv_sorted[j] = argv[i];
        i++;
    }
    mx_sort(argv_count, argv_sorted);
    for (int i = 0; i < argv_count; i++) {
        if ((stat(argv_sorted[i], &path_stat) == -1)) {
            mx_print_error("uls: ");
            mx_print_error(argv_sorted[i]);
            mx_print_error(": ");
            mx_print_error(strerror(errno));
            mx_print_error_char('\n');
            error = true;
        }
    }
    int files_count = mx_process_files(argv_count, argv_sorted, flag_l);
    mx_process_dir(argv_count, argv_sorted, files_count, error, flag_l);
    free(argv_sorted);
}

void mx_handle_long(char **path, int files_count, bool print) {
    struct stat info;
    int spaces[4] = {-1, -1, -1, -1};

    if (print)
        mx_output_blocks(path, files_count);
    mx_spaces(path, files_count, spaces);
    for (int i = 0; i < files_count; i++) {
        mx_output_info(&info, path[i], spaces, print);
    }
}

void mx_handle_long_dir(char **path,
                        int dir_count,
                        int files_count,
                        bool error) {
    bool print = false;
    if (files_count > 0 || dir_count > 1 || error)
        print = true;
    for (int i = 0; i < dir_count; i++) {
        DIR *dir = opendir(path[i]);
        if (i != 0 || files_count > 0)
            mx_printchar('\n');
        if (print) {
            mx_printstr(path[i]);
            mx_printstr(":\n");
        }
        bool is_open = true;
        if (mx_is_dir(path[i])) {
            DIR *dir_open = opendir(path[i]);
            is_open = dir_open != NULL;
            if (dir_open)
                closedir(dir_open);
        }
        if (is_open) {
            mx_output_blocks_dir(path[i]);
            mx_output_dirents(path[i]);
            if (dir)
                closedir(dir);
        } else {
            mx_print_error("uls: ");
            if (path[i][mx_strlen(path[i]) - 1] != '/') {
                char **file_names = mx_strsplit(path[i], '/');
                mx_print_error(file_names[mx_array_size(file_names) - 1]);
            }
            mx_print_error(": ");
            mx_print_error(strerror(errno));
            mx_print_error("\n");
        }
    }
}

void mx_handle_standard(bool flag_l) {
    int files_count = 0;
    char **files = NULL;

    files_count = mx_count_files(".");
    files = mx_get_files(files_count, ".");
    if (flag_l) {
        mx_sort(files_count, files);
        mx_handle_long(files, files_count, true);
    }
    else {
        mx_output_files(files, files_count);
    }
    for (int i = 0; i < files_count; i++)
        free(files[i]);
    free(files);
}

