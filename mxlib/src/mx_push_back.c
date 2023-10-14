#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *temp;
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }

    temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = mx_create_node(data);
}

