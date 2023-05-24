#include "main.h"

/*void print_error(const char *program_name, const char *error_message, int line_number)
{
    const int BUFFER_SIZE = 100;
    char error[BUFFER_SIZE];
    int i;
    int line_number_copy;
    int line_number_digits;
    const int MAX_LINE_NUMBER_DIGITS = 10; // Maximum number of digits in a line number
    char line_number_str[MAX_LINE_NUMBER_DIGITS + 1];

    // Copy program name
    strcpy(error, program_name);
    strcat(error, ": ");

    // Add line number
    line_number_copy = line_number;
    line_number_digits = 0;
    while (line_number_copy > 0) {
        line_number_copy /= 10;
        line_number_digits++;
    }
   
    for (i = line_number_digits - 1; i >= 0; i--) {
        line_number_str[i] = '0' + (line_number % 10);
        line_number /= 10;
    }
    line_number_str[line_number_digits] = '\0';
    strcat(error, line_number_str);
    strcat(error, ": ");

    // Concatenate error message
    strncat(error, error_message, BUFFER_SIZE - strlen(program_name) - strlen(line_number_str) - 3); // -3 to account for ": " and null terminator

    // Add newline character
    strcat(error, "\n");

    write(STDERR_FILENO, error, strlen(error));
}*/

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

