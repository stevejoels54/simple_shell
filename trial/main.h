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
void execute_child(char *full_path, char *args[]);
void get_path(char *args[], char *command);
char *_getenv(const char *name);
void execute_command(char *command);
void interactive_mode(void);
void non_interactive_mode(void);
#endif /* MAIN_H */
