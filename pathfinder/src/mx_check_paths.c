#include "../inc/pathfinder.h"

int mx_check_paths(t_pathfinder *pathfinder) {
    long temp = 0;

    for (int i = 0; i < pathfinder->paths_count; ++i) {
        for (int j = 0; j < pathfinder->paths_count; ++j) {
            if (i == j)
                continue;
            if ((pathfinder->paths[i][0] == pathfinder->paths[j][0]
                && pathfinder->paths[i][1] == pathfinder->paths[j][1])
                || (pathfinder->paths[i][0] == pathfinder->paths[j][1]
                && pathfinder->paths[i][1] == pathfinder->paths[j][0])) {
                mx_print_error("error: duplicate bridges\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < pathfinder->paths_count; ++i) {
        temp += pathfinder->paths[i][2];
        if (temp > MX_INT_MAX) {
            mx_print_error("error: sum of bridges lengths is too big\n");
            return 1;
        }
    }

    return 0;
}

