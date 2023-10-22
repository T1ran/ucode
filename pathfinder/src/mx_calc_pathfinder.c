#include "../inc/pathfinder.h"

void mx_calc_pathfinder(t_pathfinder *pathfinder) {
    if (mx_form_islands(pathfinder)) {
        mx_printerr("error: invalid number of islands\n");
        mx_del_pathfinder(pathfinder);
        return;
    }
    if (mx_check_dup(pathfinder)) {
        mx_printerr("error: duplicate bridges\n");
        mx_del_pathfinder(pathfinder);
        return;
    }
    if (mx_check_bridges(pathfinder)) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_pathfinder(pathfinder);
        return;
    }
    mx_del_pathfinder(pathfinder);
}

