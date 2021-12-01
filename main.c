#include "hsh.h"
/**
 * main - Description
 * @argc: Description
 * @argv: Description
 * @env: Description
 * Return: Description
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv, char **env)
{
	int tty = 1;

	char *line;
	char *cpy_line;
	size_t lineSize = 0;

	char *slip;
	args_t *list_slip = NULL; 

	pid_t state_fork;
	int state_execve;
	int state_song;

	char **path = NULL;


	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	while (1)
	{
		/*Escribe y lee las lineas de entrada*/
		write(STDOUT_FILENO, "My_Shell_$",10);
		getline(&line,&lineSize, stdin);
		cpy_line = strdup(line);

		/*separa la linea por espacios*/
		while ((slip = strtok(cpy_line, " \t\n")))
		{
			 /*   printf("%s\n",slip);*/
			add_node(&list_slip,slip);
			cpy_line = NULL;
		}
		print_list(list_slip);

		/*si es 0 = hijo si es 1 = Padre y si es -1 = error*/
		state_fork = fork();
		if(state_fork == -1)
			return -1;
		else if(state_fork == 0)
		{
			/*doble puntero*/
			path = linkedList_to_doublePointer(&list_slip);
			state_execve = execve(path[0], path, env);
			if (state_execve == -1)
				return -1;
		}
		else
		{
			wait(&state_song);
		}
		list_slip = NULL;
	}
	return 0;
}



char **linkedList_to_doublePointer(args_t **head)
{
	int i;
	args_t *h = *head;
	char **arguments;

	/*cuenta la cantidad de nodos que hay en la lista*/
	  size_t size = 0;

	  while (h != NULL)
	{
		printf("%s\n", h->arg);
		h = h->next;
		size++;
	}

	arguments = malloc( (size + 1) * sizeof(char *));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		arguments[i] = h->arg;

	arguments[i] = NULL;

	return (arguments);
}
