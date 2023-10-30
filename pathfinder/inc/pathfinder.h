#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_cell {
    int distance;
    int children_num;
    struct s_cell **children;
    int src;
    int dst;
    int standart;
}              t_cell;

typedef struct s_pathfinder {
    int islands_count;
    int real_islands_count;
    char **islands;
    int paths_count;
    int **paths;
    t_cell **matrix;
}              t_pathfinder;

void mx_print_error(char *text);
int mx_isalpha(char c);
int mx_read_till(char **data, char *store, char end, int (*f)(char));

void mx_pathfinder(int argc, char** argv);

t_pathfinder *mx_create_pathfinder(void);
void mx_delete_pathfinder(t_pathfinder *pathfinder);
int mx_file_errors(int argc, char **argv);
char *mx_read_data(char *file);
int mx_gen_pathfinder(t_pathfinder *pathfinder, char *data);
int mx_line_pathfinder(t_pathfinder *pathfinder, char **line);
void mx_add_island(t_pathfinder *pathfinder, char *island);
int mx_island_index(t_pathfinder *pathfinder, char *island);
void mx_add_path(t_pathfinder *pathfinder, char *island1, char *island2, char *distance);
int mx_check_paths(t_pathfinder *pathfinder);

void mx_gen_matrix(t_pathfinder *pathfinder);
void mx_calc_pathfinder(t_pathfinder *pathfinder);
void mx_calc_cells(t_cell *cell_main, t_cell *cell1, t_cell *cell2);

void mx_print_boundary(void);
void mx_find_routes(t_cell *cell, int *path, int pathLen, int ***allPaths, int *numPaths, int *pathSizes);
void mx_print_result(t_pathfinder *pathfinder);
void mx_print_cell(t_cell cell, char **islands, t_cell **matrix);

#endif

