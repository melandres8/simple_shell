#include "shell.h"
/**
 * count_buffer - count_buffer
 * @buffer: buffer
 * Return: int
 */
int count_buffer(char *buffer)
{
	int counter = 0;
	char *copy = NULL, *token = NULL;

	copy = _strdup(buffer);

	token = strtok(copy, " ");

	while (token)
	{
		token = strtok(NULL, " ");
		counter++;
	}
	free(copy);

	return (counter);
}

/**
 * _strdup - duplicate a specific number of bytes from a string
 * @str: string to duplicate
 * Description: gets ptr duplicate of string pointed to by str.
 * Return: ptr to duplicate, or NULL if str = NULL or if not memory avaliable
 */
char *_strdup(char *str)
{
	int i, size;
	char *ar;

	if (str == 0)
	{
		return (NULL);
	}
	size = _strlen(str);
	ar = malloc((sizeof(char) * (size + 1)));
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ar[i] = str[i];
	}
	ar[i] = '\0';
	return (ar);
}
