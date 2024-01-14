#include "../inc/uls.h"

void mx_output_blocks_dir(char *path) {
    bool print_total = false;
    blkcnt_t total_blocks = 0;
    struct stat file_stat;
    int dirent_count = 0;

    char *dir_path = mx_strcat(path, "/");
    char **names = mx_get_names(dir_path, &dirent_count);

    if (dirent_count <= 0) {
        mx_del_strarr(&names);
        mx_strdel(&dir_path);
        return;
    }

    for (int i = 0; i < dirent_count; i++) {
        char *file_path = mx_strcat(dir_path, names[i]);

        if (lstat(file_path, &file_stat) == 0) {
            total_blocks += file_stat.st_blocks;
            print_total = true;
        }
        mx_strdel(&file_path);
    }
    
    if (print_total) {
        mx_printstr("total ");
        mx_printlonglong(total_blocks);
        mx_printchar('\n');
    }
    mx_del_strarr(&names);
    mx_strdel(&dir_path);
}

