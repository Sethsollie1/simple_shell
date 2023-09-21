#include "shell.h"

/**
 * read_prompt - this function reads prompts and displays inputs
 * @byte_read: the number of byte read by getline
 * Return: this returns the user input
 */

char *read_prompt(ssize_t *byte_read)
{
	char *prompt = "SollieJoy$ ";
	char *user_input = NULL;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, 11);
	}

	user_input = _getline();
	if (user_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*byte_read = str_len(user_input);

	if (*byte_read == -1 && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	else if (*byte_read == -1)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	if (*byte_read == 0 && isatty(STDIN_FILENO))
	{
		free(user_input);
		return (read_prompt(byte_read));
	}

	/*write(STDOUT_FILENO, user_input, byte_size);*/
	user_input[_strcspn(user_input, "\n")] = '\0';
	return (user_input);
}
