#include "list.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *temp = list;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count; 
}

void mx_push_index(t_list **list, void *data, int index) {
    if (list == NULL || *list == NULL) {
        *list = mx_create_node(data);
    }
    else {
        int size = mx_list_size(*list);
        if (index <= 0) {
            mx_push_front(list, data);
        }
        else if (index >= size) {
            mx_push_back(list, data);
        }
        else {
            t_list *temp = *list;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            t_list *node_index = mx_create_node(data);
            node_index->next = temp->next;
            temp->next = node_index;
        }
    }
}

