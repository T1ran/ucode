#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"
#include <stdio.h>

void showMatrix(int n, int graph[n][n]) {
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
    int matrix[4][4] =
    { 
        { MX_INT_MAX,          8, 10,         MX_INT_MAX},
        {8,          MX_INT_MAX, 3,          MX_INT_MAX},
        {10,         3,          MX_INT_MAX, 5},
        {MX_INT_MAX, MX_INT_MAX, 5, MX_INT_MAX}
    };

    showMatrix(4, matrix);
    mx_printstr("\n\n");
    mx_shortestPathMatrix(4, matrix);
    showMatrix(4, matrix);

    return 0;
}
