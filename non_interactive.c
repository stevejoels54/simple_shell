#include "main.h"

/**
 * non_interactive_mode - Executes the program in non-interactive mode.
 * @progname: The name of the program.
 *
 * This function reads a single line of input from the standard input
 * and executes the corresponding command.
 */

void non_interactive_mode(char *progname)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	line = strtok(line, "\n");

	execute_command(line, progname);

	free(line);
}

