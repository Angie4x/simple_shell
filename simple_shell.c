#include "Main.h"

#define BUFSIZE 1024
#define TOK_BUFSIZE 64

/**
*length_array_bit - size function
*
*Return: sizeof array_str / sizeof char *
*/
int length_array_bit(void)
{
	return (sizeof(array_str) / sizeof(char *));
}

/**
*program_threads - start the program and wait for it to finish
*@args: arguments
*Return: 1
*/
int program_threads(char **args)
{
	/** declare the PID and the status */

	pid_t pid;
	int status;

	/** initiate fork */
	pid = fork();
	if (pid < 0)
		printf("not found \n");
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			printf("not foud\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
/**
*command - check the commands
*@args: arguents
*Return: program_threads(args)
*/
int command(char **args)
{
	int i = 0;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < length_array_bit(); i++)
	{
		if ((_strcmp(args[0], array_str[i]) == 0))
		{
			printf("%s", args[0]);
			return ((*functions_array[i])(args));
		}
	}
	return (program_threads(args));
}

/**
*lecture - read the command line
*
*Return: always 0
*/
char *lecture(void)
{
	int bufsize = BUFSIZE;
	int position = 0;
	int var;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		printf("not found\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		var = getchar(); /** character string */
		if (var == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else if (var == EOF)
			exit(EXIT_SUCCESS);
		else
			buffer[position] = var;
		position++;
	}
	if (position >= bufsize)
	{
		bufsize += BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer)
		{
			printf("not found\n");
			exit(EXIT_FAILURE);
		}
	}
}

/**
*split_line - separates the string of commands in a program and its arguments
*@line: variable name
*Return: Tokens
*/
char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		printf("not found\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				free(tokens_backup);
				printf("not found\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
