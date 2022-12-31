#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *str);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);

