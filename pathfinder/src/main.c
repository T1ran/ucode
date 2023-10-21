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

void showPaths(int n, char ***paths) {
    printf("Shortest Paths between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paths[i][j] == NULL) {
                printf("INF\t\t");
            } else {
                printf("%s\t\t", paths[i][j]);
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
    data.islands = (char **)malloc(4 * sizeof(char *));

    data.islands[0] = mx_strdup("Greenland");
    data.islands[1] = mx_strdup("Bananal");
    data.islands[2] = mx_strdup("Fraser");
    data.islands[3] = mx_strdup("Java");
    data.matrices.paths = (char ***)malloc(4 * sizeof(char **));
    for(int i = 0; i < 4; ++i)
        data.matrices.paths[i] = (char **)malloc(4 * sizeof(char *));
    mx_setPaths(data);
    showMatrix(4, data.matrices.bridges);
    showPaths(4, data.matrices.paths);
    mx_printstr("\n\n");
    mx_shortestPathMatrix(data);
    showMatrix(4, data.matrices.bridges);

    return 0;
}
