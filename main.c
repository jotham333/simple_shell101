#include "shell.h"

int main(void)
{
	char *input = NULL;
	char *command;
	char *path;
	char *token;
	char *end;
	char *current_command;
	char *cwd;
	char *commands[MAX_INPUT_SIZE];
	char *tokens[MAX_INPUT_SIZE];
	size_t len = 0;
	ssize_t bytes_read;
	int i;
	int cmd;
	int num_commands = 0;

	while (interactive() && 1)
	{
		cwd = get_current_dir();
		write(STDOUT_FILENO, "cisfun:", _strlen("cisfun:"));
		write(STDOUT_FILENO, cwd, _strlen(cwd));
		write(STDOUT_FILENO, "$ ", 2);
		free(cwd);

		bytes_read = _getline(&input, &len, stdin);
		if (bytes_read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (bytes_read == 1)
		{
			continue;
		}

		input[_strcspn(input, "\n")] = '\0';

		command = _strtok(input, ";");
		while (command != NULL)
		{
			commands[num_commands] = command;
			num_commands++;
			command = _strtok(NULL, ";");
		}
      
		for (cmd = 0; cmd < num_commands; cmd++)
		{
	
			current_command = commands[cmd];
			while (_isspace(*current_command))
			{
				current_command++;
			}
			end = current_command + _strlen(current_command) - 1;
			while (end > current_command && _isspace(*end))
			{
				end--;
			}
			*(end + 1) = '\0';

			token = _strtok(current_command, " ");
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
			}
			else if (_strcmp(tokens[0], "exit") == 0)
			{
				exit_builtin(tokens);
				break;
			}
			else if (_strcmp(tokens[0], "cd") == 0)
			{
				path = tokens[1];
				cd_builtin(path);
			}
			else
			{
				execute_command(tokens);
			}
		}
 		free(input);
                input = NULL;
                len = 0;
                num_commands = 0;

                fflush(stdout);
	}

	return 0;
}
