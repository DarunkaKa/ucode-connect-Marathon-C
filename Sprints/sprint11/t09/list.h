#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}               t_list;

void mx_foreach_list(t_list *list, void (*f)(t_list*node));

