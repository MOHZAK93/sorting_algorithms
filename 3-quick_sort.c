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
	quicksort_recursion(array, 0, size - 1);
}

/**
 * quicksort_recursion - applies recursive divide and conquer
 * portion of the quick_sort algorithm
 *
 * @array: array
 * @lb: low bound of array
 * @ub: upper bound of array
 */
void quicksort_recursion(int *array, int lb, int ub)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = partition(array, lb, ub);
		quicksort_recursion(array, lb, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, ub);
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
 *
 * Return: pivot element's index
 */

int partition(int *array, int lb, int ub)
{
	int pivot_value = array[ub];
	int i = lb, j;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			print_array(array, 10);
			i++;
		}
	}
	swap(&array[i], &array[ub]);

	return (i);
}
