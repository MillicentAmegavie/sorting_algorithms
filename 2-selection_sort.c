#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: size of the array.
 * Return: .
 */

void selection_sort(int *array, size_t size)
{
	size_t m, s, min_idx;
	int t;

	for (s = 0; s < size - 1; s++)
	{
		min_idx = s;
		for (m = s + 1; m < size; m++)
		{
			if (array[m] < array[min_idx])
				min_idx = m;
		}

		if (min_idx != s)
		{
			t = array[s];
			array[s] = array[min_idx];
			array[min_idx] = t;
			print_array(array, size);
		}
	}
}
