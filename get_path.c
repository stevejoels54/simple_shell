#include "main.h"


/**
 * get_path - Search for the executable in the directories
 * listed in the PATH enviroment variable.
 *
 * @args: Array of command-line arguments.
 * @command: Name of the command to search for.
 * @progname: Name of the program.
 */

void get_path(char *args[], char *command, char *progname)
{
	char *path = _getenv("PATH");
	char *dir;
	char *dup_path = strdup(path);
	char *full_path = NULL;
	int command_executed = 0;

	dir = strtok(dup_path, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			perror("malloc");
			return;
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);
		dir = strtok(NULL, ":");

		if (access(full_path, X_OK) == 0)
		{
			execute_child(full_path, args);
			free(full_path);
			command_executed = 1;
			break;
		}
		free(full_path);
	}
	if (!command_executed)
	{
		print_error(progname, args[0], 1);
	}
	free(dup_path);
}

