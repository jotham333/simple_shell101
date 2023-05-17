#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 4098

extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_len = strlen(name);
	while (*env != NULL)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return *env + name_len + 1;
		}
		env++;
	}
	return NULL;
}

// Function to tokenize a string
char **tokenize(char *str)
{
	char **tokens = NULL;
	char *token = strtok(str, " ");
	int i = 0;

	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (i + 1));
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}

	tokens = realloc(tokens, sizeof(char *) * (i + 1));
	tokens[i] = NULL;

	return tokens;
}

// Function to run a command
void run_command(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		return;
	}

	if (pid == 0)
	{
		if (tokens[0][0] == '/')
		{
			execve(tokens[0], tokens, NULL);
		}
		else
		{
			char *path = _getenv("PATH");
			char *path_copy = strdup(path);
			char *token = strtok(path_copy, ":");

			while (token != NULL)
			{
				char bin_path[MAX_INPUT_SIZE];
				strcpy(bin_path, token);
				strcat(bin_path, "/");
				strcat(bin_path, tokens[0]);
				execve(bin_path, tokens, NULL);
				token = strtok(NULL, ":");
			}
			free(path_copy);
			perror(tokens[0]);
			exit(EXIT_FAILURE);
		}
	}

	waitpid(pid, &status, 0);
}

// Function to implement the exit built-in
void exit_builtin(char **tokens)
{
	if (tokens[1] != NULL)
	{
		write(STDERR_FILENO, "Usage: exit\n", 11);
		return;
	}
	exit(EXIT_SUCCESS);
}

void env_builtin(char **tokens)
{
	if (tokens[1] != NULL)
	{
		write(STDERR_FILENO, "Usage: env\n", 11);
		return;
	}
	char **env = environ;
	while (*env != NULL)
	{
		size_t line_length = 0;
		while (*(*env + line_length) != '=')
		{
			++line_length;
		}
		++line_length; // include the '=' sign
		const char line[] = {'\n', '\0'};
		write(STDOUT_FILENO, *env, line_length);
		write(STDOUT_FILENO, *(env + 1), strlen(*(env + 1)));
		write(STDOUT_FILENO, line, 1);
		env += 2;
	}
}

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
			env_builtin(tokens);
			continue;
		}
		else if (strcmp(tokens[0], "exit") == 0)
		{
			exit_builtin(tokens);
		}
		else
		{
			run_command(tokens);
		}
		fflush(stdout);
	}
	free(input);
	return 0;
}
