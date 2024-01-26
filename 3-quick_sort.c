#include "sort.h"

/**
 * mrge_sbarr - Sort subarray of int
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted subarray
 * @front: front index of the array
 * @mid: middle index of the array
 * @back: back index of the array
 */
void mrge_sbarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * mrge_srt_rec - Implement merge sort algorithm through recursion
 * @subarr: subarray of array of int to sort
 * @buff: buffer to store the sorted result
 * @front: front index of the subarray
 * @back: back index of the subarray
 */
void mrge_srt_rec(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		mrge_srt_rec(subarr, buff, front, mid);
		mrge_srt_rec(subarr, buff, mid, back);
		mrge_sbarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of int in ascending
 *              order using the merge sort algorithm
 * @array: array of int
 * @size: size of array
 *
 * Description: Implements top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mrge_srt_rec(array, buff, 0, size);

	free(buff);
}
