#include "sort.h"

/**
 * swp_int3 - Swap 2 int in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swp_int3(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort array of int in ascending
 *              order using the shell sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t ggap, i, j;

	if (array == NULL || size < 2)
		return;

	for (ggap = 1; ggap < (size / 3);)
		ggap = ggap * 3 + 1;

	for (; ggap >= 1; ggap /= 3)
	{
		for (i = ggap; i < size; i++)
		{
			j = i;
			while (j >= ggap && array[j - ggap] > array[j])
			{
				swp_int3(array + j, array + (j - ggap));
				j -= ggap;
			}
		}
		print_array(array, size);
	}
}
