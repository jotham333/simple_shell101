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

void env_builtin()
{
        char **env = environ;
        size_t length = 0;
        int n;

        while (*env != NULL)
        {
                n = write(1, *env, strlen(*env));
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
 *
 *
 *
 *
 *
 *
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























