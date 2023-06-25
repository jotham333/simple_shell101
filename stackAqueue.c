#include "monty.h"

/**
 * switcher - switch the stack or queue
 * Return: no return
 */
void switcher(void)
{
    printf("select the mode you want to use:\n");
    printf("1 - stack and 2 - queue\n");
    int input = scanf("%d", &globalVar.is_stack);
    if (input == 1)
    {
        globalVar.is_stack = 1; // Set stack mode
    }
    else if (input == 0)
    {
        globalVar.is_stack = 0; // Set queue mode
    }
}

/**
 * addNode - adds a new node to a stack or queue based on the mode
 * @head: pointer to the head of the stack/queue
 * @n: value of the new node
 * Return: no return
 */
void addNode(stack_t **head, unsigned int n)
{
    switcher(); // Call switcher function to set the mode

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(globalVar.file);
        free(globalVar.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (globalVar.is_stack == 1) // Stack mode
    {
        if (*head != NULL)
        {
            new_node->next = *head;
            (*head)->prev = new_node;
        }
        *head = new_node;
    }
    else // Queue mode
    {
        if (*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            stack_t *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
}
