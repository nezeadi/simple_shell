#include "simple_shell.h"

/**
 * parse_cmd - make sense out of the user's command
 * @cmd: the full command the user typed into the shell
 *
 * Return: an array of words
 */

char **parse_cmd(char *cmd)
{
	int i = 0;
	char **args = malloc((MAX_NUM_ARGS + 1) * sizeof(char *));
	char *token = strtok(cmd, " ");

	while (token != NULL && i < MAX_NUM_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	return (args);
}

/**
 * execute_cmd - run the command the user asked for
 * @args: an array of words representing the command and its arguments
 *
 * Return: void
 */

void execute_cmd(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return;
	} else if (strcmp(args[0], "env") == 0)
	{
		int i;

		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	} else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror(args[0]);
				exit(EXIT_FAILURE);
			}
		} else if (pid < 0)
		{
			perror(args[0]);
		} else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
