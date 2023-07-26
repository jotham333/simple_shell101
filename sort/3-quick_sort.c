#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - sort the array
 *
 * @array: pointer to the array
 *
 * @size: the size of the array
 *
 * Return: the sorted array
 */


void quick_sort(int *array, size_t size)
{
	int pivot = array[size - 1];
	int i = 0;
	size_t j = 0;
	int temp;

	if (size <= 1) {
		return;
	}

	while (j < size - 1) {
		if (array[j] < pivot) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			i++;
		}

		j++;
	}

	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;

	print_array(array, size);

	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
}
