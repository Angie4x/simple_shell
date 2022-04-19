#include "Main.h"

/**
*_ls - list files or directories
*@args: arguments
*Return: 1
*/
int _ls(__attribute__ ((unused))char **args)
{
	system("ls");
	return (1);
}

/**
*_ls_a - enlist the whole list of the current directory
*including the hidden files.
*@args: arguments
*Return: 1
*/
int _ls_a(__attribute__ ((unused))char **args)
{
	system("ls -a");
	return (1);
}

/**
*_ls_l - to print files in a long listing format
*@args: arguments
*Return: 1
*/
int _ls_l(__attribute__ ((unused))char **args)
{
	system("ls -l");
	return (1);
}
