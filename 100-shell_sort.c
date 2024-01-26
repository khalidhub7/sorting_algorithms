#include "sort.h"
/**
 * shell_sort - Sort an array of int in ascending
 *              order using the shell sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gappp, i, j;

	if (array == NULL || size < 2)
		return;

	for (gappp = 1; gappp < (size / 3);)
		gappp = gappp * 3 + 1;

	for (; gappp >= 1; gappp /= 3)
	{
		for (i = gappp; i < size; i++)
		{
			j = i;
			while (j >= gappp && array[j - gappp] > array[j])
			{
				swp_int2(array + j, array + (j - gappp));
				j -= gappp;
			}
		}
		print_array(array, size);
	}
}
