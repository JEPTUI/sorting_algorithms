#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 *	using the bubble-sort algorithm
 * @array: array of integers to sort
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swap;
	size_t i, new_size = size;

	if (array == NULL || size < 2)
		return;
	while (new_size)
	{
		swap = 0;
		for (i = 0; i < new_size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		new_size--;
		if (!swap)
			break;
	}
}
