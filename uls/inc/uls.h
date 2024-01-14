#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int mx_array_size(char **arr);
void mx_print_error(char *text);
void mx_print_error_char(char text);
int mx_isalpha(char c);
void mx_printlonglong(long long n);

//mx_uls.c
void mx_uls(int argc, char *argv[]);


char **mx_get_names(char *path, int *dirents_count);
char **mx_get_files(int files_count, char *path);

void mx_output_default(char **files, int files_count);

void mx_output_files(char **file_arr, int files_count);
void mx_output_dir(char **dir, int dir_count, int files_count, bool error);
void mx_output_dirents(char *path);
void mx_output_blocks(char **path, int files_count);
void mx_output_blocks_dir(char *path);

void mx_output_info(struct stat *file_stat,
                    char *path,
                    int *spaces,
                    bool print);

//used in output_info
//mx_output_one.c
void mx_output_mode(mode_t mode);
void mx_output_rights(struct stat *stat);
void mx_output_additional(char *path);
void mx_output_links(struct stat *stat, int count);
void mx_output_owner(struct stat *stat, int count);
//mx_output_two.c
void mx_output_group(struct stat *stat, int count);
void mx_output_size(struct stat *stat, int count);
void mx_output_time(struct stat *stat);
void mx_output_name(char *path, struct stat *file_stat, bool print);

//mx_handle.c
void mx_handle_standard(bool flag_l);
void mx_handle_files(int argc, char *argv[], bool flag_l, int flags_count);
void mx_handle_long(char **path, int files_count, bool print);
void mx_handle_long_dir(char **path, 
                        int dir_count,
                        int files_count,
                        bool error);

//mx_process.c
int mx_process_files(int files_count_i, char **files_i, bool flag_l);
void mx_process_dir(int files_count_i,
                    char **files_i,
                    int files_count,
                    bool error,
                    bool flag_l);

//mx_helpers.c
bool mx_is_dir(char *path);
void mx_spaces(char **path, int files_count, int *spaces);
void mx_sort(int size, char *array[size]);
int mx_count_files(char *path);

#endif
