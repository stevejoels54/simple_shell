#include "main.h"

char *_getenv(const char *name)
{
    extern char **environ;
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        char *env_var = environ[i];
        char *env_name = env_var;
        const char *cmp_name = name;

        while (*env_name != '\0' && *cmp_name != '\0' && *env_name == *cmp_name)
        {
            env_name++;
            cmp_name++;
        }

        if (*env_name == '=' && *cmp_name == '\0')
        {
            return env_var + 1;
        }
    }

    return NULL;
}
