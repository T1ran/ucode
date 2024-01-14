#include "../inc/uls.h"

void mx_print_error(char *text) {
    write(2, text, sizeof(char) * mx_strlen(text));
}

void mx_print_error_char(char text) {
    write(2, &text, sizeof(char));
}

