#include "../inc/pathfinder.h"

void mx_find_routes(t_cell *cell, int *path, int pathLen, int ***allPaths, int *numPaths, int *pathSizes) {
    path[pathLen] = cell->dst;
    pathLen++;

    if (cell->children_num == 0) {
        (*numPaths)++;
        *allPaths = (int**)mx_realloc(*allPaths, (*numPaths) * sizeof(int*));
        (*allPaths)[(*numPaths) - 1] = (int*)malloc(pathLen * sizeof(int));
        pathSizes[(*numPaths) - 1] = pathLen;
        for (int i = 0; i < pathLen; i++) {
            (*allPaths)[(*numPaths) - 1][i] = path[i];
        }
    } else {
        for (int i = 0; i < cell->children_num; i++) {
            mx_find_routes(cell->children[i], path, pathLen, allPaths, numPaths, pathSizes);
        }
    }
}

