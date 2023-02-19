#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp = 0;
	unsigned int i = 0, j = 0, interval = 0;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;
	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = 1; j >= interval && array[j - interval] > temp; j -= interval)
			{
				if (array[j] != array[j - interval])
					array[j] = array[j - interval];
			}
			if (array[j] != temp)
				array[j] = temp;
		}
		print_array(array, size);
	}
}

