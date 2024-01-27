#include "sort.h"

/**
 * swp_int6 - Swap 2 ints in array
 * @a: first int to swap
 * @y: second int to swap
 */
void swp_int6(int *a, int *y)
{
	int tmmp;

	tmmp = *a;
	*a = *y;
	*y = tmmp;
}

/**
 * ho_part - Order a subset of array of ints
 *                   according to the hoare partition scheme
 * @arr: array of integers
 * @siz: size of array
 * @lef: starting index of subset to order
 * @rig: ending index of subset to order
 *
 * Return: The final partition index
 *
 * Description: Uses the last element of the partition as the pivot
 * Prints the array after each swap of two elements
 */
int ho_part(int *arr, size_t siz, int lef, int rig)
{
	int piv, abo, bel;

	piv = arr[rig];
	for (abo = lef - 1, bel = rig + 1; abo < bel;)
	{
		do {
			abo++;
		} while (arr[abo] < piv);
		do {
			bel--;
		} while (arr[bel] > piv);

		if (abo < bel)
		{
			swp_int6(arr + abo, arr + bel);
			print_array(arr, siz);
		}
	}

	return (abo);
}

/**
 * ho_sort - Implement quicksort algorithm through recursion
 * @arr: array of ints to sort
 * @siz: size of array
 * @lef: starting index of array partition to order
 * @rig: ending index of array partition to order
 *
 * Description: Uses the Hoare partition scheme
 */
void ho_sort(int *arr, size_t siz, int lef, int rig)
{
	int par;

	if (rig - lef > 0)
	{
		par = ho_part(arr, siz, lef, rig);
		ho_sort(arr, siz, lef, par - 1);
		ho_sort(arr, siz, par, rig);
	}
}

/**
 * quick_sort_hoare - Sort an array of int in ascending
 *                    order using the quicksort algorithm
 * @array: array of inte
 * @size: Tsize of array
 *
 * Description: Uses the Hoare partition scheme. Prints
 * array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	ho_sort(array, size, 0, size - 1);
}
