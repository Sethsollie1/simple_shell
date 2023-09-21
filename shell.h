#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;
char *_getline(void);

/* setenv.c */
int setenv_shell(char **args);
int unsetenv_shell(char **args);
int handle_env_cmds(char **args);

/**
 * struct data_shell - Structure representing shell data
 *
 * @_environ: Pointer to an array of strings
 * @status: Integer representing the status of the shell
 */
typedef struct data_shell
{
	char **_environ;
	int status;
} data_shell;

/* environ.c */
int _env(data_shell *shell_data);
void handle_env(char *user_input, data_shell *shell_data);

char *_strtok(char *str, const char *delim);
char *_strdup(char *dup, char *str);


/* main.c */
char *read_prompt(ssize_t *byte_read);

/* shell.c */
int main(int argc, char **argv);

/* exec.c */
int execute_cmd(char **_get_argv);

/* exit.c */
void _exit_shell(char **_get_argv, int exec_status);

/* handlepath.c */
char *_get_path(char *initial_cmd);

/* tokenize.c */
char **tokenize(char *get_user_input, char **argv, ssize_t byte_read);

char *accept_user_input(void);

void (*get_command(char *cmd))(void);

/* strings2.c */
int str_len(char *string);
void str_copy(char *to, char *from);
void str_cat(char *text_add, char *text);

/* function related */
char **handle_path(void);
int check_ifCommand_exist(char *string);
char **split_string(char *string);

/* err_func.c */
void print_error(char **av, char *err);
int _errputs(char *str);

char *_strchr(char *s, char c);
int _strcspn(char *s, char *charset);
int _strcmp(char *s, char *c);

int _atoi(char *s);

void free_array(char **argv);

int cd_command(char **args);
char *_getenv(const char *name);

#endif
