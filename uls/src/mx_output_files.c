#include "../inc/uls.h"

void mx_output_files(char **file_arr, int files_count) {
    mx_sort(files_count, file_arr);
    if (isatty(1)) {
        mx_output_default(file_arr, files_count);
        return;
    }
    for (int i = 0; i < files_count; i++) {
        mx_printstr(file_arr[i]);
        mx_printchar('\n');
    }
}

