#include "main.h"

/**
 * non_interactive_mode - Executes the program in non-interactive mode.
 *
 * This function reads a single line of input from the standard input
 * and executes the corresponding command.
 */

void non_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return;
	}

	line = strtok(line, "\n");

	execute_command(line);

	free(line);
}
