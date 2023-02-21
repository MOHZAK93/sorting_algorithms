#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * shell_sort - sorts an array of integers in ascending
 * order using quick sort algorithm
 *
 * @array: array to bey
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	int gap, i, j;
	int len = size;

	for (gap = (len / 3) + 1; gap > 0; gap /= 3)
	{
		for (j = gap; j < len; j++)
		{
			i = j;
			while (array[i] < array[i - gap])
			{
				swap(&array[i], &array[i - gap]);
				i -= gap;
				if (i - gap < 0)
					break;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - swap two elements of an array
 *
 * @x: first element
 * @y: second element
 */

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
