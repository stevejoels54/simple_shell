#include "main.h"

/**
 * execute_command - Execute a command.
 *
 * @command: Command to be executed.
 *
 * This function parses the command into arguments,
 * checks if the command is executable,
 * and then executes it. If the command is not found,
 * it attempts to locate the command
 * in the directories listed in thhe PATH environment variable.
 */

void execute_command(char *command)
{
	char *args[64];
	int argCount = 0;

	char *token = strtok(command, " \t\n");

	while (token != NULL)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}

	args[argCount] = NULL;

	if (access(args[0], X_OK) == 0)
	{
		execute_child(args[0], args);
		return;
	}
	else
	{
		get_path(args, args[0]);
	}
}
