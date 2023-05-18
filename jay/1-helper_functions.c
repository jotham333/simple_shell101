#include "shell.h"



/**
 * _strlen - count the length of a string
 *
 * @str: pointer to the string to count
 *
 * Return: number of character counted
 */


int _strlen(char *str)
{
	int i, count = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return (count);
}


/**
 * _strcpy - copy string from src to dest
 *
 * @dest: the destination to copy the string to
 *
 * @src: the source to copy the string from
 *
 * Return: a pointer to the destination
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}



/**
 * _strcmp - compares two strings
 *
 * @str1: the first string
 *
 * @str2: the second string
 *
 * Return: 0 if both strings are same; 1 if the first string is bigger
 * and -1 otherwise
 */


int _strcmp(const char *str1, const char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		else if (str1[i] > str2[i])
		{
			return (1);
		}
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else if (str1[i] == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}


/**
 * _strcat - concatenate  two strings
 *
 * @dest: the string to be appended into
 *
 * @src: the string to appended
 *
 * Return: pointer to the destination
 */

char *_strcat(char *dest, const char *src)
{
	int i, j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}

	dest[i + j] = '\0';

	return (dest);
}


/**
 * _memmove - used to copy a memory block
 *
 * @dest: pointer to destination to be copied to
 *
 * @src: pointer to the source to copy from
 *
 * @n: size of block to copy
 *
 * Return: pointer to destination
 */

void *_memmove(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	size_t i;

	if (d < s)
	{
		for (i = 0; i < n; i++)
		{
			d[i] = s[i];
		}
	}
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			d[i] = s[i];
		}
	}

	return (dest);
}




































