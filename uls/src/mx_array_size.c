#include "../inc/uls.h"

int mx_array_size(char **array) {
    if (array == NULL || *array == NULL)
        return -1;

    int answer = 0;

    for (int i = 0; array[i] != NULL; i++) {
        answer++;
    }

    return answer;
}

