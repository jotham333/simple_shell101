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
			return (*env + name_len + 1);
		}
		env++;
	}
	return (NULL);
}

/**
 * _getline - read a line of input
 *
 * @line_ptr: pointer to the line
 * @line_size: size of the line
 * @stream: stream to read from
 *
 * Return: the number of characters read
 */

ssize_t _getline(char **line_ptr, size_t *line_size, FILE *stream)
{
	ssize_t bytes_read;
	size_t i;
	char *new_buf;

	for (i = 0;; i++)
	{
		if (i + 1 >= *line_size)
		{
			*line_size = (*line_size ? *line_size * 2 : 512);
			new_buf = realloc(*line_ptr, *line_size);
			if (!new_buf)
			{
				free(*line_ptr);
				return (-1);
			}
			*line_ptr = new_buf;
		}
		bytes_read = read(fileno(stream), &((*line_ptr)[i]), 1);
		if (bytes_read <= 0)
		{
			break;
		}
		if ((*line_ptr)[i] == '\n')
		{
			i++;
			break;
		}
	}

	if (bytes_read < 0 || (bytes_read == 0 && i == 0))
	{
		free(*line_ptr);
		return (-1);
	}

	(*line_ptr)[i] = '\0';

	return (i);
}

/**
 * _setenv - Set the value of an environment variable.
 *
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: A flag indicating whether to overwrite an existing variable.
 *
 * Return: 0 on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **envp = environ;

	if (name == NULL || value == NULL || (overwrite != 0 && overwrite != 1))
		return (-1);
	while (*envp != NULL)
	{
		if (strcmp(*envp, name) == 0)
		{
			if (overwrite == 0)
				return (0);
			if (*envp != NULL)
				free(*envp);
			*envp = strdup(value);

			if (*envp == NULL)
				return (-1);
			break;
		}

		envp++;
	}

	if (*envp == NULL)
	{
		*envp = strdup(name);
		if (*envp == NULL)
			return (-1);
		*(envp + 1) = strdup(value);
		if (*(envp + 1) == NULL)
		{
			free(*envp);
			*envp = NULL;
			return (-1);
		}
	}

	return (0);
}

int _unsetenv(const char *name)
{
    char **envp = environ;

    if (name == NULL)
        return (-1);

    while (*envp != NULL)
    {
        if (strncmp(*envp, name, strlen(name)) == 0 && (*envp)[strlen(name)] == '=')
        {
            // Shift all the entries after this one back by one
            char **dst = envp;
            char **src = envp + 1;
            while (*src != NULL)
            {
                *dst = *src;
                dst++;
                src++;
            }
            *dst = NULL;
            return (0);
        }
        envp++;
    }

    return (0);
}
