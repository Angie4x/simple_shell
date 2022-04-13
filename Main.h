#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _clear(char **args);
int _cd(char **args);
int _help(char **args);
int _exit(char **args);
int _ls(char **args);
int _pause(char **args);
int _echo(char **args);

#endif
