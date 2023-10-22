#include "../inc/pathfinder.h"

int mx_data_pathfinder(char *data, t_pathfinder *pathfinder) {
    char *data_start = data;

    while (*data != '\n' && *data != '\0') {
        if(!mx_isdigit(*data))
        {
            return 1;
        }
        ++data;
    }
    for (int i = 0; i < data - data_start; ++i) {
        pathfinder->isl_count += (data_start[i] - 48) * (int) mx_pow(10.0, (data - data_start - i - 1));
    }
    ++data;
    for (int i = 2; *data != '\0'; ++i) {
        if (mx_line_pathfinder(&data, pathfinder))
            return i;
        ++data;
    }

    return 0;
}

