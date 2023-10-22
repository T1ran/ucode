#include "../inc/pathfinder.h"

int mx_line_pathfinder(char **line, t_pathfinder *pathfinder) {
    char *temp1 = mx_strnew(0);
    char *temp2 = mx_strnew(0);
    char *temp3 = mx_strnew(0);
    char temp[2] = " \0";

    while (**line != '\n') {
        if (**line == '-')
            break;
        if (!mx_isalpha(**line)) {
            free(temp1);
            free(temp2);
            free(temp3);
            return 1;
        }
        temp[0] = **line;
        mx_strcat(temp1, temp);
        ++*line;
    }
    ++*line;
    while (**line != '\n') {
        if (**line == ',')
            break;
        if (!mx_isalpha(**line)) {
            free(temp1);
            free(temp2);
            free(temp3);
            return 1;
        }
        temp[0] = **line;
        mx_strcat(temp2, temp);
        ++*line;
    }
    ++*line;
    while (**line != '\n') {
        if (**line == '\n')
            break;
        if (!mx_isdigit(**line)) {
            free(temp1);
            free(temp2);
            free(temp3);
            return 1;
        }
        temp[0] = **line;
        mx_strcat(temp3, temp);
        ++*line;
    }
    if (mx_strcmp("", temp1) == 0 || mx_strcmp("", temp2) == 0 || mx_strcmp(temp1, temp2) == 0) {
        free(temp1);
        free(temp2);
        free(temp3);
        return 1;
    }

    mx_add_path(pathfinder, temp1, temp2, temp3);
    free(temp1);
    free(temp2);
    free(temp3);

    return 0;
}

