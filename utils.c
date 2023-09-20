#include "shell.h"

/**
 * init_shell_info - this function initializes shell info
 *
 * Return: initial info
 */
info_t init_shell_info(void)
{
	info_t shell_info;

	shell_info.arg = NULL;
	shell_info.argv = NULL;
	shell_info.path = NULL;
	shell_info.argc = 0;
	shell_info.line_count = 0;
	shell_info.err_num = 0;
	shell_info.linecount_flag = 0;
	shell_info.fname = NULL;
	shell_info.environ = NULL;
	shell_info.env_changed = 0;
	shell_info.status = 0;
	shell_info.readfd = 0;

	return (shell_info);
}

/**
 * _print_error - This function prints error messages
 * @app: the name of the shell program
 * @msg: the message to print out
 */
void _print_error(char *app, char *msg)
{
	size_t app_len = _strlen(app);
	size_t msg_len = _strlen(msg);

	write(STDERR_FILENO, app, app_len);
	write(STDERR_FILENO, msg, msg_len);
}


/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
