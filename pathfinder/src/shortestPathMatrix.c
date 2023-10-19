#include "../inc/pathfinder.h"

void mx_shortestPathMatrix(int n, int graph[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int src = 0; src < n; ++src) {
            for (int dst = 0; dst < n; ++dst) {
                if (graph[src][i] != MX_INT_MAX && graph[i][dst] != MX_INT_MAX && graph[src][i] + graph[i][dst] < graph[src][dst] && src != dst) {
                    graph[src][dst] = graph[src][i] + graph[i][dst];
                }
            }
        }
    }
}

