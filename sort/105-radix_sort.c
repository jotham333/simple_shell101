#include "sort.h"
#include <math.h>
#include <string.h>

/**
 *radix_sort - sort an array
 *
 * @array: pointer to the array
 *
 * @size: size of the array
 *
 * Return: Nothing
 */

void radix_sort(int *array, size_t size)
{
	size_t max_digit = 0;
	int *tmp = malloc(size * sizeof(int));
	int counts[10] = {0};
	int pos[10] = {0};
	size_t digit, num, digit_count;
	int powers_of_10[20];
	size_t i;

	for (i = 0; i < size; i++) {
		num = array[i];
		digit_count = 0;
		while (num > 0) {
			digit_count++;
			num /= 10;
		}
		if (digit_count > max_digit) {
			max_digit = digit_count;
		}
	}
	
	powers_of_10[0] = 1;
	for (i = 1; i < max_digit; i++) {
		powers_of_10[i] = powers_of_10[i - 1] * 10;
	}

	for (digit = 0; digit < max_digit; digit++) {
		memset(counts, 0, 10 * sizeof(int));
		for (i = 0; i < size; i++) {
			num = (array[i] / powers_of_10[digit]) % 10;
			counts[num]++;
		}
		pos[0] = 0;
		for (i = 1; i < 10; i++) {
			pos[i] = pos[i - 1] + counts[i - 1];
		}
		for (i = 0; i < size; i++) {
			num = (array[i] / powers_of_10[digit]) % 10;
			tmp[pos[num]++] = array[i];
		}
		memcpy(array, tmp, size * sizeof(int));

		print_array(array, size);
	}

	free(tmp);
}
