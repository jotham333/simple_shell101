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
        *line_ptr = NULL;
        return (-1);
    }

    if (i == 0 && bytes_read == 0)
    {
        free(*line_ptr);
        *line_ptr = NULL;
        return 0;
    }

    (*line_ptr)[i] = '\0';

    return (ssize_t)i;
}


/**
 * _setenv - set an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @overwrite: whether to overwrite an existing variable
 *
 * Return: void
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	// If overwrite is zero and the variable already exists, do nothing.
	if (!overwrite && getenv(name) != NULL)
	{
		return 0;
	}

	// Allocate memory for the new environment variable string.
	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	char *env_str = malloc(name_len + value_len + 2);
	if (env_str == NULL)
	{
		errno = ENOMEM;
		return -1;
	}

	// Construct the new environment variable string.
	memcpy(env_str, name, name_len);
	env_str[name_len] = '=';
	memcpy(env_str + name_len + 1, value, value_len);
	env_str[name_len + value_len + 1] = '\0';

	// Set the new environment variable by modifying the environment array.
	extern char **environ;
	int env_size = 0;
	while (environ[env_size] != NULL)
	{
		env_size++;
	}

	char **new_environ = malloc(sizeof(char *) * (env_size + 2));
	if (new_environ == NULL)
	{
		errno = ENOMEM;
		free(env_str);
		return -1;
	}

	int i = 0;
	while (environ[i] != NULL)
	{
		new_environ[i] = environ[i];
		i++;
	}

	new_environ[i] = env_str;
	new_environ[i + 1] = NULL;

	environ = new_environ;

	return 0;
}

/**
 * unsetenv - unset an environment variable
 *
 * @name: name of the environment variable
 *
 * Return: 0
 */

int _unsetenv(const char *name)
{
	// Allocate memory for the environment variable string to remove.
	size_t name_len = strlen(name);
	char *env_str = malloc(name_len + 2);
	if (env_str == NULL)
	{
		errno = ENOMEM;
		return -1;
	}

	// Construct the environment variable string to remove.
	memcpy(env_str, name, name_len);
	env_str[name_len] = '=';
	env_str[name_len + 1] = '\0';

	// Remove the environment variable.
	int result = putenv(env_str);
	if (result != 0)
	{
		errno = EINVAL;
		free(env_str);
		return -1;
	}

	free(env_str);
	return 0;
}
