#include "shell.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */


int main()
{
	char *input = NULL;
	char *tokens[MAX_INPUT_SIZE];
	pid_t pid;
	int status, i;
	size_t len = 0;
	char *token;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		_getline(&input, &len, stdin);
		input[strcspn(input, "\n")] = 0; // remove newline character

		// Tokenize the input
		token = _strtok(input, " ");
		i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = _strtok(NULL, " ");
		}
		tokens[i] = NULL; // Set the last element to NULL

		if (_strcmp(tokens[0], "env") == 0)
		{
			env_builtin();
			continue;
		}
		else if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_builtin(tokens);
		}
		else
		{
			execute_command(tokens);
		}
		fflush(stdout);
	}
	free(input);
	return 0;
}
