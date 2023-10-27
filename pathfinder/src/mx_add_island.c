#include "../inc/pathfinder.h"

void mx_add_island(t_pathfinder *pathfinder, char *island) {
    for (int i = 0; i < pathfinder->real_islands_count; i++) {
        if (mx_strcmp(pathfinder->islands[i], island) == 0) {
            return;
        }
    }

    pathfinder->real_islands_count++;

    char **new_islands = (char **)mx_realloc(pathfinder->islands, pathfinder->real_islands_count * sizeof(char *));
    pathfinder->islands = new_islands;

    pathfinder->islands[pathfinder->real_islands_count - 1] = mx_strdup(island);
}

