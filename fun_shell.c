#include "Main.h"

/**
*_cd - change the current working directory
*@args: arguments
*Return: 1
*/
int _cd(char **args)
{
	/** we ask if the argument is different to NULL or is empty */
	if (args[1] != NULL)
	{
		if (chdir(args[1]) != 0)
			printf("directory <%s> not found \n", args[1]);
	}
	else
		printf(" specifies an argument \"cd\"\n");
	system("pwd");
	return (1);
}

/**
*_help - rganize long shell scripts into modular and reusable code blocks.
*@args: arguments
*Return: 1
*/
int _help(__attribute__ ((unused)) char **args)
{
	int i;

	printf("Welcome to my personal shell\n");
	for (i = 0; i < length_array_bit() - 1; i++)
		printf(" %s\n", array_info[i]);
	return (1);
}


/**
*function_exit - can return a value via its exit status after execution
*@args: arguments
*Return: always 0
*/
int function_exit(__attribute__ ((unused))char **args)
{
	return (0);
}

/**
*_clear - used to bring the command line on top of the computer terminal.
*@args: arguments
*Return: 1
*/
int _clear(char **args)
{
	if (args[1])
		system("clear");
	return (1);
}

/**
*_echo - outputs the strings that are passed to it as arguments
*@args: arguments
*Return: 1
*/
int _echo(char **args)
{
	if (args[1] == NULL)
		printf("specifies an argument\n");
	else
		printf("%s\n", args[1]);
	return (1);
}
