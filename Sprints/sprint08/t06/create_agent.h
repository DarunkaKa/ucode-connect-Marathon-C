#ifndef CREATE_AGENT_H
#define CREATE_AGENT_H

#include "agent.h"
#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);

t_agent *mx_create_agent(char *name, int power, int strength);

#endif

