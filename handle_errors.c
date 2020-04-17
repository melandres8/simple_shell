#include "shell.h"

/**
 * print_err - Handle the command errors
 * @file: file
 * @command: command
 * @nerror: nerror
 */
void print_err(char *file, char *command, int nerror)
{
	char errmsg[720];

	sprintf(errmsg, "%s: %d: %s: not found\n", file, nerror, command);
	write(STDOUT_FILENO, errmsg, _strlen(errmsg));
}
/**
 * verify_cases - verify_cases
 * @lineptr: lineptr
 * @rget: rget
 * Return: int
 */
int verify_cases(char *lineptr, ssize_t rget)
{
	if (_strcmp(lineptr, "exit\n") == 0)
	{
		return (1);
	}
	else if (rget == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	else if (_strcmp(lineptr, "env\n") == 0)
	{
		penv();
		return (0);
	}
	return (0);
}
