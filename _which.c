#include "shell.h"

/**
 * _which - function to get the Path of a binary file
 * @head: pointer to the first element of a linked list that contains the
 * the directions where can be allocated the binary file
 * @dir: name of a binary file that we will search
 * Return: the path where the binary file is located
 */
char *_which(directs **head, char *dir)
{
	struct stat st;
	directs *dup = *head;
	char *ruta = NULL;
	char *rutaComp = NULL;

	if (stat(dir, &st) == 0)
	{
		return (dir);
	}
	else
	{
		while (dup != NULL)
		{
			ruta = _strcat(dup->direct, "/");
			rutaComp = _strcat(ruta, dir);
			if (stat(rutaComp, &st) == 0)
			{
				free(ruta);
				return (rutaComp);
			}
			dup = dup->next;
			free(ruta);
			free(rutaComp);
		}
	}
	return (dir);
}
