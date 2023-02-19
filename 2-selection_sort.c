#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * selection_sort - sorts an array of integers in ascending
 * order using selection algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, cm;
	int set;

	for (i = 0; i < size; i++)
	{
		cm = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[cm])
			{
				cm = j;
			}
		}
		if (cm == i)
			continue;
		set = array[i];
		array[i] = array[cm];
		array[cm] = set;
		print_array(array, size);
	}
}
