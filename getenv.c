#include "shell.h"

/**
 * _getenv - function to get the value of an environment variable
 * @name: name of the environment variable
 * Return: the value of the environment variable
 */
char *_getenv(char *name)
{
	char *dup = NULL, *token = NULL, *value = NULL;
	int i = 0;

	dup = malloc(sizeof(char) * _strlen(dup) + 7);
	_strcpy(dup, name);
	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (_strcmp(dup, environ[i]) == 0)
		{
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	free(dup);
	return (value);
}
