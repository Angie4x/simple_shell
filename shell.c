#include "Main.h"

#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/** functions call */
char (*array_str[]) = {
	"clear",
	"cd",
	"help",
	"ls",
	"echo",
	"exit"
};

/** information statement */
char (*array_info[]) = {
	"cd command is used to change the current working directory",
	"ls is a command to list computer files",
	"clear command that is used to clear the terminal screen",
	"command that outputs the strings that are passed to it as arguments",
	"exit command is used to exit from the current shell"
};

/** function declaration */
int (*array_function[])(char **) = {
	&_clear,
	&_cd,
	&_help,
	&_ls,
	&_echo,
	&function_exit
};

/**
*
*
*
*/
int length_array_bit(void)
{
	return (sizeof(array_str) / sizeof(char *));
}

/**
*
*
*
*/
int _cd(char **args)
{
	/** we ask if the argument is different to NULL or is empty */
	if (args[1] != NULL && args[1] != "")
	{
		if (chdir(args[1]) != 0)
			printf("directory <%s> not found \n", args[1]);
	}
	else
		printf("specifies an argument \"cd\"\n");
	system("pwd");
	return (1);
}

/**
*
*
*
*/
int _help(char **args)
{
	printf("Welcome to my personal shell\n");
	int i = 0;

	for (i = 0; i < length_array_bit() - 1; i++)
		printf(" %s\n", array_info[i]);
	return (1);
}

/**
*
*
*
*/
int function_exit(char **args)
{
	return (0);
}

/**
*
*
*
*/
int _ls(char **args)
{
	system("ls");
	return (1);
}

/**
*
*
*
*/
int _echo(char **args)
{
	if (args[1] == NULL || args[1] == "")
		printf("specifies an argument\n");
	else
		printf("%s\n", args[1]);
	return (1);
}

/**
*
*
*
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
*
*
*
*/
int command(char **args)
{
	int i = 0;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < length_array_bit(); i++)
	{
		if (_strcmp(args[0], array_str[i] == 0)
			return ((*array_function[i])(args));
	}
	return (program_threads(args));
}

/**
*
*
*
*/
char *lecture(void)
{
	int bufsize = BUFSIZE;
	int position = 0;
	int var = 0;
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
	}
	position++;
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
 *separates the string of commands in a program and its arguments
 */
char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
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
		
		if (position >=bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));

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
	return tokens;
}

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("%dShellAngie~$ ",system("pwd"));
		if(argv[1] !=NULL)
		{
			line =argv[1];
		}
		else
		{
			line = lecture();
		}
		args = split_line(line);
		status = command(args);
		free(line);
 		free(args);
	}
	while (status);
	return EXIT_SUCCESS;
}
