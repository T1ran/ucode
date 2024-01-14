#include "../inc/uls.h"

void mx_output_dir(char **dir, int dir_count, int files_count, bool error) {
    bool print = false;
    bool is_open = true;

    mx_sort(dir_count, dir);

    if (files_count > 0 || dir_count > 1 || error)
        print = true;
    if (print && files_count > 0)
        mx_printchar('\n');
    for (int i = 0; i < dir_count; i++) {
        is_open = true;
        if (mx_is_dir(dir[i])) {
            DIR *dir_open = opendir(dir[i]);
            is_open = dir_open != NULL;
            if(dir_open)
                closedir(dir_open);
        }
        if (is_open) {
            DIR *current_dir = opendir(dir[i]);
            if (current_dir) {
                char **files = NULL;
                int files_count_dir = 0;
                if (print) {
                    mx_printstr(dir[i]);
                    mx_printchar(':');
                }
                files_count_dir = mx_count_files(dir[i]);
                if (print)
                    mx_printchar('\n');
                files = mx_get_files(files_count_dir, dir[i]);
                mx_output_files(files, files_count_dir);
                for (int i = 0; i < files_count_dir; i++)
                    free(files[i]);
                free(files);
                if (current_dir)
                    closedir(current_dir);
        } else {
            if (print) {
                mx_printstr(dir[i]);
                mx_printstr(":\n");
            }
            mx_print_error("uls: ");
            if (dir[i][mx_strlen(dir[i]) - 1] != '/') {
                char **file_names = mx_strsplit(dir[i], '/');
                mx_print_error(file_names[mx_array_size(file_names) - 1]);
            }
            mx_print_error(": ");
            mx_print_error(strerror(errno));
            mx_print_error("\n");
            }
        }
        if (i + 1 != dir_count)
            mx_printstr("\n");
    }
}

