#include "sort.h"

/**
 * swp_intt - Swap 2 int in an array.
 * @x: The first integer to swap.
 * @g: The second integer to swap.
 */
void swp_intt(int *x, int *g)
{
	int tmp;

	tmp = *x;
	*x = *g;
	*g = tmp;
}

/**
 * selection_sort - Sort an array of int in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minin_;
	size_t i, h;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minin_ = array + i;
		for (h = i + 1; h < size; h++)
			minin_ = (array[h] < *minin_) ? (array + h) : minin_;

		if ((array + i) != minin_)
		{
			swp_intt(array + i, minin_);
			print_array(array, size);
		}
	}
}
