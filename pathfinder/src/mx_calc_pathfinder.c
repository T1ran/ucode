#include "../inc/pathfinder.h"

void mx_calc_pathfinder(t_pathfinder *pathfinder) {
    int size = pathfinder->islands_count;
    t_cell ** matrix = pathfinder->matrix;
    for (int i = 0; i < size; ++i) {
        for (int src = 0; src < size; ++src) {
            for (int dst = 0; dst < size; ++dst) {
                if (src != dst && matrix[src][i].distance != MX_INT_MAX
                    && matrix[i][dst].distance != MX_INT_MAX) {
                    mx_calc_cells(&matrix[src][dst], &matrix[src][i], &matrix[i][dst]);
                }
            }
        }
    }
}

