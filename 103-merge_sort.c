#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for (; i < size; i++)
		base[i] = array[i];
	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mi - lo);
	printf("[right]: ");
	print_array(src + mi, hi - mi);
	i = lo;
	j = mi;
	k = lo;
		for (; k < hi; k++)
		{
			if (i < mi && (j >= hi || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}
