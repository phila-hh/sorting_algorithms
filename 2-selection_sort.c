#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *		Selection sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, idx, min;
	int temp, swapped;

	swapped = 0;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		min = i;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[idx] < array[min])
			{
				min = idx;
				swapped = 1;
			}
		}
		if (swapped)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
