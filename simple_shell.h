#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100
#define MAX_NUM_ARGS 10

extern char **environ;

char **parse_cmd(char *cmd);
void execute_cmd(char **args);

#endif /* SIMPLE_SHELL_H */
