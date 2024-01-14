#include "../inc/uls.h"

char **mx_get_files(int files_count, char *path) {
    struct dirent *entry = NULL;
    DIR *dir = opendir(path);
    char **files = (char **)malloc(files_count * sizeof(char *));

    if(!dir)
        return files;

    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            files[i] = mx_strdup(entry->d_name);
            i++;
        }
    }
    if (dir)
        closedir(dir);

    return files;
}

