#include "main.h"

void interactive_mode(void)
{
    char *line = NULL;
    char *line_copy = NULL;
    size_t len = 0;
    ssize_t read;

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
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("Error reading input");
                exit(EXIT_FAILURE);
            }
        }

        line_copy = strdup(line);

        line_copy = strtok(line_copy, "\n");

        if (strcmp(line_copy, "exit") == 0)
        {
            free(line);
            free(line_copy);
            exit(EXIT_SUCCESS);
        }

        execute_command(line_copy);

        free(line_copy);
    }

    free(line);
}
