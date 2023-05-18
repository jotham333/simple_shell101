#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_LENGTH 10

extern char **environ;  // External variable containing the environment

void print_environment()
{
	char **env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

int main()
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("cisfun$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "env") == 0)
		{
			print_environment();
			continue;			
		}

		char *arguments[MAX_LENGTH];
		char *token = strtok(command, " ");
		int argcount = 0;

		while (token != NULL && argcount < MAX_LENGTH - 1)
		{
			arguments[argcount] = token;
			argcount++;
			token = strtok(NULL, " ");
		}

		arguments[argcount] = NULL;

		char *path = getenv("PATH");
		char *pathtoken = strtok(path, ":");

		int commandfound = 0;
		char fullpath[MAX_LENGTH];

		while (pathtoken != NULL)
		{
			snprintf(fullpath, sizeof(fullpath), "%s/%s", pathtoken, arguments[0]);
			if (access(fullpath, X_OK) == 0)
			{
				commandfound = 1;
				break;
			}

			pathtoken = strtok(NULL, ":");
		}

		if (commandfound)
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execv(fullpath, arguments) == -1)
				{
					perror("Execution failed");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				int status;
				waitpid(pid, &status, 0);
			}
		}
		else
		{
			printf("command not found: %s\n", arguments[0]);
		}
	}

	return (0);
}
