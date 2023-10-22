#include "../inc/pathfinder.h"

void mx_printerr(char *error) {
    write(2, error, sizeof(char) * mx_strlen(error));
}

