#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *current_node = lst;
    t_list *next_node;

    if (lst == NULL)
        return lst;

    while (current_node) {
        next_node = current_node->next;
        while (next_node) {
            if (cmp(current_node->data, next_node->data)) {
                void *temp = current_node->data;
                current_node->data = next_node->data;
                next_node->data = temp;

            }
            next_node = next_node->next;
        }
        current_node = current_node->next;
    }

    return lst;
}

