#include "monty.h"

/**
 * main - monty code interpreter
 *
 * @arc: argument counter
 *
 * @arv: arguement vector
 *
 * Return: 0 on success
 */

int main(int arc, char **arv)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	unsigned int count = 0;
	stack_t *stack = NULL;

	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		content = NULL;
		readline = getline(&content, &size, file);
		globalVar.content = content;
		counte++;
		if (readline > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);

	return(0);
}
