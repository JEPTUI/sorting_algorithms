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
 * hoare_partition - implements hoare partition scheme
 * @array: array of integers
 * @left: start index
 * @right: end index
 * @size: size of an array
 * Return: partition index
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int high, low;

	for (high = left - 1, low = right + 1; high < low;)
	{
		do {
			high++;
		} while (array[high] < pivot);
		do {
			low--;
		} while (array[low] > pivot);

		if (high < low)
		{
			swap_sort(array + high, array + low);
			print_array(array, size);
		}
	}
	return (high);
}

/**
 * quickSort_hoare - sorts array recursively
 * @array: array of integers
 * @left: start
 * @right: end
 * @size: size of array
 */
void quickSort_hoare(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (right - left > 0)
	{
		pivot_index = hoare_partition(array, left, right, size);
		quickSort_hoare(array, left, size, pivot_index - 1);
		quickSort_hoare(array, size, pivot_index, right);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *	using the Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort_hoare(array, size, 0, size - 1);
}
