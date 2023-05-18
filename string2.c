#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 * Return: pointer to duplicate string
 */
char *_strdup(char *str)
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

char *_strchr(char *str, char character)
{
    while (*str != '\0')
    {
        if (*str == character)
        {
            return str;
        }
        str++;
    }
    if (character == '\0')
    {
        return str;
    }
    return NULL;
}

/**
 * _strcat - duplicate a string
 * @dest: string to duplicate
 * @src: string to duplicate
 * Return: pointer to duplicate string
 */

char *_strcat(char *destination, char *source)
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

char *_strcpy(char *destination, char *source) {
  int index = 0;

  while (source[index] != '\0') {
    destination[index] = source[index];
    index++;
  }

  destination[index] = '\0';

  return destination;
}
