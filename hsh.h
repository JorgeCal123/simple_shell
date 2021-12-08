#ifndef HSH_H
#define HSH_H
/*LIBRARIES*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/*structure main.c*/
/**
 * struct args_s - contain all arguments
 * @arg: arguments and command
 * @next: value of next structure
 */
typedef struct args_s
{
	char *arg;
	struct args_s *next;
} args_t;

/*list_cmd.c*/
size_t size_list(const args_t *h);
size_t print_list(const args_t *h);
args_t *add(args_t **head, char *arg);
char **linkedList_to_doublePointer(args_t **head);

/*function_shell.c*/
char *read_Line();
int is_directory(char *line);
args_t *split_args(char *args);
args_t *split_path(char *path, char *lin);
int _execute(args_t *dir, char **env, int type);


/*str.c*/
char *_strcat(char *s1, char *s2);

#endif
