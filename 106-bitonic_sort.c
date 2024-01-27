#include "sort.h"

/**
 * swp_int5 - Swap 2 ints in array
 * @x: first integer to swap
 * @b: second integer to swap
 */
void swp_int5(int *x, int *b)
{
	int tmmp;

	tmmp = *x;
	*x = *b;
	*b = tmmp;
}

/**
 * btnic_mrg - Sort bitonic sequence inside an array of int
 * @arr: array of int
 * @size: size of array
 * @star: starting index of sequence in array to sort
 * @se: size of sequence to sort
 * @flo: The direction to sort in
 */
void btnic_mrg(int *arr, size_t size, size_t star, size_t se,
		char flo)
{
	size_t i, jump = se / 2;

	if (se > 1)
	{
		for (i = star; i < star + jump; i++)
		{
			if ((flo == UP && arr[i] > arr[i + jump]) ||
			    (flo == DOWN && arr[i] < arr[i + jump]))
				swp_int5(arr + i, arr + i + jump);
		}
		btnic_mrg(arr, size, star, jump, flo);
		btnic_mrg(arr, size, star + jump, jump, flo);
	}
}

/**
 * btnic_se_ - Convert array of ints into a bitonic sequence
 * @ar: array of ints
 * @si: size of array
 * @st: starting index of a block of the building bitonic sequence
 * @se: size of a block of the building bitonic sequence
 * @fl: direction to sort the bitonic sequence block in
 */
void btnic_se_(int *ar, size_t si, size_t st, size_t se, char fl)
{
	size_t cutt = se / 2;
	char *str = (fl == UP) ? "UP" : "DOWN";

	if (se > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", se, si, str);
		print_array(ar + st, se);

		btnic_se_(ar, si, st, cutt, UP);
		btnic_se_(ar, si, st + cutt, cutt, DOWN);
		btnic_mrg(ar, si, st, se, fl);

		printf("Result [%lu/%lu] (%s):\n", se, si, str);
		print_array(ar + st, se);
	}
}

/**
 * bitonic_sort - Sort array of ints in ascending
 *                order using the bitonic sort algorithm
 * @ar: array of int
 * @si: size of array
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */
void bitonic_sort(int *ar, size_t si)
{
	if (ar == NULL || si < 2)
		return;

	btnic_se_(ar, si, 0, si, UP);
}
