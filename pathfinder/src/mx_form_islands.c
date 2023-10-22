#include "../inc/pathfinder.h"

void mx_found_isl(char ***islands, int *isl_count, char *island) {
    int found = 0;
    for (int j = 0; j < *isl_count; j++) {
        if (mx_strcmp(island, (*islands)[j]) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        (*isl_count)++;
        *islands = (char **)mx_realloc(*islands, *isl_count * sizeof(char *));
        (*islands)[*isl_count - 1] = mx_strdup(island);
    }
}

int mx_form_islands(t_pathfinder *pathfinder) {
    char **new_islands = NULL;
    int new_isl_count = 0;

    for (int i = 0; i < pathfinder->path_count; i++) {
        mx_found_isl(&new_islands, &new_isl_count, pathfinder->paths[i]->island1);
        mx_found_isl(&new_islands, &new_isl_count, pathfinder->paths[i]->island2);
    }

    if (new_isl_count == pathfinder->isl_count)
    {
        pathfinder->islands = new_islands;
        return 0;
    }
    pathfinder->isl_count = 0;
    for (int i = 0; i < new_isl_count; ++i)
        free(new_islands[i]);
    if (new_isl_count)
        free(new_islands);

    return 1;
}

