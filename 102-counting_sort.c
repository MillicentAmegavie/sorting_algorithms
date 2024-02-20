#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 * @array: pointer to array.
 * @size: size of the array.
 **/

void counting_sort(int *array, size_t size)
{
	int n, j, *ca, *a;
	size_t m;

	if (!array || size < 2)
		return;
	n = array[0];
	for (m = 0; m < size; m++)
	{
		if (array[m] > n)
			n = array[m];
	}
	ca = calloc((n + 1), sizeof(int));
	for (m = 0; m < size; m++)
	{
		ca[array[m]]++;
	}
	for (j = 1; j < n; j++)
	{
		ca[j + 1] += ca[j];
	}
	print_array(ca, n + 1);
	a = malloc(sizeof(int) * size);
	for (m = 0; m < size; m++)
	{
		ca[array[m]]--;
		a[ca[array[m]]] = array[m];
	}
	for (m = 0; m < size; m++)
	{
		array[m] = a[m];
	}
	free(a);
	free(ca);
}

