#include "main.h"

/**
 * check_path - Checks and adjusts the command path if necessary.
 * @env: The environment variables.
 * @array: The array of tokens representing the command and its arguments.
 * @mode: The execution mode (interactive or non-interactive).
 * @prog_name: The name of the current program.
 * Return: The adjusted command path.
 */

char *check_path(char **env, char **array, int mode, char *prog_name)
{
	char *temp;

	if (strstr(array[0], "/") == NULL)
	{
		if (built_ins(array, env) == 1)
			temp = find_path(env, array[0]);
		if (temp == NULL && mode == 0)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, array[0]);
			exit(127);
		}
		if (temp != NULL)
			array[0] = find_path(env, array[0]);
	}
	return (array[0]);
}
