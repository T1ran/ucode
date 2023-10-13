#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *answer;
    char *temp;
    int replace_size = mx_strlen(replace);
    int sub_size = mx_strlen(sub);
    int sub_count = mx_count_substr(str, sub);
    int answer_len = mx_strlen(str) + (replace_size - sub_size) * sub_count;

    if (!str || !sub || !replace)
        return NULL;
    
    answer = mx_strnew(answer_len);
    temp = answer;

    for (int i = 0; i < sub_count; i++) {
        int substr_index = mx_get_substr_index(str, sub);

        temp = mx_strncpy(temp, str, mx_get_substr_index(str, sub)) + substr_index;
        temp = mx_strcpy(temp, replace) + replace_size;
        str += substr_index + sub_size;
    }

    return answer;
}

