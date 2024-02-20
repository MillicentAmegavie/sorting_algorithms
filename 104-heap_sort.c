#include "sort.h"

/**
 * check_tree - swiftdown check.
 * @array: pointer to array.
 * @size: size of the pointer.
 * @size_init: original size of the array.
 * @i: index as a root of the tree.
 **/

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int m, b1, b2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	b1 = array[br1];
	b2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(b1 >= b2 && b1 > array[i]))
		|| ((br1 == size - 1) && b1 > array[i]))
	{
		m = array[i];
		array[i] = b1;
		array[br1] = m;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(b2 > b1 && b2 > array[i]))
	{
		m = array[i];
		array[i] = b2;
		array[br2] = m;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}

/**
 * heap_sort - sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: pointer to array.
 * @size: size of the pointer.
 **/

void heap_sort(int *array, size_t size)
{
	size_t m, size_init = size;
	int k;

	if (!array)
		return;
	for (m = 0; m < size / 2 ; m++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - m);
	}
	for (m = 0; m < size_init - 1; m++)
	{
		k = array[0];
		array[0] = array[size - 1 - m];
		array[size - 1 - m] = k;
		print_array(array, size_init);
		check_tree(array, size_init, size - m - 1, 0);
	}

}
