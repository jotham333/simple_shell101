#include "shell.h"



/**
 * tokenize - tokenize a string
 *
 * @str: string to tokenize
 *
 * Return: array of tokens
 */

char **tokenize(char *str)
{
        char **tokens = NULL;
        char *token = _strtok(str, " ");
        int i = 0;

        while (token != NULL)
        {
                tokens = realloc(tokens, sizeof(char *) * (i + 1));
                tokens[i] = _strdup(token);
                i++;
                token = _strtok(NULL, " ");
        }

        tokens = realloc(tokens, sizeof(char *) * (i + 1));
        tokens[i] = NULL;

        return tokens;
}




/**
 * _strtok - tokenizes string
 *
 * @str: pointer to the string to be tokenize
 *
 * @delim: pointer to the character to look out for
 *
 * Return: pointer to the tokenize string
 */


char *_strtok(char *str, char *delim)
{
	static char *last;
	char *token;

	if (str == NULL)
		str = last;

	while (*str != '\0' && strchr(delim, *str) != NULL)
	{
		str++;
	}

	if (*str == '\0')
		return (NULL);

	token = str;
	str = strchr(str, *delim);

	if (str != NULL)
	{
		*str++ = '\0';
	}

	last = str;

	return (token);
}

























