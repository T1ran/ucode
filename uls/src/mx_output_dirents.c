#include "../inc/uls.h"

void mx_output_dirents(char *path) {
    struct stat file_stat;
    int dirent_count = 0;
    char *dir_path = mx_strcat(path, "/");
    char **names = mx_get_names(dir_path, &dirent_count);
    char **file_path = (char **)malloc((dirent_count + 1) * sizeof(char *));

    for (int i = 0; i < dirent_count; ++i)
        file_path[i] = mx_strcat(dir_path, names[i]);
    file_path[dirent_count] = NULL;

    int spaces[4] = {-1, -1, -1, -1};
    mx_spaces(file_path, dirent_count, spaces);
    for (int i = 0; i < dirent_count; i++)
        mx_output_info(&file_stat, file_path[i], spaces, true);

    mx_strdel(&dir_path);
    mx_del_strarr(&names);
    mx_del_strarr(&file_path);
}

