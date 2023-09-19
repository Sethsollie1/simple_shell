#include "main.h"

int main(int argc __attribute__((unused)), char **argv)
{
	int count = 0, retour, status;
	pid_t id;

	signal(SIGINT, handler);
	while (1)
	{
		retour = shell_loop(argv, count);
		if (retour == 2)
		{
			count++;
			id = fork();
			if (id == -1)
			{
				perror("Error fork: ");
				return (EXIT_FAILURE);
			}
			if (id != 0)
			{
				wait(&status);
				return (127);
			}
			else
				continue;
		}
		if (retour != 0)
			break;
		count++;
	}
	return (0);
}
