#include "../inc/pathfinder.h"

void mx_del_pathfinder(t_pathfinder *pathfinder) {
    for (int i = 0; i < pathfinder->path_count; ++i) {
        free(pathfinder->paths[i]->island1);
        free(pathfinder->paths[i]->island2);
    }
    for (int i = 0; i < pathfinder->path_count; ++i)
        free(pathfinder->paths[i]);
    for (int i = 0; i < pathfinder->isl_count; ++i)
        free(pathfinder->islands[i]);

    free(pathfinder->paths);
    if(pathfinder->isl_count)
        free(pathfinder->islands);

    free(pathfinder);
}

