#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 * Return: pointer to duplicate string
 */
char *_strdup(const char *str)
{
	if (str == NULL)
		return NULL;

	char *dup = malloc(sizeof(char) * (strlen(str) + 1));
	if (dup == NULL)
	{
		return NULL;
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		dup[i] = str[i];
	}
	return dup;
}

/**
 * _strchar - duplicate a string
 * @str: string to duplicate
 * @c: character to duplicate
 * Return: pointer to duplicate string
 */

char _strchar(char *str, char c)
{
	int i;
	if (str == NULL)
		return '\0';

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return str[i];
	}
	return '\0';
}

/**
 * _strcat - duplicate a string
 * @dest: string to duplicate
 * @src: string to duplicate
 * Return: pointer to duplicate string
 */

char *strcat(char *destination, const char *source)
{
	char *ptr;
	if (destination == NULL)
		return source;

	ptr = destination;
	while (*ptr != '\0')
		ptr++;

	while (*source != '\0') 
	{
		*ptr = *source;
		source++;
		ptr++;
	}
	*ptr = '\0';
	return destination;
}

/**
 * _strcpy - duplicate a string
 * @dest: string to duplicate
 * @src: string to duplicate
 * Return: pointer to duplicate string
 */

char *_strcpy(char *destination, const char *source)
{
	if (destination == NULL)
		return source;

	while (*source != '\0') 
	{
		*destination = *source;
		source++;
		destination++;
	}
	return destination;
}
