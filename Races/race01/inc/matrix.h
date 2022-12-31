#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int mx_add(int a, int b);
int mx_sub(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);

typedef struct s_operation {
	char op;
	int (*f)(int a, int b);
}				t_operation;

enum e_operation {
	SUB,
	ADD,
	MUL,
	DIV
};

char *mx_strtrim(const char *str);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
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
