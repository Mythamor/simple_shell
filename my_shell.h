#ifndef MY_SHELL
#define MY_SHELL

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 100

void displayPrompt(void);
char **parseCmd(char *cmd);
void exeCmd(char **args);
void execmd(char **argv);
int _strcmp(char *s1, char *s2);
void reportError(char *command);
int WIFEXITED_wrapper(int status);
int WEXITSTATUS_wrapper(int status);
char *my_fgets(char *str, int n, FILE *stream);
int my_execvp(char *file, char *const argv[]);
int my_feof(FILE *stream);
size_t my_strlen(const char *s);


#endif
