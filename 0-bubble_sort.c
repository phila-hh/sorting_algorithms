#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *		Bubble sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp, swapped;

	n = size;
	swapped = 0;
	while (swapped == 0)
	{
		swapped = 1;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapped = 0;
				print_array(array, size);
			}
		}
	}
}
