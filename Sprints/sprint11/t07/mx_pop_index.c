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

void mx_pop_index(t_list **list, int index) {
    int size = mx_list_size(*list);
    if (index <= 0) {
        mx_pop_front(list);
    }
    else if (index >= size) {
        mx_pop_back(list);
    }
    else {
        t_list *temp = *list;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        t_list *node_pop = temp->next;
        temp->next = node_pop->next;
        free(node_pop);
    }
}

