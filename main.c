#include "shell.h"

/**
 * main - entry point
 * @c: narg
 * @av: args
 * Return: 0 on success
 */
int main(int ac __attribute((unused)), char *av[] __attribute((unused)))
{
	struct stat st;
	ssize_t rget = 0;
	char *lineptr = NULL, **mcommands = NULL, *ruta = NULL;
	size_t n = 0;
	pid_t rfork = 0;
	int wstatus = 0, nerror = 1;
	directs *head = NULL;
	char *directories = _getenv("PATH");

	add_dir_to_struct(&head, directories);

	do {
		write(STDOUT_FILENO, "$ ", 2);
		rget = getline(&lineptr, &n, stdin);

		if (_strcmp(lineptr, "exit\n") == 0)
		{
			free(lineptr);
			return (0);
		}
		else if (rget == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			return (0);
		}
		else if (_strcmp(lineptr, "env\n") == 0)
		{
			penv();
			free(lineptr);
			return (0);
		}
		else
		{
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
						print_err(av[0], mcommands[0], nerror);
						return (127);
					}
				}
				else
				{
					wait(&wstatus);
				}
			}
		}
		nerror++;
	} while (rget != -1);

	return (0);
}
