#include "shell.h"


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



void _realloc(void *ptr, size_t old_size, size_t new_size)
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
		 copy_size = old_size < new_size ? old_size : new_size;
		 memcpy(new_ptr, ptr, copy_size);

		 free(ptr);
	}

	return (new_ptr);
}















