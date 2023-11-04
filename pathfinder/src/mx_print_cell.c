#include "../inc/pathfinder.h"

void mx_print_cell(t_cell cell, char **islands, t_cell **matrix) {
    int path[1024];
    int pathSizes[1024];
    int** allPaths = NULL;
    int numPaths = 0;
    int temp = 0;

    mx_find_routes(&cell, path, 0, &allPaths, &numPaths, pathSizes);
    if (cell.standart == 1 && pathSizes[0] > 1) {
        numPaths++;
        allPaths = (int**)mx_realloc(allPaths, (numPaths) * sizeof(int*));
        allPaths[(numPaths) - 1] = (int*)malloc(sizeof(int));
        allPaths[(numPaths) - 1][0] = cell.dst;
        pathSizes[(numPaths) - 1] = 1;
        for (int i = numPaths - 2; i >= 0; --i) {
            if (allPaths[i][pathSizes[i]-1] > allPaths[numPaths - 1][0]) {
                int temp_size = pathSizes[numPaths - 1];
                int *temp = allPaths[numPaths - 1];
                allPaths[numPaths - 1] = allPaths[i];
                allPaths[i] = temp;
                pathSizes[numPaths - 1] = pathSizes[i];
                pathSizes[i] = temp_size;
            }
        }
    }
    for (int i = 0; i < numPaths; ++i) {
        mx_print_boundary();
        mx_printstr("Path: ");
        mx_printstr(islands[cell.src]);
        mx_printstr(" -> ");
        mx_printstr(islands[cell.dst]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        mx_printstr(islands[cell.src]);
        for (int j = pathSizes[i] - 1; j >= 0; --j) {
            mx_printstr(" -> ");
            mx_printstr(islands[allPaths[i][j]]);
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        temp = cell.src;
        if (pathSizes[i]>=2) {
            for (int j = pathSizes[i] - 1; j >= 0; --j) {
                if (j != pathSizes[i] - 1)
                    mx_printstr(" + ");
                mx_printint(matrix[temp][allPaths[i][j]].distance);
                temp = allPaths[i][j];
            }
            mx_printstr(" = ");
        }
        mx_printint(cell.distance);
        mx_printchar('\n');
        mx_print_boundary();
    }
    for (int i = 0; i < numPaths; ++i)
        free(allPaths[i]);
    free(allPaths);
}

