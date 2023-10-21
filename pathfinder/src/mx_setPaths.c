#include "../inc/pathfinder.h"
#include <string.h>

void mx_setPaths(t_pathfinder pathfinder) {
    for (int i = 0; i < pathfinder.isl_count; ++i) {
        for (int j = 0; j < pathfinder.isl_count; ++j) {
            if (pathfinder.matrices.bridges[i][j] != MX_INT_MAX)
            {
                char *temp = mx_strdup(pathfinder.islands[i]);
                mx_strcat(temp, " -> ");
                mx_strcat(temp, pathfinder.islands[j]);
                pathfinder.matrices.paths[i][j] = mx_strdup(temp);
                free(temp);
            }
        }
    }
}

