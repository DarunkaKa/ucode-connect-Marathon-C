#include "list.h"

void mx_clear_list(t_list **list) {
    t_list *temp = *list;
    while (temp->next != NULL) {
        t_list *temp_node = temp;
        temp_node = temp_node->next;
        free(temp_node);
        temp_node->next = NULL;
    }
    free(*list);
    (*list)->next = NULL;
}

