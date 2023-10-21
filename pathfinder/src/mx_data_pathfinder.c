#include "../inc/pathfinder.h"

int mx_data_pathfinder(t_pathfinder *pathfinder, char *data) {
    char *data_start = data;

    while (*data != '\n' && *data != '\0') {
        if(!mx_isdigit(*data))
        {
            return 3;
        }
        ++data;
    }
    for (int i = 0; i < data - data_start; ++i) {
        pathfinder->isl_count += (data_start[i] - 48) * (int) mx_pow(10.0, (data - data_start - i - 1));
    }
    ++data;
    
    if (mx_line_pathfinder(pathfinder, data))
        return 4;
    free(data_start);
    return 0;
}

