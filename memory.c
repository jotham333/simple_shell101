#include "shell.h"


/**
 * _memcpy - copy str from src to dest
 *
 * @dest: pointer to the destination to copy the str to
 *
 * @src: poiter to the source to copy the str from
 *
 * @num_bytes: number of bytes to copy
 *
 * Return: pointer to the dest
 */

void *_memcpy(void *dest, const void *src, size_t num_bytes)
{
	char *d;
	const char *s;
	size_t i = 0;

	d = dest;
	s = src;

	while (i < num_bytes)
	{
		d[i] = s[i];
	}

	return (d);
}





/**
 * _realloc - reallocate memory size for a buffer
 *
 * @ptr: pointer to buffer to resize
 *
 * @new_size: the new sizwe to be allocated
 *
 * Return: pointer to the newly allocated variable
 */


void *_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;
	size_t copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		copy_size = new_size < sizeof(ptr) ? new_size : sizeof(ptr);
		memcpy(new_ptr, ptr, copy_size);

		free(ptr);
	}

	return (new_ptr);
}



void tokenizeString(const char* input, const char* delimiters)
{
    char* copy = strdup(input);  // Make a copy of the input string
    char* token = strtok(copy, delimiters);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }

    free(copy);  // Free the copied string
}











