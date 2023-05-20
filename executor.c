#include "shell.h"



/**
 * execute_command - execute a command
 *
 * @tokens: array of tokens
 *
 * Return: void
 */

int execute_command(char **tokens)
{
    char *path, *path_copy, *token;
    pid_t pid;
    int status;
    char bin_path[MAX_INPUT_SIZE];

    pid = fork();

    if (pid == -1)
    {
        perror("fork failed");
		exit(EXIT_FAILURE);
        return -1;
    }

    if (pid == 0)
    {
        if (tokens[0][0] == '/')
        {
            execve(tokens[0], tokens, NULL);
        }
        else
        {
            path = _getenv("PATH");
            path_copy = _strdup(path);
            token = strtok(path_copy, ":");

            while (token != NULL)
            {
                _strcpy(bin_path, token);
                _strcat(bin_path, "/");
                _strcat(bin_path, tokens[0]);
                execve(bin_path, tokens, NULL);
                token = strtok(NULL, ":");
            }
            free(path_copy);
            perror(tokens[0]);
            exit(EXIT_FAILURE);
        }
    }

    waitpid(pid, &status, 0);
	return 0;
}
