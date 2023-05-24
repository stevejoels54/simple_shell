#include "main.h"
#include <signal.h>

void interactive_mode(void)
{
    char *line = NULL;
    char *line_copy = NULL;
    size_t len = 0;
    ssize_t read;
    char *token = NULL;

    while (1)
    {
        printf("sh: ");
        fflush(stdout);

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (feof(stdin))
            {
                free(line);
                free(line_copy);
                exit(EXIT_SUCCESS);
            }
        }

        line_copy = strdup(line);
        free(line);
        line = NULL;

        token = strtok(line_copy, "\n");

        if (token != NULL && strcmp(token, "exit") == 0)
        {
            free(line_copy);
            exit(EXIT_SUCCESS);
        }
        execute_command(token, "interactive");
        free(line_copy);
        line_copy = NULL;
    }
free(line);
}
