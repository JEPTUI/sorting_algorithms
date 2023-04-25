#include "sort.h"
/**
 * sort_index - sort integers in an array
 * @arr: array of integers
 * @size: size of an array
 * @num_digit: sinificant digit to sort
 * @output_buff: buffer to store sorted array
 */
void sort_index(int *arr, size_t size, int num_digit, int *output_buff)
{
	int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		index[(arr[i] / num_digit) % 10] += 1;
	for (i = 0; i < size; i++)
		index[i] += index[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output_buff[index[(arr[i] / num_digit) % 10] - 1] = arr[i];
		index[(arr[i] / num_digit) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		arr[i] = output_buff[i];
}

/**
 * get_max_val - Get maximum value
 * @arr: array of integers
 * @size: size of array
 */
int get_max_val(int *arr, int size)
{
	int value, i;

	for (value = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > value)
			value = arr[i];
	}
	return (value);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *	using the Radix sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int value, num_digit, *output_buff;

	if (array == NULL || size < 2)
		return;
	output_buff = malloc(sizeof(int) * size);
	if (output_buff == NULL)
		return;
	value = get_max_val(array, size);
	for (num_digit = 1; value / num_digit > 0; num_digit *= 10)
	{
		sort_index(array, size, num_digit, output_buff);
		print_array(array, size);
	}
	free(output_buff);
}
