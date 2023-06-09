#include "main.h"

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
