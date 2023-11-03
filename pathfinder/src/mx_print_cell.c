#include "../inc/pathfinder.h"

void mx_print_cell(t_cell cell, char **islands, t_cell **matrix) {
    int path[1024];
    int pathSizes[1024];
    int** allPaths = NULL;
    int numPaths = 0;
    int temp = 0;

    mx_find_routes(&cell, path, 0, &allPaths, &numPaths, pathSizes);
    if (cell.standart == 1) {
        mx_print_boundary();
        mx_printstr("Path: ");
        mx_printstr(islands[cell.src]);
        mx_printstr(" -> ");
        mx_printstr(islands[cell.dst]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        mx_printstr(islands[cell.src]);
        mx_printstr(" -> ");
        mx_printstr(islands[cell.dst]);
        mx_printchar('\n');
        mx_printstr("Distance: ");
        mx_printint(cell.distance);
        mx_printchar('\n');
        mx_print_boundary();
    }
    for (int i = cell.standart; i < numPaths; ++i) {
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
        for (int j = pathSizes[i] - 1; j >= 0; --j) {
            if (j != pathSizes[i] - 1)
                mx_printstr(" + ");
            mx_printint(matrix[temp][allPaths[i][j]].distance);
            temp = allPaths[i][j];
        }
        mx_printstr(" = ");
        mx_printint(cell.distance);
        mx_printchar('\n');
        mx_print_boundary();
    }
    for (int i = 0; i < numPaths; ++i)
        free(allPaths[i]);
    free(allPaths);
}

