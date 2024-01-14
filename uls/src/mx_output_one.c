#include "../inc/uls.h"

void mx_output_mode(mode_t mode) {
    switch (mode & S_IFMT) {
        case S_IFBLK:
            mx_printchar('b');
            break;
        case S_IFCHR:
            mx_printchar('c');
            break;
        case S_IFDIR:
            mx_printchar('d');
            break;
        case S_IFLNK:
            mx_printchar('l');
            break;
        case S_IFIFO:
            mx_printchar('p');
            break;
        case S_IFSOCK:
            mx_printchar('s');
            break;
        case S_IFWHT:
            mx_printchar('w');
            break;
        default:
            mx_printchar('-');
    }
}

void mx_output_rights(struct stat *stat) {
    mx_printchar((stat->st_mode & S_IRUSR) ? 'r' : '-');
    mx_printchar((stat->st_mode & S_IWUSR) ? 'w' : '-');
    mx_printchar((stat->st_mode & S_IXUSR) ? 'x' : '-');
    mx_printchar((stat->st_mode & S_IRGRP) ? 'r' : '-');
    mx_printchar((stat->st_mode & S_IWGRP) ? 'w' : '-');
    mx_printchar((stat->st_mode & S_IXGRP) ? 'x' : '-');
    mx_printchar((stat->st_mode & S_IROTH) ? 'r' : '-');
    mx_printchar((stat->st_mode & S_IWOTH) ? 'w' : '-');
    mx_printchar((stat->st_mode & S_IXOTH) ? 'x' : '-');
}

void mx_output_additional(char *path) {
    ssize_t xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(path, ACL_TYPE_EXTENDED);

    if (xattr > 0) {
        mx_printchar('@');
        if (acl != NULL)
            acl_free(acl);
    }
    else if (acl != NULL) {
        mx_printchar('+');
        acl_free(acl);
    }
    else {
        mx_printchar(' ');
    }
    mx_printchar(' ');
}

void mx_output_links(struct stat *stat, int count) {
    for (int i = mx_strlen(mx_itoa(stat->st_nlink)); i < count; i++)
        mx_printchar(' ');
    mx_printint(stat->st_nlink);
    mx_printchar(' ');
}

void mx_output_owner(struct stat *stat, int count) {
    struct passwd *pw = getpwuid(stat->st_uid);

    if (pw == 0) {
        mx_printlonglong(stat->st_uid);
        for (int i = mx_strlen(mx_itoa(stat->st_uid)); i < count; i++)
            mx_printchar(' ');
    }
    else {
        mx_printstr(pw->pw_name);
        for (int i = mx_strlen(pw->pw_name); i < count; i++)
            mx_printchar(' ');
    }
    mx_printstr("  ");
}

