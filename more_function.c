#include "hsh.h"
/**
 * launch - launch the command
 * @list_slip: arguments of command
 * @env: enviroment of launch
 * Return: state of execuve
 */
int launch(args_t *list_slip, char **env)
{
	int state_execve;
	char **path = NULL;
	
	path = linkedList_to_doublePointer(&list_slip);
	state_execve = execve(path[0], path, env);

	if (state_execve == -1)
		return (-1);
	free(path);
	return (1);
}

/*
 * print_env() - Prints the environmental
 * @env: The current environment from the main function.
 */
void print_env(char **env) 
{
	int i;

	for (i = 0; env[i]; i++) 
	{
			printf("%s\n",env[i]);
	}
}

