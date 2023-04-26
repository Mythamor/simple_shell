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

/**
 * struct list - linked list for environment variables
 * @var: holds string for environ variable
 * @next: points to the next node
 */

typedef struct list
{
	char *var;
	struct list *next;
} list_t;

void displayPrompt(void);
char **parseCmd(char *cmd);
void exeCmd(char **args);
void execmd(char **argv);
int _strcmp(char *s1, char *s2);
int WIFEXITED_wrapper(int status);
int WEXITSTATUS_wrapper(int status);
char *my_fgets(char *str, int n, FILE *stream);
int my_execvp(char *file, char *const argv[]);
int my_feof(FILE *stream);

#endif
