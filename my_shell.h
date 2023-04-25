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
char *strcpy(char *dest, const char *src);
char *strtok(char *str, const char *delim);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);


#endif
