#include "list.h"
void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    if (list == NULL || *list == NULL) {
        *list = node;
    }
    else {
        t_list *temp_node = *list;
        while (temp_node->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = node;
    }
}

