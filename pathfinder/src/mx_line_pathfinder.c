#include "../inc/pathfinder.h"

int mx_line_pathfinder(t_pathfinder *pathfinder, char *line) {
    //char *start_line = line;
    char *temp1 = NULL;
    char *temp2 = NULL;
    mx_printstr(line);
    while (*line != '-') {
        if (mx_isspace(*line) || *line == '\0')
            return 1;
        char a[2];
        a[0] = *line;
        a[1] = '\0';

        if (temp1 == NULL) {
            temp1 = mx_strnew(0);
            mx_strcat(temp1, a);
        }
        else {
            mx_strcat(temp1, a);
        }
        ++line;
    }
    ++line;
    while (*line != '\n' && *line != '\0') {
        char a[2];
        a[0] = *line;
        a[1] = '\0';

        if (mx_isspace(*line) || *line == '\0')
            return 1;
        if (temp2 == NULL) {
            temp2 = mx_strnew(0);
            mx_strcat(temp2, a);
        }
        else {
            mx_strcat(temp2, a);
        }
        ++line;
    }

    mx_printstr("\n\n");
    mx_printstr(temp1);
    mx_printstr("\n\n");
    mx_printstr(temp2);
    mx_printstr("\n\n");
    free(temp1);
    free(temp2);

    return 0;
    pathfinder->isl_count = 0;
}

