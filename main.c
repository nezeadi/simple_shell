#include "simple_shell.h"

/**
 * main - this is where all the magic happens
 *
 * Return: always 0 (if everything's good)
 */

int main(void)
{
	char cmd[MAX_CMD_LENGTH];
	char **args;

	while (1)
	{
		printf("> ");
		fgets(cmd, MAX_CMD_LENGTH, stdin);
		cmd[strcspn(cmd, "\n")] = 0;

		if (strcmp(cmd, "exit") == 0)
			return (0);
		args = parse_cmd(cmd);
		execute_cmd(args);
		free(args);
	}

	return (0);
}
