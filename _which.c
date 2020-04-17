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
	directs *copy;
	char *ruta = NULL;
	char *rutaComp = NULL;

	copy = *head;
	ruta = _strcat("/", dir);

	while (copy != NULL)
	{

		rutaComp = _strcat(copy->direct, ruta);
		if (stat(rutaComp, &st) == 0)
			break;

		free(rutaComp);
		rutaComp = NULL;
		copy = copy->next;
	}
	if (rutaComp)
	{
		free(ruta);
		ruta = rutaComp;

		return (ruta);
	}
	else
	{
		free(ruta);
		return (NULL);
	}

	return (ruta);
}
