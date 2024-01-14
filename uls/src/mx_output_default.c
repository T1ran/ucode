#include "../inc/uls.h"

void mx_output_default(char **files, int files_count) {
    int target_len = 0;
    struct winsize win;
    int cols = 0;
    int rows = 0;

    for (int i = 0; i < files_count; i++) {
        if (target_len < mx_strlen(files[i]))
            target_len = mx_strlen(files[i]);
    }
    target_len += 8 - (target_len % 8);

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    cols = win.ws_col / target_len;
    if (cols == 0)
        cols++;
    rows = files_count / cols;
    if (rows == 0 || files_count % cols != 0)
        rows++;

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < files_count; j += rows) {
            mx_printstr(files[j]);
            int len = target_len - mx_strlen(files[j]);
            len = len / 8 + (len % 8 != 0);
            for (int k = 0; k < len; k++) {
                mx_printchar('\t');
            }
        }
        if (files_count > 0) {
            mx_printchar('\n');
        }
    }
}

