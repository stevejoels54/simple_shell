#include "main.h"

void interactive_mode(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;
    char *line_copy = NULL;
    char *token = NULL;

    while (1)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            free(line);
            free(line_copy);
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
                free(line_copy);
                exit(EXIT_SUCCESS);
            }
            if (access(args[0], X_OK) == 0)
                execute_child(args[0], args);
            else
                get_path(args, args[0], "interactive");
            free(args);
        }
        free(line_copy);
        line_copy = NULL;
    }
}

