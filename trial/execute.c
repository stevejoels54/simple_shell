#include "main.h"

void execute_command(char *command, char *progname)
{
    char *args[64];
    int argCount = 0;
    char *token = NULL;

    if (!command)
        return;

    token = strtok(command, " \t\n");

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
        get_path(args, args[0], progname);
    }

}
