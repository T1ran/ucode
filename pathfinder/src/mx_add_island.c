#include "../inc/pathfinder.h"

void mx_add_island(t_pathfinder *pathfinder, char *island) {
    static int islands_count = 0;
    
    for (int i = 0; i < islands_count; i++) {
        if (mx_strcmp(pathfinder->islands[i], island) == 0) {
            return;
        }
    }
    mx_printstr(island);
    mx_printint(islands_count);
    islands_count++;
    mx_printint(islands_count);
    mx_printchar('\n');
    char **new_islands = (char **)mx_realloc(pathfinder->islands, islands_count * sizeof(char *));
    pathfinder->islands = new_islands;

    pathfinder->islands[islands_count - 1] = mx_strdup(island);
}

