#include "sort.h"

/**
 * merge_suubarr_ - Sort a subarray of int
 * @sbarr: subarray of an array of int to sort
 * @buf: buffer to store the sorted subarray
 * @front: front index of array
 * @mid: middle index of array
 * @back: back index of array
 */
void merge_suubarr_(int *sbarr, int *buf, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, x = 0;

	printf("Merging...\n[left]: ");
	print_array(sbarr + front, mid - front);

	printf("[right]: ");
	print_array(sbarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; x++)
		buf[x] = (sbarr[i] < sbarr[j]) ? sbarr[i++] : sbarr[j++];
	for (; i < mid; i++)
		buf[x++] = sbarr[i];
	for (; j < back; j++)
		buf[x++] = sbarr[j];
	for (i = front, x = 0; i < back; i++)
		sbarr[i] = buf[x++];

	printf("[Done]: ");
	print_array(sbarr + front, back - front);
}

/**
 * merg_sort_recurs - Implement merge sort algorithm through recursion
 * @sbarr: subarray of an array of int to sort
 * @buf: buffer to store the sorted result
 * @front: front index of subarray
 * @back: back index of subarray
 */
void merg_sort_recurs(int *sbarr, int *buf, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merg_sort_recurs(sbarr, buf, front, midd);
		merg_sort_recurs(sbarr, buf, midd, back);
		merge_suubarr_(sbarr, buf, front, midd, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *bf;

	if (array == NULL || size < 2)
		return;

	bf = malloc(sizeof(int) * size);
	if (bf == NULL)
		return;

	merg_sort_recurs(array, bf, 0, size);

	free(bf);
}
