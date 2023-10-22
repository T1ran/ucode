#include "../inc/pathfinder.h"

int mx_check_bridges(t_pathfinder *pathfinder) {
    long temp = 0;
    for (int i = 0; i < pathfinder->path_count; ++i) {
        temp += pathfinder->paths[i]->bridge;
        if (temp > MX_INT_MAX)
            return 1;
    }
    return 0;
}

