#include "../inc/uls.h"

char **mx_get_names(char *path, int *dirents_count) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    char **names = NULL;

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] != '.') {
            names = mx_realloc(names, sizeof(char *) * (*dirents_count + 1));
            names[*dirents_count] = mx_strdup(entry->d_name);
            (*dirents_count)++;
        }
    }

    names = mx_realloc(names, sizeof(char *) * (*dirents_count + 1));
    names[*dirents_count] = NULL;
    mx_bubble_sort(names, *dirents_count);

    if (dir)
        closedir(dir);
    return names;
}

