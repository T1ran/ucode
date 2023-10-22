#include "../inc/pathfinder.h"

void mx_add_path(t_pathfinder *pathfinder, char *island1, char *island2, char *bridge) {
    int bridge_int = 0;
    pathfinder->path_count += 1;

    t_path *new_path = (t_path *)malloc(sizeof(t_path));
    if (new_path == NULL) {
        return;
    }

    new_path->island1 = mx_strdup(island1);
    new_path->island2 = mx_strdup(island2);

    for (int i = 0; i < mx_strlen(bridge); ++i)
        bridge_int += (bridge[i] - 48) * (int) mx_pow(10.0, (mx_strlen(bridge) - i - 1));

    new_path->bridge = bridge_int;

    pathfinder->paths = (t_path **)mx_realloc(pathfinder->paths, sizeof(t_path *) * pathfinder->path_count);
    if (pathfinder->paths == NULL) {
        free(new_path->island1);
        free(new_path->island2);
        free(new_path);
        return;
    }

    pathfinder->paths[pathfinder->path_count - 1] = new_path;
}

