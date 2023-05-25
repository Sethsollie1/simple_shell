#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "$ "

void execute_command(char *command, char **environ);
void display_prompt(void);
void read_execute_command(void);

/* Environment variable */
extern char **environ;

#endif
