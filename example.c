#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 *
 */


int main()
{
	char *input = NULL;
	char *tokens[MAX_INPUT_SIZE];
	pid_t pid;
	int status;
	size_t len = 0;

	while (1)
	{
		write(1, "cisfun$ ", 9);
		getline(&input, &len, stdin);
		input[strcspn(input, "\n")] = 0; // remove newline character

		// Tokenize the input
		char *token = strtok(input, " ");
		int i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		tokens[i] = NULL; // Set the last element to NULL

		if (strcmp(tokens[0], "env") == 0)
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
