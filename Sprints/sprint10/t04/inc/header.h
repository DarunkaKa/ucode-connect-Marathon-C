#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printchar(char c);
void mx_printstr(const char *s);
bool mx_isspace(char c);
