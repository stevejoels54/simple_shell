#include "main.h"

void print_error(const char *program_name, const char *failed_command, int error_number)
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

