#include "main.h"

void non_interactive_mode(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;
    char *line_copy = NULL;
    char *token = NULL;
    
    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        free(line);
        return;
    }

    line_copy = strdup(line);
    free(line);
    line = NULL;

    token = strtok(line_copy, "\n");
    if (token != NULL)
    {
        args = tokenize_input(token);
        if (strcmp(args[0], "exit") == 0)
        {
            free(args);
            free(line);
            exit(EXIT_SUCCESS);
        }
        if (access(args[0], X_OK) == 0)
            execute_child(args[0], args);
        else
            get_path(args, args[0], "non-interactive");
    }
    free(args);
    free(line);
}
