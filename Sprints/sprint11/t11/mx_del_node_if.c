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
bool cmp(void *a, void *b) {
    if(a == b) {
        return true;
    }
    return false;
}

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    int size = mx_list_size(*list);
    t_list *temp = *list;
    for (int i = 0; i < size; i++) {
        if (cmp(temp->data, del_data) == true) {
            t_list *node_pop = temp->next;
            temp->next = node_pop->next;
            free(node_pop);
        }
        temp = temp->next;
    }        
}

