#include "shell.h"

/**
 *
 *
 *
 */

void print_prompt()
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}



/**
 *
 *
 *
 *
 */

char *get_line()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			return (NULL);
		}
		else
		{
			return (NULL);
		}
	}

	if (line[nread - 1] == '\n')
	{
		line[nread - 1] = '\0';
	}

	return (line);

}


/**
 *
 *
 *
 *
 */

void execute_command(char *command)
{
	char **args = tokenize(command);
	pid_t pid;
	int status;
     	int ret;

	if (find_command(command) == NULL)
	{
		write(2, "Command not found: ", 19);
		write(2, command, _strlen(command));
		write(2, "\n", 1);
		return;
	}

	if (args == NULL)
		return;

	pid = fork();

	if (pid == - 1)
	{
		perror("Fork failed");
		return;
	}
	else if (pid == 0)
	{
		ret = execve(args[0], args, NULL);
		if (ret < 0)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
