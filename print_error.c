#include "main.h"

/**
 * print_error - Prints an error message to the standard error.
 *
 * @program_name: The name of the program.
 * @failed_command: The name of the command that failed.
 * @error_number: The error number.
 */

void print_error(const char *program_name,
const char *failed_command, int error_number)
{
	/*const int BUFFER_SIZE = 100;*/
	char error[100];
	char error_number_str[11];

	sprintf(error_number_str, "%d", error_number);
	strcpy(error, program_name);
	strcat(error, ": ");
	strcat(error, error_number_str);
	strcat(error, ": ");
	strcat(error, failed_command);
	strcat(error, ": command not found\n");

	write(STDERR_FILENO, error, strlen(error));
}

