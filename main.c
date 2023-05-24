#include "main.h"

/**
 * main - Entry point of the program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing
 *        the arguments passed to the program.
 *
 * Return: 0 on successful execution.
 */

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
	return (0);
}
