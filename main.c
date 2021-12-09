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
		line = read_Line();

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		cpy_line = _strdup(line);

		if (is_directory(cpy_line) == 1)
			list_path = split_path(path, cpy_line);
		else
			list_path = split_args(cpy_line);

		_execute(list_path, env, is_directory(cpy_line));
	free(line);
	free(list_path);
	free(cpy_line);
	}
	return (0);

}
