#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_pathfinder {
    int fd;
    int isl_count;
}              t_pathfinder;

void mx_shortestPathMatrix(int n, int graph[n][n]);

#endif
