#include "monty.h"

/**
 * f_push - pushes an element onto the stack or queue
 * @stack: pointer to the head of the stack or queue
 * @line_number: current line number in the Monty program
 */
void f_push(stack_t **head, unsigned int counter)
{
	int i, n;
	stack_t *ptr;

    if (globalVar.arg == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(globalVar.file);
        free(globalVar.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    i = 0;
    if (globalVar.arg[i] == '-')
        i++;
    while (globalVar.arg[i] != '\0')
    {
        if (globalVar.arg[i] < '0' || globalVar.arg[i] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(globalVar.file);
            free(globalVar.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    n = atoi(globalVar.arg);
    if (globalVar.is_stack == 0)
	{
		ptr = malloc(sizeof(stack_t));
		ptr->n = n;
		ptr->next = *head;
		*head = ptr;
	}   
    else
	{
        ptr = malloc(sizeof(stack_t));
		ptr->n = n;
		ptr->prev = NULL;
		ptr->next = *head;
		*head = ptr;
	}

    fclose(globalVar.file);
    free(globalVar.content);
}