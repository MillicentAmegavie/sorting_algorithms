#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: array of integer.
 * @size: array of size.
 * Return: .
 */

void bubble_sort(int *array, size_t size)
{
	size_t m;
	int t, s;

	if (!array || size == 0)
		return;

	do {
		s = 1;
		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				s = 0;
				t = array[m];
				array[m] = array[m + 1];
				array[m + 1] = t;
				print_array(array, size);
			}
		}

	} while (s == 0);
}
