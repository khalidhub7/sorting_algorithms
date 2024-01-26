#include "sort.h"

/**
 * swp_int2 - Swap 2 int in array.
 * @x: The first integer to swap.
 * @b: The second integer to swap.
 */
void swp_int2(int *x, int *b)
{
	int tmp_;

	tmp_ = *x;
	*x = *b;
	*b = tmp_;
}

/**
 * lomt_parti - Order a subset of an array of int according to
 *                    the lomuto partition scheme (last element as pivot)
 * @array: The array of int
 * @size: size of array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 *
 * Return: The final partition index
 */
int lomt_parti(int *array, size_t size, int left, int right)
{
	int *pivott, aabove, beloow;

	pivott = array + right;
	for (aabove = beloow = left; beloow < right; beloow++)
	{
		if (array[beloow] < *pivott)
		{
			if (aabove < beloow)
			{
				swp_int2(array + beloow, array + aabove);
				print_array(array, size);
			}
			aabove++;
		}
	}

	if (array[aabove] > *pivott)
	{
		swp_int2(array + aabove, pivott);
		print_array(array, size);
	}

	return (aabove);
}

/**
 * lomt_sort - Implement quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomt_sort(int *array, size_t size, int left, int right)
{
	int paart;

	if (right - left > 0)
	{
		paart = lomt_parti(array, size, left, right);
		lomt_sort(array, size, left, paart - 1);
		lomt_sort(array, size, paart + 1, right);
	}
}

/**
 * quick_sort - Sort an array of int in ascending
 *               using the quicksort algorithm
 * @array: An array of int
 * @size: size of array
 *
 * Description: Uses the Lomuto partition scheme Prints
 *              array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomt_sort(array, size, 0, size - 1);
}
