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
	unsigned long int i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
