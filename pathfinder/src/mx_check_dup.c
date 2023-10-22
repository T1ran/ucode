#include "../inc/pathfinder.h"

int mx_check_dup(t_pathfinder *pathfinder) {
    for (int i = 0; i < pathfinder->path_count; ++i) {
        for (int j = 0; j < pathfinder->path_count; ++j) {
            if (i == j)
                continue;
            if (!mx_strcmp(pathfinder->paths[i]->island1, pathfinder->paths[j]->island1)
                && !mx_strcmp(pathfinder->paths[i]->island2, pathfinder->paths[j]->island2))
                return 1;
            if (!mx_strcmp(pathfinder->paths[i]->island1, pathfinder->paths[j]->island2)
                && !mx_strcmp(pathfinder->paths[i]->island2, pathfinder->paths[j]->island1))
                return 1;
        }
    }
    return 0;
}

