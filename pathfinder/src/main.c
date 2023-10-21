#include "../inc/pathfinder.h"

int main(void) {
    t_pathfinder* pathfinder = malloc(sizeof(t_pathfinder));
    mx_printint(mx_read_pathfinder(pathfinder, "temp"));
    mx_printchar('\n');
    mx_printint(pathfinder->isl_count);
    free(pathfinder);
    return 0;
}
