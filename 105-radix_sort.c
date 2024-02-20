#include <stdlib.h>
#include "sort.h"

/**
 * csort2 - auxiliary function of radix sort.
 * @array: array of data to be sorted.
 * @buff: malloc buffer.
 * @size: size of data.
 * @lsd: Less significant digit,
 * Return: .
 */

void csort2(int *array, int **buff, int size, int lsd)
{
	int m, j, cs = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (m = 0; m < size; m++)
	{
		num = array[m];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[m];
		carr[num] += 1;
	}

	for (m = 0, j = 0; m < cs; m++)
	{
		while (carr[m] > 0)
		{
			array[j] = buff[m][carr2[m]];
			carr2[m] += 1, carr[m] -= 1;
			j++;
		}
	}

	print_array(array, size);
}

/**
 * csort - auxiliary function of radix sort.
 * @array: array of data to be sorted.
 * @size: size of data.
 * @lsd: less significant digit.
 * Return: .
 */

void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int m, j, num, cs = 10, **buff;

	for (m = 0; m < size; m++)
	{
		num = array[m];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (m = 0; m < cs; m++)
		if (carr[m] != 0)
			buff[m] = malloc(sizeof(int) * carr[m]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (m = 0; m < cs; m++)
		if (carr[m] > 0)
			free(buff[m]);
	free(buff);
}

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 * @array: array of data to be sorted.
 * @size: size of data.
 * Return: .
 */

void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
