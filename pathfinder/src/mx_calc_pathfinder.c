#include "../inc/pathfinder.h"
#include <stdio.h>

void showMatrix(int n, int **graph) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == MX_INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}
void mx_calc_pathfinder(t_pathfinder *pathfinder) {
    if (mx_form_islands(pathfinder)) {
        mx_printerr("error: invalid number of islands\n");
        mx_del_pathfinder(pathfinder);
        return;
    }
    if (mx_check_dup(pathfinder)) {
        mx_printerr("error: duplicate bridges\n");
        mx_del_pathfinder(pathfinder);
        return;
    }
    if (mx_check_bridges(pathfinder)) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_pathfinder(pathfinder);
        return;
    }

    mx_create_matrices(pathfinder);
    showMatrix(pathfinder->isl_count, pathfinder->matrices.path_size);
    mx_shortest_path(pathfinder->matrices, pathfinder->isl_count);
    showMatrix(pathfinder->isl_count, pathfinder->matrices.path_size);
    mx_printint(pathfinder->matrices.paths[0][3][0]);
    mx_printchar('\n');
    mx_printint(pathfinder->matrices.paths[0][3][1]);
    mx_printchar('\n');
    mx_printint(pathfinder->matrices.paths[0][3][2]);
    mx_del_pathfinder(pathfinder);
}

