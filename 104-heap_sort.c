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
 * heap_swap - convert into a binary heap
 * @arr: array of integers
 * @size: size
 * @child : index of the base row
 * @root: root node
 */
void heap_swap(int *arr, size_t size, unsigned int child, unsigned int root)
{
	unsigned int start, end, max;

	start = 2 * root + 1;
	end = 2 * root + 2;
	max = root;
	if (start < child && arr[start] > arr[max])
		max = start;
	if (end < child && arr[end] > arr[max])
		max = end;
	if (max != root)
	{
		swap_sort(arr + root, arr + max);
		print_array(arr, size);
		heap_swap(arr, size, child, max);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 *	using the Heap sort algorithm
 * @array: array of integers
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		heap_swap(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap_sort(array, array + i);
		print_array(array, size);
		heap_swap(array, size, i, 0);
	}
}
