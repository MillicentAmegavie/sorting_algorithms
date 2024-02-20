#include "sort.h"

/**
*swap - the positions of two elements into an array.
*@array: array.
*@item1: array element.
*@item2: array element.
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int t;

	t = array[item1];
	array[item1] = array[item2];
	array[item2] = t;
}

/**
 *hoare_partition - hoare partition sorting scheme implementation.
 *@array: array.
 *@first: first array element.
 *@last: last array element.
 *@size: size array.
 *Return: position of the last element sorted.
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int c = first - 1, f = last + 1;
	int p = array[last];

	while (1)
	{

		do {
			c++;
		} while (array[c] < p);
		do {
			f--;
		} while (array[f] > p);
		if (c >= f)
			return (c);
		swap(array, c, f);
		print_array(array, size);
	}
}

/**
 *qs - qucksort algorithm implementation.
 *@array: array.
 *@first: first array element.
 *@last: last array element.
 *@size: array size.
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t p = 0;

	if (first < last)
	{
		p = hoare_partition(array, first, last, size);
		qs(array, first, p - 1, size);
		qs(array, p, last, size);
	}
}

/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm.
 *@array: array.
 *@size: array size.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
