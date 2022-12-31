#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}               t_list;

int mx_strcmp(const char *s1, const char *s2);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b));

