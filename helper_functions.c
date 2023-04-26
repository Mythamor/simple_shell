#include "my_shell.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}

/**
 * WIFEXITED_wrapper -  Returns true if the process terminated normally
 * @status: the status
 * Return: numeric status
 */

int WIFEXITED_wrapper(int status)
{
	return (WIFEXITED(status));
}

/**
 * WEXITSTATUS_wrapper -  Returns the exit status of the child process
 * @status:the status
 * Return: numeric status
 */

int WEXITSTATUS_wrapper(int status)
{
	return (WEXITSTATUS(status));
}
