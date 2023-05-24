#include "main.h"

char **find_paths(void)
{
    char *path = _getenv("PATH");
    char *dir;
    int pathCount;

    char **paths = malloc(64 * sizeof(char *));
    if (paths == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    pathCount = 0;
    dir = strtok(path, ":");
    while (dir != NULL && pathCount < 63)
    {
        paths[pathCount++] = dir;
        dir = strtok(NULL, ":");
    }

    paths[pathCount] = NULL;

    return paths;
}

