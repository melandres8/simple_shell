#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIMS " \t\n\r\a"
extern char **environ;

/**
 * struct directories - struct directories
 * @direct: direct
 * @next: next
 */
typedef struct directories
{
	char *direct;
	struct directories *next;
} directs;

/*Handle the strings: functions*/
int _strlen(char *str);
char *_strcpy(char *fstr, char *sstr);
char *_strcat(char *fstr, char *sstr);
int _strcmp(char *s1, char *s2);
char **sep_str(char *input);

/*Handle errors: functions*/
void print_err(char *file, char *command, int nerror);

/*Environment functions*/
char *_getenv(char *name);
int penv(void);

/*Util funcs, handle the env variables*/
struct directories *add_node_end(struct directories **head, char *str);
void add_dir_to_struct(struct directories **head, char *directories);
char *_which(directs **head, char *dir);
int exect_commands(char *, directs *, int, char *, char **);
int verify_cases(char *lineptr, ssize_t rget);
void free_list(directs *head);
void free_dbl_arr(char **arr);
void free_mem(char *ruta, char **mcommands, char *lineptr);
int count_buffer(char *buffer);
char *_strdup(char *str);
int _strncmp(const char *first, const char *last, size_t count);
void logic(char *, directs *, int, char **, ssize_t, char **);

#endif /*HOLBERTON*/
