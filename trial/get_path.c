#include "main.h"

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
    if (!command_executed && strcmp(progname, "interactive") == 0)
        print_error("sh", args[0], 1);
    else
        print_error(progname, args[0], 1);
    free(dup_path);
}
