#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int answer = 0;

    t_list *temp = list;
    while (temp) {
        answer++;
        temp = temp->next;
    }

    return answer;
}

