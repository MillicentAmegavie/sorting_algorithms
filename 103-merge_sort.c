#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one buffer to another.
 * @src: source buffer,
 * @dst: destination buffer.
 * @size: size of buffers.
 * Return: .
 */

void copy(int *src, int *dst, int size)
{
	int m;

	for (m = 0; m < size; m++)
		dst[m] = src[m];
}

/**
 * merge - merges two sets of data in ascending order.
 * but they must already be sorted before hand.
 * @array: first set of data.
 * @buff: second set of data.
 * @minL: lower range of first set of data.
 * @maxL: upper range of first set of data.
 * @minR: lower range of second set of data.
 * @maxR: upper range of second set of data.
 * Return: .
 */

void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int m = minL, n = minR, k = minL;

	while (m <= maxL || n <= maxR)

		if (m <= maxL && n <= maxR)
			if (buff[m] <= buff[n])
				array[k] = buff[m], k++, m++;
			else
				array[k] = buff[n], k++, n++;

		else if (m > maxL && n <= maxR)
			array[k] = buff[n], k++, n++;
		else
			array[k] = buff[m], k++, m++;
}

/**
 * printcheck - prints an array in a given range.
 * @array: array of data to be print.
 * @r1: start range
 * @r2: end range.
 * Return: .
 */

void printcheck(int *array, int r1, int r2)
{
	int m;

	for (m = r1; m <= r2; m++)
	{
		if (m > r1)
			printf(", ");
		printf("%d", array[m]);
	}
	printf("\n");
}

/**
 * split - recursive function to split data into merge tree.
 * @array: array of data to be split.
 * @buff: auxiliary array of data for merging.
 * @min: min range of data in array,
 * @max: max range of data in array.
 * @size: size of total data.
 * Return: .
 */

void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array of data to be sorted.
 * @size: size of data.
 * Return: .
 */

void merge_sort(int *array, size_t size)
{
	int *b;

	if (size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	copy(array, b, size);

	split(array, b, 0, size - 1, size);

	free(b);
}
