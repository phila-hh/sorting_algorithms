#include "sort.h"

/**
 * knuth_max_gap - returns the maximum gap based on the Knuth sequence
 * @size: size of the array
 *
 * Return: the maximum gap
 */

size_t knuth_max_gap(size_t size)
{
	size_t gap;

	gap = 1;
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	if (gap >= size)
	{
		gap = (gap - 1) / 3;
	}

	return (gap);
}


/**
 * shell_sort - sorts an array of integers in ascending order using the
 *		Shell sort algorithm, using the Knuth sequence
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	gap = 0;
	gap = knuth_max_gap(size);
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
