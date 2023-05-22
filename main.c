#include "simple_shell.h"

/**
 * main - this is where all the magic happens
 * @argc: count of arguments that are passed to the program
 * @argv: array of pointers to the strings which are those arguments
 *
 * Return: always 0 (if everything's good)
 */

int main(void)
{
	char cmd[MAX_CMD_LENGTH];
	char **args;

	do {
		printf("> ");
		fgets(cmd, MAX_CMD_LENGTH, stdin);
		cmd[strcspn(cmd, "\n")] = 0;
		args = parse_cmd(cmd);
		execute_cmd(args);
		free(args);
	} while (1);

	return (0);
}
