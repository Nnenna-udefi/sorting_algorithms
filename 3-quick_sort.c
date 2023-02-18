#include "sort.h"

/**
 * swap_ints - function that swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function that partition the array around the pivot
 * and return the index of the pivot
 * @low: lower point
 * @high: higher point
 * Return: index of the pivot
 */
int partition(int *array, int low, int high)
{
	int pivot, j, i;

	pivot = array[high]; /* pivot is the last element */
	i = low - 1; /* i is the index of the smaller element */

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
		}
	}
	swap_ints(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_wrapper - quick sort wrapper
 * @array: given array
 * @low: lower
 * @high: higher
 * @size: array's size
 * Return: void
 */
void quick_sort_wrapper(int *array, int low, int high, size_t size)
{
	int pi; /* pi is partitioning index */

	if (low < high)
	{
		pi = partition(array, low, high);
		print_array(array, size);
		quick_sort_wrapper(array, low, pi - 1, size);
		quick_sort_wrapper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_wrapper(array, 0, size - 1, size);
	print_array(array, size);
}
