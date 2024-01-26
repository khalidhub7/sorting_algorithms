#include "sort.h"

/**
 * geet_maxx - Get the maximum value in an array of int
 * @array: array of int
 * @sizee: size of array
 *
 * Return: The maximum integer in the array.
 */
int geet_maxx(int *array, int sizee)
{
	int maxx, i;

	for (maxx = array[0], i = 1; i < sizee; i++)
	{
		if (array[i] > maxx)
			maxx = array[i];
	}

	return (maxx);
}

/**
 * counting_sort - Sort an array of int in ascending order
 *                 using the counting sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *countt, *sorted, maxx, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxx = geet_maxx(array, size);
	countt = malloc(sizeof(int) * (maxx + 1));
	if (countt == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maxx + 1); i++)
		countt[i] = 0;
	for (i = 0; i < (int)size; i++)
		countt[array[i]] += 1;
	for (i = 0; i < (maxx + 1); i++)
		countt[i] += countt[i - 1];
	print_array(countt, maxx + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[countt[array[i]] - 1] = array[i];
		countt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(countt);
}
