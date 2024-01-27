#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>
/*#include <time.h>*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/*print*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/*task prototypes*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swp(listint_t *x, listint_t *y);

void selection_sort(int *array, size_t size);
void swp_intt(int *x, int *g);

void swp_int2(int *x, int *b);
int lomt_parti(int *array, size_t size, int left, int right);
void lomt_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);
void swp_int3(int *a, int *b);

void swp_nod_ahead_(listint_t **list, listint_t **tail, listint_t **shker);
void swpp_nod_behind(listint_t **list, listint_t **tail, listint_t **shker);
void cocktail_sort_list(listint_t **list);

int geet_maxx(int *array, int sizee);
void counting_sort(int *array, size_t size);

void swp_int4(int *x, int *b);
void max_hea(int *array, size_t size, size_t basee, size_t root);
void heap_sort(int *array, size_t size);

int get_mxx(int *array, int size);
void radx_count_srt(int *array, size_t size, int sg, int *bff);
void radix_sort(int *arr, size_t size);

#define UP 0
#define DOWN 1
void swp_int5(int *x, int *b);
void btnic_mrg(int *arr, size_t size, size_t star, size_t se,
		char flo);
void btnic_se_(int *ar, size_t si, size_t st, size_t se, char fl);
void bitonic_sort(int *ar, size_t si);

void swp_int6(int *a, int *y);
int ho_part(int *arr, size_t siz, int lef, int rig);
void ho_sort(int *arr, size_t siz, int lef, int rig);
void quick_sort_hoare(int *array, size_t size);






void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
#endif
