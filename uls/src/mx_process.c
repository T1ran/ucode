#include "../inc/uls.h"

int mx_process_files(int files_count_i,
                 char **files_i,
                 bool flag_l) {
    struct stat path_stat;
    char **files = NULL;
    int files_count = 0;
    int j = 0;
    for (int i = 0; i < files_count_i; i++) {
        stat(files_i[i], &path_stat);
        if (stat(files_i[i], &path_stat) != -1
            && !S_ISDIR(path_stat.st_mode))
            files_count++;
    }
    if (files_count > 0) {
        files = (char **)malloc(files_count * sizeof(char *));
        for (int i = 0; i < files_count_i; i++) {
            stat(files_i[i], &path_stat);
            if (stat(files_i[i], &path_stat) != -1
                && !S_ISDIR(path_stat.st_mode)) {
                files[j] = files_i[i];
                j++;
            }
        }
        if (flag_l) {
            mx_sort(files_count, files);
            mx_handle_long(files, files_count, false);
        }
        else {
            mx_output_files(files, files_count);
        }
        free(files);
    }
    return files_count;
}

void mx_process_dir(int count_files_i,
                char **files_i,
                int files_count,
                bool error,
                bool flag_l) {
    char **dir = NULL;
    int dir_count = 0;
    struct stat path_stat;
    int j = 0;
    for (int i = 0; i < count_files_i; i++) {
        stat(files_i[i], &path_stat);
        if (stat(files_i[i], &path_stat) != -1
            && S_ISDIR(path_stat.st_mode))
            dir_count++;
    }
    if (dir_count > 0) {
        dir = (char **)malloc(dir_count * sizeof(char *));
        for (int i = 0; i < count_files_i; i++) {
            stat(files_i[i], &path_stat);
            if (stat(files_i[i], &path_stat) != -1 &&
                S_ISDIR(path_stat.st_mode)) {
                dir[j] = files_i[i];
                j++;
            }
        }
        if (flag_l) {
            mx_sort(dir_count, dir);
            mx_handle_long_dir(dir, dir_count, files_count, error);
        }
        else {
            mx_output_dir(dir, dir_count, files_count, error);
        }
        free(dir);
    }
}

