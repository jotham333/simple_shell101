#include "shell.h"

/**
 * _getenv - print the environment
 *
 * @name: name of the environment variable
 *
 * Return: void
 */


char *_getenv(char *name)
{
        char **env = environ;
        size_t name_len = _strlen(name);
        while (*env != NULL)
        {
                if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
                {
                        return *env + name_len + 1;
                }
                env++;
        }
        return NULL;
}
