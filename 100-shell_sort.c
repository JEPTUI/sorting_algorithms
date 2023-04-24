#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 *	using the Shell sort algorithm
 * @array: array of integers
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap = 1, i = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		i = gap /= 3;
		gap = i;
	}
}
