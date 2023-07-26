#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * selection_sort - sorts array
 *
 * @array: pointer to the array
 *
 * @size: size of the array
 *
 * Return: Nothing
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		print_array(array, size);
	}
}

