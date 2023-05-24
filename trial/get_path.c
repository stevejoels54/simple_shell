#include "main.h"

void get_path(char **args, char *command, char *mode)
{
    char **paths = find_paths();
    char *full_path = NULL;
    int command_executed = 0;
    int i;

    for (i = 0; paths[i] != NULL; i++)
    {
        full_path = malloc(strlen(paths[i]) + strlen(command) + 2);
        if (!full_path)
        {
            perror("malloc");
            free(args);
            free(paths);
            return;
        }
        strcpy(full_path, paths[i]);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (access(full_path, X_OK) == 0)
        {
            execute_child(full_path, args);
            free(full_path);
            command_executed = 1;
            break;
        }
        free(full_path);
    }

    if (!command_executed && strcmp(mode, "interactive") == 0)
        print_error("sh", args[0], 1);

    free(paths);
}

