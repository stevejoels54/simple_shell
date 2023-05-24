#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Return: 0 on successful execution.
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}

	return (0);
}
