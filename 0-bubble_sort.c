#include "sort.h"
/**
 *bubble_sort - sort array of integer
 *use bubble sort algorithm
 *
 *@array: array of int
 *@size: size of array
 *
*/
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
