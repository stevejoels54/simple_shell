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
	char *line_copy = NULL;
	size_t len = 0;
	ssize_t read;
	char *command = NULL;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		free(line_copy);
		exit(EXIT_SUCCESS);
	}

	line_copy = strdup(line);
	command = strtok(line_copy, "\n");

	if (strcmp(command, "exit") == 0)
	{
		free(line);
		free(line_copy);
		exit(EXIT_SUCCESS);
	}
	execute_command(command, progname);
	free(line);
	free(line_copy);
	line_copy = NULL;
	line = NULL;
}


