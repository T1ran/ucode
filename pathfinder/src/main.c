#include "../libmx/inc/libmx.h"
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
    /*int matrix[4][4] =
    { 
        { MX_INT_MAX,          8, 10,         MX_INT_MAX},
        {8,          MX_INT_MAX, 3,          MX_INT_MAX},
        {10,         3,          MX_INT_MAX, 5},
        {MX_INT_MAX, MX_INT_MAX, 5, MX_INT_MAX}
    };*/
    int **matrix;
    matrix = (int **)malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++) {
        matrix[i] = (int *)malloc(8 * sizeof(int));
    }

    int initValues[8][8] = {
        {MX_INT_MAX, 471, MX_INT_MAX, 766, 2403, 1141, 11864, 11079},
        {471, MX_INT_MAX, 340, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {MX_INT_MAX, 340, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {766, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {2403, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {1141, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {11864, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX},
        {11079, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX, MX_INT_MAX}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matrix[i][j] = initValues[i][j];
        }
    }
    t_matrix data;
    data.bridges = matrix;

    showMatrix(8, data.bridges);
    mx_printstr("\n\n");
    mx_shortestPathMatrix(8, data);
    showMatrix(8, data.bridges);

    return 0;
}
