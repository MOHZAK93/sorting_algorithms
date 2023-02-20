#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * quick_sort - sorts an array of integers in ascending
 * order using quick sort algorithm
 *
 * @array: array to bey
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - applies recursive divide and conquer
 * portion of the quick_sort algorithm
 *
 * @array: array
 * @lb: lower bound of array
 * @ub: upper bound of array
 * @size: size of the array
 */
void quicksort_recursion(int *array, int lb, int ub, size_t size)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = partition(array, lb, ub, size);
		quicksort_recursion(array, lb, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, ub, size);
	}
}

/**
 * swap - swap to elements of the array
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

/**
 * partition - partitions the array by a pivot
 *
 * @array: array
 * @lb: lower bound of array
 * @ub: upper bound of array
 * @size: size of the array
 *
 * Return: pivot element's index
 */

int partition(int *array, int lb, int ub, size_t size)
{
	int pivot_value = array[ub];
	int i = lb - 1, j;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != ub)
	{
		swap(&array[i], &array[ub]);
		print_array(array, size);
	}
	return (i);
}
