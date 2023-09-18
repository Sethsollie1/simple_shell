#include "shell.h"

int main(void)
{
	char *buffer, *line;
	list_t *env_head;
	int ret_val;

	/* create a buffer to store input */
	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
		return (1);
	line = NULL;
	env_head = array_to_list(environ);
	/* call cmd_line_loop */
	ret_val = cmd_line_loop(buffer, line, &env_head);

	free_list(env_head);
	free(buffer);
	return (ret_val);
}
