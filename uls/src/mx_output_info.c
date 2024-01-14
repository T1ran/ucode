#include "../inc/uls.h"

void mx_output_info(struct stat *file_stat,
                          char *path,
                          int *spaces,
                          bool print) {
    if (lstat(path, file_stat)) 
        return;
    mx_output_mode(file_stat->st_mode);
    mx_output_rights(file_stat);
    mx_output_additional(path);
    mx_output_links(file_stat, spaces[0]);
    mx_output_owner(file_stat, spaces[1]);
    mx_output_group(file_stat, spaces[2]);
    mx_output_size(file_stat, spaces[3]);
    mx_output_time(file_stat);
    mx_output_name(path, file_stat, print);
}

