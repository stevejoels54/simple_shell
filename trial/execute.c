#include "main.h"

void execute_command(char *command, char *progname)
{
    char *args[64];
    int argCount = 0;
    char *token = NULL;
    // int command_executed = 0;

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
        // command_executed = 1;
        return;
    }
    else
    {
        get_path(args, args[0], progname);
    }

    // if (access(args[0], X_OK) != 0 && !command_executed)
    // {
    //     get_path(args, args[0], progname);
    // }
    
    // if (!command_executed && access(args[0], X_OK) == 0)
    // {
    //     print_error(progname, args[0], 1);
    // }
}
