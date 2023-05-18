#include "shell.h"


/**
 * _strtok - spilts a string into tokens
 *
 * @str: pointer to the string to be splitted
 *
 * @delim: char to search for in the string
 *
 * Return: a pointer to the splitted string otherwise NULL
 */


char *_strtok(char *str, char *delim)
{
	static char *last = NULL;
	char *token;

	if (str == NULL)
		str = last;

	if (*str == '\0')
		return (NULL);
	
	token = str;
	while (*str != '\0')
	{

		if (_strchr(delim, *str) != NULL)
		{
			*str = '\0';
			last = str + 1;
			return (token);
		}

		str++;
	}

	last = str;
	return token;
}



/**
 *
 *
 *
 *
 *
 */


char **tokenize(char *str)
{
	char **tokens = NULL;
	char *token = strtok(str, " ");
	int i = 0;

	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (i + 1));
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}

	tokens = realloc(tokens, sizeof(char *) * (i + 1));
	tokens[i] = NULL;

	return (tokens);
}




























