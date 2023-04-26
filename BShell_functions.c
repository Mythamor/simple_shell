#include "my_shell.h"

/**
 *  my_fgets - gets user input
 *  @str:a character array where the input read from stream will be stored.
 *  @n:the maximum number of characters that can be read into buffer
 *  @stream: pointer to FILE structure that reps the input stream to read from
 *  Return: pointer to the buffer if successful, NULL, if otherwise
 */

char  *my_fgets(char  *str, int n, FILE  *stream)
{
char *result = fgets(str, n, stream);

if (result && result[strlen(result) - 1] == '\n')
{
result[strlen(result) - 1] = '\0';
}
return (result);
}

/**
 * my_execvp -  executes a command
 * @file: string representing the path to the executable file to execute
 * @argv:array of strings rep the arguments to pass to the exe file
 * Return: integer representing the success or failure
 */

int my_execvp(char *file, char *const argv[])
{
return (execvp(file, argv));
}

/**
 * my_feof - end of file
 * @stream: pointer to the FILE structure repn the input stream to check eof
 * Return: int success(0) or failuer
 */

int my_feof(FILE *stream)
{
return (feof(stream));
}

/**
 * my_strlen - gets the length of a string
 * @s: the string
 * Return: length of string
 */

size_t my_strlen(const char *s)
{
const char *p = s;

while (*p != '\0')
{
p++;
}

return ((size_t)(p - s));
}

/**
 * freeArgs - frees memory
 * @args: argument vectors
 */

void freeArgs(char **args)
{
int i;

for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
args = NULL;
}

