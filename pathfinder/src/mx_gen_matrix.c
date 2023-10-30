#include "../inc/pathfinder.h"

void mx_gen_matrix(t_pathfinder *pathfinder) {
    int size = pathfinder->islands_count;
    pathfinder->matrix = (t_cell **) malloc(sizeof(t_cell *) * size);
    for (int i = 0; i < size; ++i) {
        pathfinder->matrix[i] = (t_cell *) malloc(sizeof(t_cell) * size);
        for (int j = 0; j < size; ++j) {
            pathfinder->matrix[i][j].distance = MX_INT_MAX;
            pathfinder->matrix[i][j].children_num = 0;
            pathfinder->matrix[i][j].children = NULL;
            pathfinder->matrix[i][j].src = i;
            pathfinder->matrix[i][j].dst = j;
        }
    }
    for (int i = 0; i < pathfinder->paths_count; ++i) {
        pathfinder->matrix[pathfinder->paths[i][0]][pathfinder->paths[i][1]].distance = pathfinder->paths[i][2];
        pathfinder->matrix[pathfinder->paths[i][0]][pathfinder->paths[i][1]].children_num = 0;
        pathfinder->matrix[pathfinder->paths[i][0]][pathfinder->paths[i][1]].standart = 1;
        pathfinder->matrix[pathfinder->paths[i][1]][pathfinder->paths[i][0]].distance = pathfinder->paths[i][2];
        pathfinder->matrix[pathfinder->paths[i][1]][pathfinder->paths[i][0]].standart = 1;
    }
}

