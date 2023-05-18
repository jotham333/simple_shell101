#include "shell.h"


/**
 *
 *
 *
 *
 *
 *
 */

char *_getenv(char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], name) == 0)
		{
			return environ[i] + _strlen(name) + 1;
		}
	}
	return (NULL);
}



char *find_command(char *command)
{
	char *path = _getenv("PATH");
	char **tokens = tokenize(command);
	int i;
	char *full_path;

	for (i = 0; tokens[i] != NULL; i++)
	{
		full_path = malloc(_strlen(path) + _strlen(tokens[i]) + 2);
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, tokens[i]);

		if (access(full_path, F_OK) == 0)
		{
			free(tokens);
			return (full_path);
		}

		free(full_path);
	}
	free(tokens);

	return (NULL); 
}























