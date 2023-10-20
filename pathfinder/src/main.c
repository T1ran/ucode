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

int main(void) {
    int **matrix;
    matrix = (int **)malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++) {
        matrix[i] = (int *)malloc(8 * sizeof(int));
    }
    //char ***paths;
    int initValues[4][4] =
    { 
        { MX_INT_MAX,          8, 10,         MX_INT_MAX},
        {8,          MX_INT_MAX, 3,          MX_INT_MAX},
        {10,         3,          MX_INT_MAX, 5},
        {MX_INT_MAX, MX_INT_MAX, 5, MX_INT_MAX}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = initValues[i][j];
        }
    }
    t_pathfinder data;
    data.matrices.bridges = matrix;
    data.isl_count = 4;

    showMatrix(4, data.matrices.bridges);
    mx_printstr("\n\n");
    mx_shortestPathMatrix(data);
    showMatrix(4, data.matrices.bridges);

    return 0;
}
