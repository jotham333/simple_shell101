#include "monty.h"

#include "monty.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * f_push - pushes an element onto the stack or queue
 * @stack: pointer to the head of the stack or queue
 * @line_number: current line number in the Monty program
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	char *endptr;
	long int val;
	stack_t *new;

	if (globalVar.arg[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	endptr;
	val = strtol(globalVar.arg[1], &endptr, 10);

	/* Check for errors in input */
	if (*endptr != '\0' || endptr == globalVar.arg[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = (int)val;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;

	printf("L%d: PUSH %d\n", line_number, new->n);
}
