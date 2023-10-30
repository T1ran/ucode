#include "../inc/pathfinder.h"

void mx_print_result(t_pathfinder *pathfinder) {
    for (int i = 0; i < pathfinder->islands_count; ++i) {
        for (int j = i + 1; j < pathfinder->islands_count; ++j) {
            if (pathfinder->matrix[i][j].distance != MX_INT_MAX)
                mx_print_cell(pathfinder->matrix[i][j], pathfinder->islands, pathfinder->matrix);
        }
    }
}

