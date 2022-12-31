#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_agent {
    char *name;
    int power;
    int strength;
}   t_agent;

void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);
int mx_strcmp(const char *s1, const char *s2);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
