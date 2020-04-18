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
 * Return: int
 */
int verify_cases(char *lineptr)
{
	if (_strncmp(lineptr, "exit", 4) == 0)
	{
		return (1);
	}
	else if (_strncmp(lineptr, "env", 3) == 0)
	{
		penv();
		return (0);
	}
	return (0);
}

/**
 * handle_signal - the Signal Handler
 * @sig: Signal number.
 */

void handle_signal(int sig)
{
	write(STDIN_FILENO, "\n$ ", 3);
	fflush(stdout);
	(void)sig;
}
