#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024
#define BUFFER_SIZE_READ 1024
#define BUFFER_SIZE_WRITE 1024
#define OR_FLAG 1
#define AND_FLAG 2
#define CHAIN_FLAG 3
#define USE_GETLINE 0
#define USE_STRTOK 0
#define MAX_WORD_COUNT 100
#define HIST_SIZE_MAX

extern char **environ;
int main(void)
{
        char base_dir[MAX_PATH_LENGTH] = "/path/to/base";
        char sub_dir[MAX_PATH_LENGTH] = "subdirectory";
        char file_name[MAX_PATH_LENGTH] = "file.txt";
        char path[MAX_PATH_LENGTH];

        /* Combine the base directory, subdirectory, and file name */
        snprintf(path, sizeof(path), "%s/%s/%s", base_dir, sub_dir, file_name);

        /* Print the constructed path */
        printf("%s\n", path);

        return (0);
}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */

typedef struct builtin
{
        char *type;
        int (*func)(info_s *);
} builtin_commands;

int access(const char *path, int mode);
int chdir(const char *path);
int close(int fd);
int closedir(DIR *dirp);
int execve(const char *pathname, char *const argv[], char *const envp[]);
void exit(int status);
void _exit(int status);
int fflush(FILE *stream);
pid_t fork(void);
void free(void *ptr);
char *getcwd(char *buf, size_t size);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
pid_t getpid(void);
int isatty(int fd);
int kill(pid_t pid, int sig);
void *malloc(size_t size);
int open(const char *pathname, int flags, mode_t mode);
DIR *opendir(const char *dirname);
void perror(const char *s);
ssize_t read(int fd, void *buf, size_t count);
struct dirent *readdir(DIR *dir);
void (*signal(int signum, void (*handler)(int)))(int);
void handler(int signum);
int stat(const char *path, struct stat *buf);
void (*signal(int signum, void (*handler)(int)))(int);
void handler(int signum);
int stat(const char *path, struct stat *buf);
int lstat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
char *strtok(char *str, const char *delimiters)
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
ssize_t write(int fd, const void *buf, size_t count);

#endif /* HEADER_H */
