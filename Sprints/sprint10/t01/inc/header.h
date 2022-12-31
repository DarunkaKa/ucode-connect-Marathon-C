#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
