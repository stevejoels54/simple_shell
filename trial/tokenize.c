#include "main.h"

char **tokenize_input(char *input_line)
{
    int argCount;
    char *token;
    char **args = malloc(64 * sizeof(char *));
    if (args == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    argCount = 0;
    if (input_line != NULL)
        input_line = strdup(input_line);
    else
        return NULL;

    token = strtok(input_line, " \t\n");
    while (token != NULL && argCount < 63)
    {
        args[argCount++] = token;
        token = strtok(NULL, " \t\n");
    }

    args[argCount] = NULL;
    return args;
}

