#include "shell.h"

/**
 * env_builtin - print the environment
 *
 * Return: void
 */

void env_builtin(void)
{
	char **env = environ;
	int n;

	while (*env != NULL)
	{
		n = write(1, *env, _strlen(*env));
		write(1, "\n", 1);

		if (n < 0)
		{
			perror("write");
			exit(1);
		}
		env++;
	}
}

/**
 * exit_builtin - exit the shell
 *
 * @tokens: array of tokens
 *
 * Return: void
 */

void exit_builtin(char **tokens)
{
	if (tokens[1] != NULL)
	{
		int status = atoi(tokens[1]);
		if (status == 0 && _strcmp(tokens[1], "0") != 0)
		{
			// The argument is not a valid integer
			char *error = "Usage: exit [status]\n";
			write(STDERR_FILENO, error, _strlen(error));
		}
		else
		{
			exit(status);
		}
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
