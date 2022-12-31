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

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    int size = mx_list_size(list);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (cmp(list->data, list->next->data)) {
                void *temp_data = list->data;
                list->data = list->next->data;
                list->next->data = temp_data;
            }
            list = list->next;
        }
    }
    return list;
}

