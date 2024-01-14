#include "../inc/uls.h"

void mx_output_group(struct stat *stat, int count) {
    struct group *gr = getgrgid(stat->st_gid);

    if (gr == 0) {
        mx_printlonglong(stat->st_gid);
        for (int i = mx_strlen(mx_itoa(stat->st_gid)); i < count; i++)
            mx_printchar(' ');
    }
    else {
        mx_printstr(gr->gr_name);
        for (int i = mx_strlen(gr->gr_name); i < count; i++)
            mx_printchar(' ');
    }
    mx_printstr("  ");
}

void mx_output_size(struct stat *stat, int count) {
    if (S_ISCHR(stat->st_mode) || S_ISBLK(stat->st_mode)) {
        char *hex = mx_nbr_to_hex(stat->st_rdev);
        if (stat->st_rdev == 0) {
            for (int i = mx_strlen(hex); i < count; i++)
                mx_printchar(' ');
        }
        else {
            for (int i = mx_strlen(hex); i < count - mx_strlen("0x"); i++)
                mx_printchar(' ');
            mx_printstr("0x");
        }
        mx_printstr(hex);
        mx_strdel(&hex);
    }
    else {
        for (int i = mx_strlen(mx_itoa(stat->st_size)); i < count; i++)
            mx_printchar(' ');
        mx_printlonglong(stat->st_size);
    }
    mx_printchar(' ');
}

void mx_output_time(struct stat *stat) {
    char *time_str = ctime(&stat->st_mtime);
    char **time_array = mx_strsplit(time_str, ' ');

    char *month_str = time_array[1];
    char *day_str = time_array[2];

    time_t current_time = time(NULL);
    time_t half_year = (365 / 2) * 24 * 60 * 60;


    mx_printstr(month_str);
    mx_printchar(' ');
    if (mx_strlen(day_str) == 1)
        mx_printchar(' ');
    mx_printstr(day_str);
    mx_printchar(' ');

    if (stat->st_mtime + half_year <= current_time
        || stat->st_mtime >= current_time + half_year) {
        char *year_str = time_array[4];
        int new_line_index = mx_get_char_index(year_str, '\n');
        year_str[new_line_index] = '\0';
        mx_printchar(' ');
        mx_printstr(year_str);
    }
    else {
        char *time_str = time_array[3];
        char **time_arr = mx_strsplit(time_str, ':');
        char *hour = time_arr[0];
        char *minute = time_arr[1];

        mx_printstr(hour);
        mx_printchar(':');
        mx_printstr(minute);
    }
    mx_printchar(' ');
}

void mx_output_name(char *path,
                        struct stat *file_stat,
                        bool print) {
    if (print) {
        char **file_names = mx_strsplit(path, '/');
        char *file_name = file_names[mx_array_size(file_names) - 1];
        mx_printstr(file_name);
        mx_del_strarr(&file_names);
    }
    else {
        mx_printstr(path);
    }

    if ((file_stat->st_mode & S_IFMT) == S_IFLNK) {
        char buffer[PATH_MAX];
        ssize_t buffer_len = readlink(path, buffer, sizeof(buffer) - 1);

        if (buffer_len != -1) {
            buffer[buffer_len] = '\0';
            mx_printstr(" -> ");
            mx_printstr(buffer);
        }
    }

    mx_printchar('\n');
}

