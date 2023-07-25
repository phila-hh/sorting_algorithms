#include "sort.h"

/**
 * counting_sort - sort an array of integers in ascending order using the
 *		Counting sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int i, j, k, *sorted_arr;
	size_t p;

	if (array == NULL || size < 2)
		return;

	k = 0;
	for (i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	sorted_arr = malloc(sizeof(int) * ++k);
	if (sorted_arr == NULL)
		return;

	for (i = 0; i < k; i++)
		sorted_arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		sorted_arr[array[i]] += 1;

	for (i = j = 0; i < k && j < (int)size; i++)
	{
		p = sorted_arr[i];
		while (p > 0)
		{
			array[j] = i;
			p--;
			j++;
		}
	}
	p = 0;
	for (i = 0; i < k; i++)
	{
		p += sorted_arr[i];
		sorted_arr[i] = p;
	}
	print_array(sorted_arr, k);
	free(sorted_arr);
}
