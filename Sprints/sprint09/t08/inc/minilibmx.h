#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
int mx_strncmp(const char *s1, const char *s2, int n);
