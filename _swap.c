#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: the stack head
 * @counter: current line number in the Monty program
 * Return: nothing
*/

void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
