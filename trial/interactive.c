#include "main.h"

void interactive_mode(void)
{
    char *line = NULL;
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
        line = strtok(line, "\n");

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        execute_command(line);
    }
    free(line);
}
