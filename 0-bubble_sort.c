#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n = 0, temp;

	while (n < size)
	{
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				print_array(array, size);
			}
		}
		n++;
	}
}
