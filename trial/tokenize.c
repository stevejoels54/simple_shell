#include "main.h"

char **tokenize_input(char *input_line)
{
    char **args = NULL;
    char *token = NULL;
    int i = 0;

    args = malloc(sizeof(char *));
    if (args == NULL)
        return (NULL);

    token = strtok(input_line, " \t\n");
    while (token != NULL)
    {
        args[i] = strdup(token);
        if (args[i] == NULL)
        {
            free_args(args, i);
            return (NULL);
        }
        i++;
        args = realloc(args, (i + 1) * sizeof(char *));
        if (args == NULL)
        {
            free_args(args, i);
            return (NULL);
        }
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return (args);
}

void free_args(char **args, int len)
{
    int i;

    for (i = 0; i < len; i++)
        free(args[i]);
    free(args);
}
