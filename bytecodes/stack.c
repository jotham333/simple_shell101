#include "monty.h"

/**
 * f_stack - set the format of the data to a stack (LIFO).
 * @head: pointer to the head of the stack
 * @counter: current line number in the Monty program
 * Return: no return
*/

void f_stack(stack_t **head, unsigned int counter)
{
    stack_t *ptr;
    int data;
    
    ptr = malloc(sizeof(stack_t));
    if (ptr == NULL)
        return;

    ptr->n = data;
    ptr->next = *head;
    ptr->prev = NULL;
    
    if (*head != NULL)
        (*head)->prev = ptr;

    *head = ptr;
}
