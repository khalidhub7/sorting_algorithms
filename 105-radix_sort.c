#include "sort.h"

/**
 * get_mxx - Get the maximum value in an array of ints
 * @arr: array of int
 * @size: size of array
 *
 * Return: The maximum int in array
 */
int get_mxx(int *arr, int size)
{
	int ma, x;

	for (ma = arr[0], x = 1; x < size; x++)
	{
		if (arr[x] > ma)
			ma = arr[x];
	}

	return (ma);
}

/**
 * radx_count_srt - Sort significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm
 * @array: array of ints
 * @size: size of array
 * @sg: significant digit to sort on
 * @bff: A buffer to store the sorted array
 */
void radx_count_srt(int *array, size_t size, int sg, int *bff)
{
	int cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		cont[(array[i] / sg) % 10] += 1;

	for (i = 0; i < 10; i++)
		cont[i] += cont[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		bff[cont[(array[i] / sg) % 10] - 1] = array[i];
		cont[(array[i] / sg) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = bff[i];
}

/**
 * radix_sort - Sort array of ints in ascending
 *              order using the radix sort algorithm
 * @arr: array of ints
 * @size: size of array
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase
 */
void radix_sort(int *arr, size_t size)
{
	int max, sig, *buff;

	if (arr == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_mxx(arr, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radx_count_srt(arr, size, sig, buff);
		print_array(arr, size);
	}

	free(buff);
}
