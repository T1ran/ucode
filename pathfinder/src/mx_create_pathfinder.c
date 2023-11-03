#include "../inc/pathfinder.h"

t_pathfinder *mx_create_pathfinder(void) {
    t_pathfinder *pathfinder = (t_pathfinder *) malloc(sizeof(t_pathfinder));
    pathfinder->islands_count = 0;
    pathfinder->real_islands_count = 0;
    pathfinder->paths_count = 0;

    pathfinder->matrix = NULL;
    pathfinder->islands = (char **)malloc(sizeof(char *));
    pathfinder->paths = NULL;

    return pathfinder;
}

