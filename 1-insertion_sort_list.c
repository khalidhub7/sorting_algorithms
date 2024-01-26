#include "sort.h"
/**
 * swp - function that swap 2 nodes in doubly linked list
 * @x: address of first node
 * @y: address of second node
 *
 * Return: void
*/
void swp(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y-prev = x->prev;
	x->prev = y;
	y->next = x;
}
/**
 * insertion_sort_list - insertion sort in doubly linked list
 * @list: address of ptr to head node
 *
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swp(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
