#include "Main.h"

/**
*main - function that execute the project
*@argc: stands for argument count
*@argv: stands for argument values
*Return: success
*/
int main(__attribute__ ((unused))int argc, char **argv)
{
	char *line;
	char **args = 0;
	int status;

	do {
		printf("simple_shell ");
		if (argv[1] != NULL)
		{
			line = argv[1];
		}
		else
		{
			line = lecture();
		}
		args = split_line(line);
		status = command(args);
		free(line);
		free(args);
	} while (status);
	return (EXIT_SUCCESS);
}
