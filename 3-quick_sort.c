#include "sort.h"

/**
 * swap - swaps two numbers.
 * @num_1: pointer to first number
 * @num_2: pointer to second number
 */
void swap(int *num_1, int *num_2)
{
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}

/**
 * partition - partitions an array into two
 * @array: array to be partitioned
 * @size: size of array
 * @l: lowest index of array
 * @h: highest index of array
 *
 * Return: pivot index
 */
size_t partition(int *array, size_t size, size_t l, size_t h)
{
	int p = array[h];

	size_t i, j;

	i = l - 1;

	for (j = l; j < h; j++)
	{
		if (array[j] <= p)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	i++;
	swap(&array[i], &array[h]);
	print_array(array, size);
	return i;
}

/**
 * lomuto - sorts array using lomuto partition
 * @array: array to be sorted
 * @size: size of array
 * @l: lowest index of array
 * @h: highest index of array
 */
void lomuto(int *array, size_t size, size_t l, size_t h)
{
	size_t p;

	p = partition(array, size, l, h);

	lomuto(array, size, l, p - 1);
	lomuto(array, size, p + 1, h);
}

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto(array, size, 0, size - 1);
}
