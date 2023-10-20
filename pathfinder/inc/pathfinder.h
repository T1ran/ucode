#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_matrices {
    int **bridges;
    char ***paths;
}              t_matrices;

typedef struct s_pathfinder {
    int fd;
    int isl_count;
    char **islands;
    t_matrices matrices;
}              t_pathfinder;


void mx_shortestPathMatrix(t_pathfinder pathfinder);
void mx_setPaths(t_pathfinder pathfinder);

#endif
