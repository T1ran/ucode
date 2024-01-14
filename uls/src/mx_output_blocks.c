#include "../inc/uls.h"

void mx_output_blocks(char **path, int files_count) {
    blkcnt_t blocks_total = 0;
    struct stat file_stat;

    if (files_count <= 0)
        return;

    for (int i = 0; i < files_count; i++) {
        if (lstat(path[i], &file_stat) == 0)
            blocks_total += file_stat.st_blocks;
    }
    mx_printstr("total ");
    mx_printlonglong(blocks_total);
    mx_printstr("\n");
}

