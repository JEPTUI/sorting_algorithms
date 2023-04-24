#include "sort.h"
/**
 * selection_sort - sorts an array of integers in
 *	ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: size
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_idx, temp, index = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min_idx)
			{
				min_idx = array[j];
				index = j;
			}
		}
		if (min_idx != array[i])
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
