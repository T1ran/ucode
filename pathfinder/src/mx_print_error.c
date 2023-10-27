#include "../inc/pathfinder.h"

void mx_print_error(char *text) {
    write(2, text, sizeof(char) * mx_strlen(text));
}

