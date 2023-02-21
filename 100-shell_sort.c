#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending
 * order using quick sort algorithm
 *
 * @array: array to bey
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	int i, j, gap, tmp, n = 1, len = size;

	while (n < len)
		n = n * 3 + 1;
	for (gap = (n - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (j = gap; j < len; j++)
		{
			i = j;
			while (array[i] < array[i - gap])
			{
				tmp = array[i];
				array[i] = array[i - gap];
				array[i - gap] = tmp;
				i -= gap;
				if (i - gap < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
