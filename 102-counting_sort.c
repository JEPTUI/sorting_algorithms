#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order
 *	using the Counting sort algorithm
 * @array: array of integers
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int j, k, digi, cp;
	int *index;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	index = malloc(sizeof(int) * (k + 1));
	if (!index)
		return;
	for (j = 0; j < (k + 1); j++)
		index[j] = 0;
	for (i = 0; i < size; i++)
	{
		digi = array[i];
		index[digi] += 1;
	}
	for (j = 0; j < k; j++)
	{
		index[j + 1] += index[j];
	}
	print_array(index, k + 1);
	for (i = 0, j = 0; j < k; j++)
	{
		if ((j == 0) && index[i] != 0)
		{
			for ((cp = index[j]); cp > 0; cp--)
				array[i++] = j;
		}
		if (index[j + 1] > index[j])
		{
			for ((cp = index[j + 1] - index[j]); cp > 0; cp--)
				array[i++] = (j + 1);
		}
	} free(index);
}
