#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *sorted_list, *temp_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted_list = *list;
	current_node = sorted_list->next;

	while (current_node != NULL)
	{
		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			temp_node = current_node->prev;
			temp_node->next = current_node->next;

			if (current_node->next != NULL)
				current_node->next->prev = temp_node;

			current_node->next = temp_node;
			current_node->prev = temp_node->prev;
			temp_node->prev = current_node;

			if (current_node->prev != NULL)
				current_node->prev->next = current_node;
			else
				*list = current_node;

			print_list(*list);
		}

		current_node = current_node->next;
	}
}
