#include "sort.h"
#include <stdio.h>

/**
 * _swap - swaped 2 values.
 * @array: array for swap him values.
 * @i: the first index.
 * @j: the second index.
 * Return: .
 */

void _swap(int *array, int i, int j)
{
	int t;

	if (array[i] != array[j])
	{
		t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}

/**
 * shell_sort - sort the list and print the changes.
 * @array: array to sort.
 * @size: size of array.
 * Return: .
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 0, m, j;

	if (size < 2)
		return;

	while (n <= size / 3)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (m = n; m < size; m++)
			for (j = m; j >= n && array[j] < array[j - n]; j -= n)
				_swap(array, j, j - n);
		n /= 3;
		print_array(array, size);
	}
}
