#include "../inc/pathfinder.h"

int mx_read_till(char **data, char *store, char end, int (*f)(char)) {
    char temp[2] = " \0";

    while (**data != '\n') {
        if (**data == end)
            break;
        if (!f(**data)) {
            return 1;
        }
        temp[0] = **data;
        mx_strcat(store, temp);
        ++(*data);
    }
    ++(*data);
    return 0;
}

