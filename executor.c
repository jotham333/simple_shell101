#include "shell.h"



/**
 *
 *
 *
 *
 *
 */

void execute_command(char **tokens)
{
        char *path, *path_copy, *token;
        pid_t pid;
        int status;
        char bin_path[MAX_INPUT_SIZE];

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
                        path = _getenv("PATH");
                        path_copy = strdup(path);
                        token = strtok(path_copy, ":");

                        while (token != NULL)
                        {
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
