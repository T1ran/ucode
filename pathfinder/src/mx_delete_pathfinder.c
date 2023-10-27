#include "../inc/pathfinder.h"

void mx_delete_pathfinder(t_pathfinder *pathfinder) {
    if (pathfinder == NULL)
        return;
    if (pathfinder->islands != NULL) {
        for (int i = 0; pathfinder->islands[i] != NULL; ++i)
            free(pathfinder->islands[i]);
        free(pathfinder->islands);
    }
    if (pathfinder->matrix != NULL) {
        for (int y = 0; y < pathfinder->islands_count; ++y) {
            for (int x = 0; x < pathfinder->islands_count; ++x) {
                if (pathfinder->matrix[y][x].data != NULL) {
                    for (int i = 0; pathfinder->matrix[y][x].data[i] != NULL; ++i)
                        free(pathfinder->matrix[y][x].data[i]);
                    free(pathfinder->matrix[y][x].data);
                }
            }
            free(pathfinder->matrix[y]);
        }
        free(pathfinder->matrix);
    }

    free(pathfinder);
}
