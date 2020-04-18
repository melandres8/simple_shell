#include "shell.h"

/**
 * main - entry point
 * @ac: narg
 * @av: args
 * @env: env
 * Return: 0 on success
 */
int main(int ac, char *av[], char **env)
{
	/*ssize_t rget = 0;
	char *lineptr = NULL;
	size_t n = 0;*/
	int nerror = 1;
	directs *head = NULL;
	char *directories = _getenv("PATH");
	(void)ac, (void)av;

	add_dir_to_struct(&head, directories);
	exect_commands("    asd  ", head, nerror, av[0], env);
/*
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	signal(SIGINT, &handle_signal);
	do {
		rget = getline(&lineptr, &n, stdin);
		if (rget == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		exect_commands(lineptr, head, nerror, av[0], env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		nerror++;
	} while (rget != -1);

	free(lineptr);
	free_list(head);*/
	return (0);
}

/**
 * exect_commands - exect_commands
 * @lineptr: lineptr
 * @head: head
 * @nerror: nerror
 * @av: av
 * @env: env
 * Return: int
 */
int exect_commands(char *lineptr, directs *head, int nerror,
		   char *av, char **env)
{
	char **mcommands = NULL, *ruta = NULL;
	struct stat st;
	pid_t rfork = 0;
	int wstatus = 0;

	mcommands = sep_str(lineptr);


	if (mcommands[0])
	{
		if (verify_cases(mcommands[0]) == 1)
		{
			free_list(head);
			free(mcommands);
			free(lineptr);
			exit(0);
		}
		if (stat(mcommands[0], &st) == 0)
			ruta = mcommands[0];
		else
		{
			ruta = _which(&head, mcommands[0]);
		}
		if (lineptr && _strncmp(lineptr, "\n", 1) && ruta)
		{
			rfork = fork();
			if (rfork == 0)
			{
				if (execve(ruta, mcommands, env) == -1)
				{
					print_err(av, mcommands[0], nerror);
					free(mcommands);
					if (ruta)
						free(ruta);
					free(lineptr);
					free_list(head);
					_exit(127);
				}
			}
			else
			{
				wait(&wstatus);
			}
		}
		else
		{
			print_err(av, mcommands[0], nerror);
		}
	}
	if (ruta)
		free(ruta);
	ruta = NULL;
	free(mcommands);
	return (0);
}
/**
 * free_dbl_arr - free_dbl_arr
 * @arr: arr
 */
void free_dbl_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;

	while (arr[i] != NULL)
		free(arr[i]), i++;
	free(arr);
}
/**
 * free_mem - free_mem
 * @ruta: ruta
 * @mcommands: mcommands
 * @lineptr: lineptr
 */
void free_mem(char *ruta, char **mcommands, char *lineptr)
{
	if (ruta)
		free(ruta);
	if (lineptr)
		free(lineptr);
	if (mcommands)
		free(mcommands);
}
