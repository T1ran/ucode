#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_path {
    char *island1;
    char *island2;
    int bridge;
}              t_path;

typedef struct s_pathfinder {
    int isl_count;
    int path_count;
    char **islands;
    t_path **paths;
}              t_pathfinder;

void mx_printerr(char *error);
int mx_file_errors(int argc, char **argv);
char *mx_read_data(char *file);
int mx_data_pathfinder(char *data, t_pathfinder *pathfinder);
int mx_isalpha(char c);
int mx_line_pathfinder(char **line, t_pathfinder *pathfinder);
void mx_add_path(t_pathfinder *pathfinder, char *island1, char *island2, char *bridge);

#endif
