#include "main.h"

int main(void)
{
    if (isatty(STDIN_FILENO))
    {
        interactive_mode();
    }
    else
    {
        non_interactive_mode("./shell");
    }

    return 0;
}
