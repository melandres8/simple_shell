#include "shell.h"

/**
 * _strlen - function that count how many elements are in a string
 * @str: String the it will count the elements
 * Return: the number of characters of a string
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - Copie a string pointed
 * @sstr: Destination
 * @fstr: Sender
 * Return: A char
 */
char *_strcpy(char *fstr, char *sstr)
{
	int i = 0, j;

	while (sstr[i] != '\0')
		i++;

	for (j = 0; j <= i; j++)
		fstr[j] = sstr[j];

	return (fstr);
}

/**
 * _strcmp - function to compare if two string are equals.
 * @s1: string to be compared with s2
 * @s2: string to be compared with s1
 * Return: 0 if the strings are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}

/**
 * _strcat - function that concat two string
 * @fstr: first string
 * @sstr: second string
 * Return: char that contains the two string concatenated.
 */
char *_strcat(char *fstr, char *sstr)
{
	char *concat = NULL;
	int lens1 = 0, lens2 = 0, i = 0, j = 0;

	lens1 = _strlen(fstr);

	lens2 = _strlen(sstr);

	concat = malloc((lens1 + lens2 + 7));

	for (i = 0; i < lens1; i++)
	{
		concat[i] = fstr[i];
	}

	for (j = 0; i < (lens1 + lens2); i++, j++)
	{
		concat[i] = sstr[j];
	}
	concat[i] = '\0';

	return (concat);
}

/**
 * sep_str - sep_str
 * @input: input
 * Return: char**;
 */
char **sep_str(char *input)
{
	int i = 0;
	char **args = NULL, *token = NULL;

	args = malloc(sizeof(char *) * (count_buffer(input) + 1));

	if (args == NULL)
	{
		free(input);
		return (NULL);
	}

	token = strtok(input, DELIMS);

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, DELIMS);
		i++;
	}
	args[i] = NULL;

	return (args);
}
