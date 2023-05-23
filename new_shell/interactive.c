#include "shell.h"

void _isactive()
{
    char *input;
    char **args;
    int status = -1;

    while (status == -1)
    {
        write (STDOUT_FILENO, "cisfun$", strlen("cisfun$") + 1);
        input = get_input();
        args = tokenize(input);
        status = execute_command(args);

        free(input);
        free(args);

        if (status >= 0)
        {
            exit_builtin(status);
        }
        
    }
    return (0);
}