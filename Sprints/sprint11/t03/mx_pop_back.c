#include "list.h"
void mx_pop_back(t_list **list) {
    if (list != NULL || *list != NULL) {
        if ((*list)->next != NULL) {
           t_list *temp = *list;
           while (temp->next->next != NULL) {
                temp = temp->next;
           }
           free(temp->next);
           temp->next = NULL;
           temp = NULL;
        }
        free(*list);
        *list = NULL;
    }
    return;
}

