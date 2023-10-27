#include "../inc/pathfinder.h"

int mx_check_islands(t_pathfinder *pathfinder) {
    int real_islands_count = 0;
    for (int i = 0; pathfinder->islands[i] != NULL;++i)
        real_islands_count++;

    return real_islands_count == pathfinder->islands_count;
}
