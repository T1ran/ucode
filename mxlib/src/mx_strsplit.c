#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    char **answer;
    int word_count = 0;
    int word_len = 0;
    int len = 0;
    int index = 0;

    if (s == NULL)
        return NULL;

    word_count = mx_count_words(s, c);
    len = mx_strlen(s);
    answer = (char **)malloc((word_count + 1) * sizeof(char *));

    if (answer == NULL)
        return NULL;

    for (int i = 0; i <= len; i++) {
        if (s[i] == c || s[i] == '\0') {
            if (word_len > 0) {
                answer[index] = mx_strndup(s + i - word_len, word_len);
                if (answer[index] == NULL) {
                    mx_strdel(answer);
                    return NULL;
                }
                index++;
                word_len = 0;
            }
        } else {
            word_len++;
        }
    }

    return answer;
}

