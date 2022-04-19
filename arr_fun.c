#include "Main.h"

/** functions call */
char (*array_str[256]) = {
	"clear",
	"cd",
	"help",
	"ls",
	"ls -a",
	"ls -l",
	"echo",
	"exit"
};

/** information statement */
char (*array_info[256]) = {
	"cd command is used to change the current working directory",
	"ls is a command to list computer files",
	"clear command that is used to clear the terminal screen",
	"command that outputs the strings that are passed to it as arguments",
	"exit command is used to exit from the current shell"
};

/** functions_array - function declaration */
int (*functions_array[256])(char **) = {
	&_clear,
	&_cd,
	&_help,
	&_ls,
	&_ls_a,
	&_ls_l,
	&_echo,
	&function_exit
};
