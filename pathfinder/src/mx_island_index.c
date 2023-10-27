#include "../inc/pathfinder.h"

int mx_island_index(t_pathfinder *pathfinder, char *island) {
    if (pathfinder == NULL || island == NULL || pathfinder->islands == NULL) {
        return -1;
    }

    for (int i = 0; pathfinder->islands[i] != NULL; i++) {
        if (mx_strcmp(pathfinder->islands[i], island) == 0) {
            return i;
        }
    }

    return -1;
}

