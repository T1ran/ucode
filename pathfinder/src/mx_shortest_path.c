#include "../inc/pathfinder.h"

void mx_shortest_path(t_matrices matrices, int n) {
    int path_size = 0;
    for (int i = 0; i < n; ++i) {
        for (int src = 0; src < n; ++src) {
            for (int dst = 0; dst < n; ++dst) {
                if (matrices.bridges[src][i] != MX_INT_MAX && matrices.bridges[i][dst] != MX_INT_MAX
                    && matrices.bridges[src][i] + matrices.bridges[i][dst] < matrices.bridges[src][dst] && src != dst) {
                    matrices.bridges[src][dst] = matrices.bridges[src][i] + matrices.bridges[i][dst];
                    if (matrices.paths[src][dst] == NULL)
                        matrices.path_size[src][dst] = 2;
                    path_size = (matrices.path_size[src][i] + matrices.path_size[i][dst] - 1);
                    mx_printint(path_size);
                    mx_printchar(' ');
                    matrices.paths[src][dst] = realloc(matrices.paths[src][dst], path_size);
                    matrices.paths[src][dst][0] = src;
                    int loc = 1;
                    for (int j = 1; j < matrices.path_size[src][i]; ++j) {
                        matrices.paths[src][dst][loc] = matrices.paths[src][i][j];
                        ++loc;
                    }
                    for (int j = 1; j < matrices.path_size[i][dst] - 1; ++j) {
                        matrices.paths[src][dst][loc] = matrices.paths[i][dst][j];
                        ++loc;
                    }
                    matrices.paths[src][dst][path_size - 1] = dst;
                    matrices.path_size[src][dst] = path_size;
                }
            }
        }
    }
}

