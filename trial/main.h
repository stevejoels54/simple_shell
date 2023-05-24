#ifndef MAIN_H
#define MAIN_H

/*
 * @Desc: Header file containing the function prototypes for simple_shell.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
char **find_paths(void);
char **tokenize_input(char *input_line);
void print_error(const char *program_name, const char *failed_command, int error_number);
void execute_child(char *full_path, char *args[]);
void get_path(char **args, char *command, char *mode);
char *_getenv(const char *name);
void interactive_mode(void);
void non_interactive_mode(void);
#endif /* MAIN_H */
