#include "sort.h"

/**
 * swap - swaps two values in an array
 * @array: pointer to the address of the array to swap values of
 * @idx_1: index of first value
 * @idx_2: index of second value
 *
 * Return: void
 */

void swap(int **array, ssize_t idx_1, ssize_t idx_2)
{
	int temp;

	temp = (*array)[idx_1];
	(*array)[idx_1] = (*array)[idx_2];
	(*array)[idx_2] = temp;
}


/**
 * partition - splits the array using the Lomuto's partition scheme
 * @array: pointer to the array to be splitted
 * @first: index of the first element of the array
 * @last: index of the last element of the array
 * @size: size of the array to be splitted
 *
 * Return: index of the new partition of the array
 */

size_t partition(int *array, int first, int last, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[last];
	i = first;
	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[last] < array[i])
	{
		swap(&array, i, last);
		print_array(array, size);
	}
	return (i);
}


/**
 * q_sort - partitions the array, and sorts each partition
 * @array: pointer to the array to be sorted
 * @first: the index of the first element of the array
 * @last: the index of the last element of the array
 * @size: size of the arrayto be sorted
 *
 * Return: void
 */

void q_sort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		q_sort(array, first, pivot - 1, size);
		q_sort(array, pivot + 1, last, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order using the
 *		Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: the size of the array to be sorted
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	ssize_t first, last;

	first = 0;
	last = size - 1;

	if (array == NULL || size < 2)
		return;

	q_sort(array, first, last, size);
}
