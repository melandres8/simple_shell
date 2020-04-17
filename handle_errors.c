#include "shell.h"

/**
 * print_err - Handle the command errors
 * @file:
 * @command:
 * @nerror:
 */
void print_err(char *file, char *command, int nerror)
{
	char errmsg[720];
	sprintf(errmsg, "%s: %d: %s: not found\n", file, nerror, command);
	write(STDOUT_FILENO, errmsg, _strlen(errmsg));
}
