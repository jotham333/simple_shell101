#include "shell.h"


/**
 * _strchr - searches for a particular char in a string
 *
 * @str: pointer to the string
 *
 * @c: the character to search for
 *
 * Return: pointer when the char is encountered otherwise NULL
 */

char *_strchr(char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}

	return (NULL);
}



