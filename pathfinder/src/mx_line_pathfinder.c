#include "../inc/pathfinder.h"

int mx_line_pathfinder(t_pathfinder *pathfinder, char **line) {
    char *island1 = mx_strnew(0);
    char *island2 = mx_strnew(0);
    char *distance = mx_strnew(0);

    if (mx_read_till(&*line, island1, '-', mx_isalpha)
        || mx_read_till(&*line, island2, ',', mx_isalpha)
        || mx_read_till(&*line, distance, '\0', mx_isdigit)
        || mx_strcmp("\0", island1) == 0
        || mx_strcmp("\0", island2) == 0
        || mx_strcmp(island1, island2) == 0
        || mx_atoi(distance) == 0
        || mx_atoi(distance) > MX_INT_MAX) {
        free(island1);
        free(island2);
        free(distance);
        return 1;
    }

    mx_add_island(pathfinder, island1);
    mx_add_island(pathfinder, island2);
    mx_add_path(pathfinder, island1, island2, distance);
    free(island1);
    free(island2);
    free(distance);

    return 0;
    pathfinder->islands_count = 0;
}

