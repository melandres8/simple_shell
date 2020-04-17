#include "shell.h"

/**
 * penv - function to print the environment valiables
 * Return: 0 on success
 */
int penv(void)
{
	int len = 0, i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
