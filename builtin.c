#include "shell.h"


/**
 * env_builtin - print the environment
 *
 * @tokens: array of tokens
 *
 * Return: void
 */

void env_builtin()
{
        char **env = environ;
        size_t length = 0;
        int n;

        while (*env != NULL)
        {
                n = write(1, *env, _strlen(*env));
                write(1, "\n", 1);

                if (n < 0)
                {
                        perror("write");
                        exit(1);
                }
                env++;
        }
}



/**
 * exit_builtin - exit the shell
 *
 * @tokens: array of tokens
 *
 * Return: void
 */

void exit_builtin(char **tokens)
{
        if (tokens[1] != NULL)
        {
                write(STDERR_FILENO, "Usage: exit\n", 11);
                return;
        }
        exit(EXIT_SUCCESS);

}























