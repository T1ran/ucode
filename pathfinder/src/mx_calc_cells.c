#include "../inc/pathfinder.h"

void mx_calc_cells(t_cell *cell_main, t_cell *cell1, t_cell *cell2) {
    int distance_new = cell1->distance + cell2->distance;
    if (distance_new == cell_main->distance) {
        cell_main->children_num += 1;
        cell_main->children = (t_cell **) mx_realloc(cell_main->children, sizeof(t_cell *) * cell_main->children_num);
        cell_main->children[cell_main->children_num-1] = cell1;
    }
    if (distance_new < cell_main->distance) {
        cell_main->distance = distance_new;
        if (cell_main->children != NULL) {
            free(cell_main->children);
        }
        cell_main->children_num = 1;
        cell_main->standart = 0;
        cell_main->children = (t_cell **) malloc(sizeof(t_cell *) * cell_main->children_num);
        cell_main->children[0] = cell1;
    }
}

