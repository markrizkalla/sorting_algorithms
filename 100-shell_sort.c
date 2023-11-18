#include "sort.h"

/**
 * calc_gap - Calculate gap distance in array
 * using Knuth sequence
 * @size: size of array
 * Return: The gap distance
 */

size_t calc_gap(size_t size)
{
	size_t h = 1;

	while (h < size / 3)
	{
		h = (h * 3) + 1;
	}

	return (h);
}
/**
 * shell_sort - sort array of integer in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size == 1)
		return;
	size_t h = calc_gap(size);

	while (h > 0)
	{
		size_t out;

		for (out = h; out < size; out++)
		{
			int temp = array[out];
			size_t in;

			in = out;
			while (in > h - 1 && array[in - h] >= temp)
			{
				array[in] = array[in - h];
				in = in - h;
			}

			array[in] = temp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}

}
