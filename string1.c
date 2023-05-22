#include "shell.h"



/**
 * _strlen - calculate the length of a string
 *
 * @str: pointer to the string
 *
 * Return: the number of string counted
 */

size_t _strlen(char *str)
{
	size_t i;

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}




/**
 * _strcmp - compares two string
 *
 * @str1: pointer to the first string
 *
 * @str2: pointer to the second string
 *
 * Return: 0 if both string are equal; -1 is str1 is less and 1 otherwise
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else if (*str1 > *str2)
		{
			return (1);
		}
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	else if (*str1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}



/**
 * _strncmp - compare two string with a specific byte
 *
 * @str1: pointer to the first string
 *
 * @str2: pointer to the second string
 *
 * @n: number of byte tp compare
 *
 * Return: 0 if strings are same; -1 if str1 is less and 1 if str2 is less
 */

int _strncmp(char *str1, char *str2, size_t n)
{
	while (*str1 != '\0' && *str2 != '\0' && n > 0)
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else if (*str1 > *str2)
		{
			return (1);
		}

		str1++;
		str2++;
		n--;
	}

	if (n == 0)
	{
		return (0);
	}
	else if (*str1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
