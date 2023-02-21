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
	size_t gap, j;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (j = gap; j < size; j++)
		{
			while (j)
			{
				if (array[j] < array[j - gap])
					swap(&array[j], &array[j - gap]);
				else
					break;
				j--;
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
