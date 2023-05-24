#include "main.h"

void non_interactive_mode(char *progname)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);

    if (read == -1)
    {
        free(line);
        return;
    }

    line = strtok(line, "\n");

    execute_command(line, progname);

    free(line);
}
