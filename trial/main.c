#include "main.h"

int main(int argc, char *argv[])
{
    if (isatty(STDIN_FILENO))
    {
        interactive_mode();
    }
    else
    {
        if (argc > 0)
        {
            non_interactive_mode(argv[0]);
        }
    }

    return 0;
}
