#include "main.h"

/**
 * execute_child - Execute a child process.
 *
 * @full_path: Full path to the executable file
 * @args: Array of arguments for the executable.
 *
 * Function forks a new process and executes the specified executable files.
 * If execution fails, an error message is printed and the child process exits
 * Parent process waits for the child process to complete before continuing.
 */

void execute_child(char *full_path, char *args[])
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			print_error(args[0], "command not found", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
