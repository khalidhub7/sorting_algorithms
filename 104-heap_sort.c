#include "sort.h"

/**
 * swp_int4 - Swap 2 ints in array
 * @x: first integer to swap
 * @b: second integer to swap
 */
void swp_int4(int *x, int *b)
{
	int tmpp;

	tmpp = *x;
	*x = *b;
	*b = tmpp;
}

/**
 * max_hea - Turn a binary tree into a complete binary heap
 * @array: array of int representing a binary tree
 * @size: size of the array/tree
 * @basee: index of the base row of the tree
 * @root: root node of the binary tree
 */
void max_hea(int *array, size_t size, size_t basee, size_t root)
{
	size_t left, right, largee;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largee = root;

	if (left < basee && array[left] > array[largee])
		largee = left;
	if (right < basee && array[right] > array[largee])
		largee = right;

	if (largee != root)
	{
		swp_int4(array + root, array + largee);
		print_array(array, size);
		max_hea(array, size, basee, largee);
	}
}

/**
 * heap_sort - Sort an array of ints in ascending
 *             order using the heap sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swp_int4(array, array + i);
		print_array(array, size);
		max_hea(array, size, i, 0);
	}
}
