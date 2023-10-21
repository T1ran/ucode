#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_pathfinder {
    int isl_count;
    char **islands;
    int **bridges;
    char ***paths;
}              t_pathfinder;

int mx_read_pathfinder(t_pathfinder *pathfinder, char *file);
int mx_data_pathfinder(t_pathfinder *pathfinder, char *data);
int mx_line_pathfinder(t_pathfinder *pathfinder, char *line);

#endif
