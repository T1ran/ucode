#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_pathfinder {
    int fd;
    int isl_count;
}              t_pathfinder;

typedef struct s_matrix {
    int **bridges;
    char ***paths;
}              t_matrix;

void mx_shortestPathMatrix(int n, t_matrix matrix);

#endif
