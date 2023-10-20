#include "../inc/pathfinder.h"

void mx_shortestPathMatrix(int n, t_matrix matrix) {
    for (int i = 0; i < n; ++i) {
        for (int src = 0; src < n; ++src) {
            for (int dst = 0; dst < n; ++dst) {
                if (matrix.bridges[src][i] != MX_INT_MAX && matrix.bridges[i][dst] != MX_INT_MAX
                    && matrix.bridges[src][i] + matrix.bridges[i][dst] < matrix.bridges[src][dst] && src != dst) {
                    matrix.bridges[src][dst] = matrix.bridges[src][i] + matrix.bridges[i][dst];
                }
            }
        }
    }
}

