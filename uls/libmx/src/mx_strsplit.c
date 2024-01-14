#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int words_count = mx_count_words(s, c);
    char **answer = malloc(sizeof(char *) * (words_count + 1));
    int index = 0;
    int start = 0;

    if (!answer || !s)
        return NULL;

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != c) {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            answer[index] = mx_strndup(&s[start], i - start);
            if (answer[index] == NULL) {
                for (int j = 0; j < index; j++)
                    mx_strdel(&answer[j]);
                free(answer);
                return NULL;
            }
            index++;
            if (s[i] == '\0')
                break;
        }

    answer[index] = NULL;
    return answer;
}
