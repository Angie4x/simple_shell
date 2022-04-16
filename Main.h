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
int function_exit(char **args);
int _ls(char **args);
int _echo(char **args);
int command(char **args);
char *lecture(void);
int program_threads(char **args);
int _echo(char **args);
int _ls(char **args);
int function_exit(char **args);
int _help(char **args);
int _cd(char **args);
int length_array_bit(void);
int (array_function[])(char *);
char *array_info[];
char *array_str[];

#endif
