#include "../inc/pathfinder.h"

int mx_gen_pathfinder(t_pathfinder *pathfinder, char *data) {
    char *data_start = data;

    while (*data != '\n' && *data != '\0') {
        if(!mx_isdigit(*data))
        {
            return 1;
        }
        ++data;
    }
    for (int i = 0; i < data - data_start; ++i) {
        pathfinder->islands_count += (data_start[i] - 48) * (int) mx_pow(10.0, (data - data_start - i - 1));
    }
    ++data;

    for (int i = 2; *data != '\0'; ++i) {
        if (mx_line_pathfinder(pathfinder, &data))
            return i;
    }

    return 0;
}

