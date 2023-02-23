#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * counting_sort - sorts an array of integers in ascending
 * order using counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int *arr, *arrp, i, k = *array, n = size;

	for (i = 1; i < n; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	arr = malloc(sizeof(arr) * (k + 1));
	if (!arr)
		return;
	for (i = 0; i < n; i++)
	{
		arr[array[i]]++;
	}
	for (i = 1; i <= k; i++)
	{
		arr[i] = arr[i] + arr[i - 1];
	}
	print_array(arr, k + 1);
	arrp = malloc(sizeof(arrp) * n);
	if (!arrp)
		return;
	for (i = n - 1; i >= 0; i--)
	{
		arrp[--arr[array[i]]] = array[i];
	}
	for (i = 0; i < n; i++)
		array[i] = arrp[i];
}
