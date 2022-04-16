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
int _help(__attribute__ ((unused)) char **args);
int _ls(__attribute__ ((unused))char **args);
int _echo(char **args);
int command(char **args);
char *lecture(void);
int program_threads(char **args);
int function_exit(__attribute__ ((unused))char **args);
int length_array_bit(void);
int ((*functions_array[256])(char **));
char *array_info[256];
char *array_str[256];
char **split_line(char *line);
int main(int argc, char **argv);

#endif
