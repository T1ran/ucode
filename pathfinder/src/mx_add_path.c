#include "../inc/pathfinder.h"

void mx_add_path(t_pathfinder *pathfinder, char *island1, char *island2, char *distance) {
    int index1 = mx_island_index(pathfinder, island1);
    int index2 = mx_island_index(pathfinder, island2);
    int distance_value = 0;

    for (int i = 0; i < mx_strlen(distance); ++i)
        distance_value += (distance[i] - 48) * (int) mx_pow(10.0, (mx_strlen(distance) - i - 1));

    int *new_path = (int *)malloc(3 * sizeof(int));

    new_path[0] = index1;
    new_path[1] = index2;
    new_path[2] = distance_value;

    pathfinder->paths_count++;
    int **new_paths = (int **)realloc(pathfinder->paths, pathfinder->paths_count * sizeof(int *));

    pathfinder->paths = new_paths;
    pathfinder->paths[pathfinder->paths_count - 1] = new_path;

}

