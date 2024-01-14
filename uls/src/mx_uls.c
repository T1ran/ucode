#include "../inc/uls.h"

void mx_uls(int argc, char *argv[]) {
    bool is_files = 0;
    bool flag_l = 0;
    int flags_count = 0;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-' && mx_isalpha(argv[i][1])) {
            int length = mx_strlen(argv[i]);

            for (int j = 1; j < length; j++) {
                if (argv[i][j] != 'l') {
                    mx_print_error("uls: invalid option -- ");
                    mx_print_error_char(argv[i][j]);
                    mx_print_error("\nusage: uls [-l] [file ...]\n");
                    exit(1);
                }
            }
            flags_count += 1;
        } else {
            is_files = true;
            break;
        }
        flag_l = true;
    }
    if (is_files) {
        mx_handle_files(argc, argv, flag_l, flags_count);
    }
    else {
        mx_handle_standard(flag_l);
    }
}

