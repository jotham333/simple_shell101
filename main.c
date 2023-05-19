#include "shell.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */


int main(void)
{
	char *input = NULL;
	char *tokens[MAX_INPUT_SIZE];
	char *tok = NULL;
	size_t len = 0;
	char *token;
	int i;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		_getline(&input, &len, stdin);
		input[strcspn(input, "\n")] = 0;

		token = _strtok(input, " ");
		tok = _strtok(NULL, " ");
		i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = _strtok(NULL, " ");
		}
		tokens[i] = NULL;

		if (_strcmp(tokens[0], "env") == 0)
		{
			env_builtin();
			continue;
		}
		else if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_builtin(tokens);
		}
		else if (_strcmp(tokens[0], "cd") == 0)
		{
			cd_builtin(tok);
		}
		else
		{
			execute_command(tokens);
		}
		fflush(stdout);
	}
	free(input);
	return (0);
}
