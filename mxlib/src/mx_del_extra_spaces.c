#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *answer;
    char *temp;
    int temp_index = 0;

    if (str == NULL) {
        return NULL;
    }

    temp = mx_strnew(mx_strlen(str));
    temp_index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isspace(str[i])) {
            temp[temp_index++] = str[i];
        }
        if ((!mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            temp[temp_index++] = ' ';
        }
    }

    answer = mx_strtrim(temp);
    mx_strdel(&temp);

    return answer;
}

