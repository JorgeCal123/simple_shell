#include "hsh.h"
/**
 * read_Line - read the first line
 * Return: value type char
 */
char *read_Line()
{
	char *line;
	size_t lineSize = 0;

	write(STDOUT_FILENO, "My_Shell_$ ", 10);

	if (getline(&line, &lineSize, stdin) == EOF)
	{
		write(1, "\n", 1);
		exit(0);
	}
	return (line);
}
/**
 * split_args - separate all arguments
 * @args: line with arguments
 * Return: structure type args_t with arguments
 */
args_t *split_args(char *args)
{

	args_t *list_slip = NULL;
	char *line = strdup(args);
	char *slip;

	while ((slip = strtok(line, " \t\n")))
	{
		add(&list_slip, slip);
		line = NULL;
	}
	return (list_slip);
}
/**
 * split_path - separete the arguments from path
 * @path: contain all directions from path
 * @lin: is the command to execute
 * Return: structure type args_t with arguments from path
 */
args_t *split_path(char *path, char *lin)
{
	char *line = strdup(path);
	char *slip;
	char *node_dir;

	args_t *list_slip = NULL;

	while ((slip = strtok(line, ":")))
	{
		node_dir = _strcat(slip, "/");
		node_dir = _strcat(node_dir, lin);
		add(&list_slip, node_dir);

		line = NULL;
	}

	return (list_slip);
}
/**
 * is_directory - found if the line es a diretory
 * @line: line to verificated
 * Return: 1 if not is directory and 0 if is directory
 */
int is_directory(char *line)
{

	int pos = 0;
	int found = 1;

	while (line[pos] != '\0' && found)
	{
		if (line[pos] == '/')
			found = 0;
		pos++;
	}

	return (found);
}
/**
 * _execute - run a command
 * @dir: is the command or direction
 * @env: is the enviroment of execution
 * @type: type of command a direccion or command
 * Return: State of execute
 */
int _execute(args_t *dir, char **env, int type)
{
	pid_t state_fork;
	int state_execve;
	int state_song;
	args_t *list_slip;
	char **path = NULL;

	state_fork = fork();
	if (state_fork == -1)
		return (-1);
	else if (state_fork == 0)
	{
		if (type == 1)
		{
			while (dir != NULL)
			{
				list_slip = split_args(dir->arg);
				path = linkedList_to_doublePointer(&list_slip);
				state_execve = execve(path[0], path, env);
				dir = dir->next;
			}
			if (state_execve == -1)
				return -1;
		}
		else
		{
			list_slip = dir;
			path = linkedList_to_doublePointer(&list_slip);
			state_execve = execve(path[0], path, env);
			if (state_execve == -1)
				return -1;
		}
	}
	else
	wait(&state_song);

	free(path);

	return (0);
}
