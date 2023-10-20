#include "../inc/pathfinder.h"

void mx_shortestPathMatrix(t_pathfinder pathfinder) {
    for (int i = 0; i < pathfinder.isl_count; ++i) {
        for (int src = 0; src < pathfinder.isl_count; ++src) {
            for (int dst = 0; dst < pathfinder.isl_count; ++dst) {
                if (pathfinder.matrices.bridges[src][i] != MX_INT_MAX && pathfinder.matrices.bridges[i][dst] != MX_INT_MAX
                    && pathfinder.matrices.bridges[src][i] + pathfinder.matrices.bridges[i][dst] < pathfinder.matrices.bridges[src][dst] && src != dst) {
                    pathfinder.matrices.bridges[src][dst] = pathfinder.matrices.bridges[src][i] + pathfinder.matrices.bridges[i][dst];
                }
            }
        }
    }
}

