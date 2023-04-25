#include "sort.h"
/**
 * swap_sort - swaps two elements
 * @i: element to swap
 * @j: element to swap
 */
void swap_sort(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bitonicSort - sorts a bitonic sequence inside an array
 * @arr: array of integers
 * @size: size of an array
 * @start: starting index
 * @order: bitonic sequence
 * @dir: direction to sort
 */
void bitonicSort(int *arr, size_t size, size_t start, size_t order, char dir)
{
	size_t j;
	size_t cnt = order / 2;

	if (order > 1)
	{
		for (j = start; j < start + cnt; j++)
		{
			if ((dir == UP && arr[j] > arr[j + cnt]) ||
				(dir == DOWN && arr[j] < arr[j + cnt]))
				swap_sort(arr + j, arr + j + cnt);
		}
		bitonicSort(arr, size, start, cnt, dir);
		bitonicSort(arr, size, start + cnt, cnt, dir);
	}
}

/**
 * bitonicMerge - merges two subarrays into bitonic sequence
 * @arr: array of integers
 * @size: size of an array
 * @start: starting index
 * @order: bitonic sequence
 * @dir: direction to sort bitonic sequence
 */
void bitonicMerge(int *arr, size_t size, size_t start, size_t order, char dir)
{
	size_t k = order / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (order > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", order, size, str);
		print_array(arr + start, order);

		bitonicSort(arr, size, start, k, UP);
		bitonicSort(arr, size, start + k, k, DOWN);
		bitonicMerge(arr, size, start, order, dir);

		printf("Result [%lu/%lu] (%s):\n", order, size, str);
		print_array(arr + start, order);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *	using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonicSort(array, size, 0, size, UP);
}
