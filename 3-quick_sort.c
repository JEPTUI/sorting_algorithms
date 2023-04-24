#include "sort.h"
/**
 * partition - partitions the array
 * @array: array of integers
 * @left: start of array
 * @right: end of array
 * @size: array size
 * Return: pivot number
 */
int partition(int *array, ssize_t left, ssize_t right, size_t size)
{
	int pivot = array[right];
	ssize_t i = left, j, temp;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != right)
	{
		temp = array[i];
		array[i] = array[right];
		array[right] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quickSort - quick sort function
 * @array: array of integers
 * @left: start of array
 * @right: end of array
 * @size: size of array
 */
void quickSort(int *array, ssize_t left, ssize_t right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quickSort(array, left, pivot - 1, size);
		quickSort(array, pivot + 1, right, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 *	order using the Quick sort algorithm
 * @array: array of integers
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
