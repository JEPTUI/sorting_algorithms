#include "sort.h"
/**
 * top_down - sorts the array
 * @arr: array of integers to sort
 * @start: starting index
 * @end: ending size index
 * @dup: copy of the array
 */
void top_down(int *arr, ssize_t start, ssize_t end, int *dup)
{
	int i, j, k, mid;

	mid = (start + end) / 2;
	i = start;
	j = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + start, mid - start);
	printf("[right]: ");
	print_array(arr + mid, end - mid);
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || arr[i] <= arr[j]))
		{
			dup[k] = arr[i];
			i = i + 1;
		}
		else
		{
			dup[k] = arr[i];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(dup + start, end - start);
}

/**
 * split_merge - splits and merges halves
 * @arr: array of integers
 * @start: starting index
 * @end: ending index
 * @dup: copy of the array
 */
void split_merge(int *arr, ssize_t start, ssize_t end, int *dup)
{
	int mid = 0;

	mid = (start + end) / 2;
	if (end - start < 2)
		return;
	split_merge(dup, start, mid, arr);
	split_merge(dup, mid, end, arr);
	top_down(arr, start, end, dup);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *	using the Merge sort algorithm
 * @array: array of integers
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *dup = NULL;
	size_t k = 0;

	if (array == NULL || size < 2)
		return;
	dup = malloc(sizeof(int) * size);
	if (dup == NULL)
		return;
	for (k = 0; k < size; k++)
		dup[k] = array[k];
	split_merge(dup, 0, size, array);
	free(dup);
}
