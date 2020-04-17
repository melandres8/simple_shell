#include "shell.h"

/**
 * _getenv - function to get the value of an environment variable
 * @name: name of the environment variable
 * Return: the value of the environment variable
 */
char *_getenv(char *name)
{
	char *path = name;
	int i = 0;

	while (environ[i])
	{

		if (_strncmp(environ[i], path, 4) == 0)
		{
			break;
		}
		i++;
	}
	return (environ[i]);
}


/**
 * _strncmp - Compare two strings
 * @first: string
 * @last: string
 * @count: n size of bytes to compare
 * Description: compares the first (at most) n bytes of s1 and s2.
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */
int _strncmp(const char *first, const char *last, size_t count)
{
	if (!count)
		return (0);

	while (--count && *first && *first == *last)
	{
		first++;
		last++;
	}

	return (*first - *last);
}
