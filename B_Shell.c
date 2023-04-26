#include "my_shell.h"

/**
 *displayPrompt - Displays a prompt and waits for user input
 *
 */

void displayPrompt(void)
{
	printf("#B_Shell > ");
}

/**
 * parseCmd - Parse the command line
 * @cmd: The command
 * Return: Tokenized arguments
 */

char **parseCmd(char *cmd)
{
	/* Maximum of two arguments allowed */
	int max_args = 10;
	char **args = malloc((max_args + 1) * sizeof(char *));
	int i = 0;

	/* tokenize the string by space or newline */
	char *arg = strtok(cmd, " \n");

	while (arg != NULL && i < max_args)
{
	args[i] = arg;
	arg = strtok(NULL, " \n");
	i++;
}

	args[i] = NULL;

	return (args);
}

/**
 * exeCmd - Execute the command
 *@args: The argument vectors
 */
void exeCmd(char **args)
{
pid_t pid = fork();

if (_strcmp(args[0], "exit") == 0) /* if user wants to exit */
{
exit(0);
}
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid == 0)
{
if (_strcmp(args[0], "env") == 0) /* if user wants to see the environ var*/
{
char **env_ptr = __environ;
while (*env_ptr)
{
printf("%s\n", *env_ptr);
env_ptr++;
}
}
else if (my_execvp(args[0], args) == -1)
{
perror("my_execvp");
exit(1);
}
}
else
{
int status;
waitpid(pid, &status, 0);

if (WIFEXITED_wrapper(status) && WEXITSTATUS_wrapper(status) != 0)
{
printf("Error: \"%s\"\n: not found:", args[0]);
}
}
}


/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH];
	char **args;

	while (1)
{
	displayPrompt();
	if (my_fgets(cmd, MAX_COMMAND_LENGTH, stdin) == NULL)
{
	/* EOF condition (Ctrl+D) */
	if (my_feof(stdin))
{
		exit(0);
}
	else
{
		perror("my_fgets");
		exit(1);
}
}

	/* execute the command */
	args = parseCmd(cmd);
	exeCmd(args);

	/* free allocated memory */
	free(args);
}
	return (0);
}
