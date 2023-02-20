#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - function that partition the array around the pivot
 * @array: array
 * @low: lower
 * @high: higher
 * @size: array's size
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1; /* i is the index of the smaller element */
	int j;
	int pivot = array[high], aux = 0;
	/* pivot is the last element */

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		aux = array[i + 1];
		array[i + 1] = array[high];
		array[high] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @low: lower
 * @high:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int low, int high, size_t size)
{
	int pivot; /* partitioning index */

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_s(array, low, pivot - 1, size);
		quick_s(array, pivot + 1, high, size);
	}
}
