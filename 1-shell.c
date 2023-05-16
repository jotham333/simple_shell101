#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *find_command(char *command);
 char **tokenize(char *str);



int main()
{
	char command[1024];
	char *paths = getenv("PATH");
	char **tokens;
	char *path;
	pid_t pid;
	int status;

	while (1)
	{
		printf("cisfun$ ");
		fgets(command, sizeof(command), stdin);

		command[strlen(command) - 1] = '\0';

		tokens = tokenize(command);
		path = find_command(tokens[0]);

		if (path == NULL)
		{	
			printf("commands not found: %s\n", command);
			continue;
		}

		pid = fork();

		if (pid == - 1)
		{
			perror("fork failed");
			return (1);
		}

		else if (pid == 0)
		{
			execve(path, tokens, NULL);
			perror(command);
			exit(EXIT_FAILURE);
		}

		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}




char *find_command(char *command)
{
	char *paths = getenv("PATH");
	char *token;
	char *path;

	while ((token = strsep(&paths, ":")) != NULL)
	{
		path = malloc(strlen(token) + strlen(command) + 2);

		if (path == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}

		sprintf(path, "%s/%s", token, command);

		if (access(path, F_OK) == 0)
			return (path);
	}
	free(path);
	return (NULL);
}


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

	return (tokens);
}

























