#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL)
        return;
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *current = *head;
    t_list *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    if (prev != NULL)
        prev->next = NULL;
    else
        *head = NULL;
}

