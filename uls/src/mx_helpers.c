#include "../inc/uls.h"

bool mx_is_dir(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);

    return S_ISDIR(path_stat.st_mode);
}

void mx_sort(int size, char *array[size]) {
    bool sorted = false;
    char *temp;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size - 1; ++i) {
            if (mx_strcmp(array[i + 1], array[i]) < 0) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

void mx_spaces(char **path, int files_count, int *spaces) {
    struct stat file_stat;
    for (int i = 0; i < files_count; i++) {
        stat(path[i], &file_stat);
        struct passwd *pw = getpwuid(file_stat.st_uid);
        struct group *gr = getgrgid(file_stat.st_gid);
        if (spaces[0] < mx_strlen(mx_itoa(file_stat.st_nlink)))
            spaces[0] = mx_strlen(mx_itoa(file_stat.st_nlink));

        if (pw == 0) {
            if (spaces[1] < mx_strlen(mx_itoa(file_stat.st_uid)))
                spaces[1] = mx_strlen(mx_itoa(file_stat.st_uid));
        }
        else {
            if (spaces[1] < mx_strlen(pw->pw_name))
                spaces[1] = mx_strlen(pw->pw_name);
        }

        if (gr == 0) {
            if (spaces[2] < mx_strlen(mx_itoa(file_stat.st_gid)))
                spaces[2] = mx_strlen(mx_itoa(file_stat.st_gid));
        }
        else {
            if (spaces[2] < mx_strlen(gr->gr_name))
                spaces[2] = mx_strlen(gr->gr_name);
        }

        if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode)) {
            char *hex = mx_nbr_to_hex(file_stat.st_rdev);
            if (file_stat.st_rdev != 0) {
                if (spaces[3] < mx_strlen("0x") + mx_strlen(hex))
                    spaces[3] = mx_strlen("0x") + mx_strlen(hex);
            }
            if (spaces[3] < mx_strlen(hex))
                spaces[3] = mx_strlen(hex);
            mx_strdel(&hex);
        }
        else {
            if (spaces[3] < mx_strlen(mx_itoa(file_stat.st_size)))
                spaces[3] = mx_strlen(mx_itoa(file_stat.st_size));
        }

    }
}

int mx_count_files(char *path) {
    struct dirent *entry = NULL;
    DIR *dir = opendir(path);
    int answer = 0;

    if (!dir)
        return answer;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.')
            answer++;
    }
    if (dir)
        closedir(dir);
    return answer;
}

