#include "hsh.h"
/**
 * main - Description
 * @argc: Description
 * @argv: Description
 * @env: Description
 * Return: Description
 */

int main(int argc, char **argv, char **env)
{
	char *path = getenv("PATH");
	char *line;
	args_t *list_path;

	char *cpy_line;
	int state = 1;
	(void)argc;
	(void)argv;

	while (state)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "My_Shell_$", 10);
		line = read_Line();
		fflush(stdin);
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		else if (_strcmp(line, "env") == 0)
			print_env(env);
		else
		{
		cpy_line = _strdup(line);

		if (is_directory(cpy_line) == 1)
			list_path = split_path(path, cpy_line);
		else
			list_path = split_args(cpy_line);
		_execute(list_path, env, is_directory(cpy_line));
		free(list_path);

		free(cpy_line);
		}
	free(line);
	}
	return (0);
}
