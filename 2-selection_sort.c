#include "sort.h"

/**
 * swap - swaps two numbers
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
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
			swap(&array[i], &array[min]);
		print_array(array, size);
	}
}
