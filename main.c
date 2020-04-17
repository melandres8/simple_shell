#include "shell.h"

/**
 * main - entry point
 * @c: narg
 * @av: args
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	ssize_t rget = 0;
	char *lineptr = NULL;
	size_t n = 0;
	int nerror = 1;
	directs *head = NULL;
	char *directories = _getenv("PATH");
	(void)ac, (void)av;

	add_dir_to_struct(&head, directories);

	do {
		write(STDOUT_FILENO, "$ ", 2);
		rget = getline(&lineptr, &n, stdin);

		if (verify_cases(lineptr, rget) == 1)
		{
			free_list(head);
			free(lineptr);
			return (0);
		}
		else
		{
			exect_commands(lineptr, head, nerror, av[0]);
		}
		nerror++;
	} while (rget != -1);

	return (0);
}

int exect_commands(char *lineptr, directs *head, int nerror, char *av)
{
	char **mcommands = NULL, *ruta = NULL;
	struct stat st;
	pid_t rfork = 0;
	int wstatus = 0;

	mcommands = sep_str(lineptr);
	if (stat(mcommands[0], &st) == 0)
		ruta = mcommands[0];
	else
	{
		ruta = _which(&head, mcommands[0]);
	}
	if (lineptr && _strcmp(lineptr, "\n") && mcommands[0])
	{

		rfork = fork();
		if (rfork == 0)
		{
			if (execve(ruta, mcommands, environ) == -1)
			{
				print_err(av, mcommands[0], nerror);
				free_mem(ruta, mcommands);
				_exit(127);
			}
		}
		else
		{
			wait(&wstatus);
		}
	}
	free_mem(ruta, mcommands);
	return (0);
}

void free_dbl_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;

	while (arr[i] != NULL)
		free(arr[i]), i++;
	free(arr);
}

void free_mem(char *ruta, char **mcommands)
{
	if (!ruta)
		free(ruta);
	if (!mcommands)
		free_dbl_arr(mcommands);	
}