#include "sort.h"

/**
 * swp_nod_ahead_ - Swap a node in a listint_t doubly-linked list
 *                   list of int with the node ahead of it
 * @list: pointer to the head of a doubly-linked list of integers
 * @tail: pointer to the tail of the doubly-linked list
 * @shker: pointer to the current swapping node of the cocktail shaker algo
 */
void swp_nod_ahead_(listint_t **list, listint_t **tail, listint_t **shker)
{
	listint_t *tmpp = (*shker)->next;

	if ((*shker)->prev != NULL)
		(*shker)->prev->next = tmpp;
	else
		*list = tmpp;
	tmpp->prev = (*shker)->prev;
	(*shker)->next = tmpp->next;
	if (tmpp->next != NULL)
		tmpp->next->prev = *shker;
	else
		*tail = *shker;
	(*shker)->prev = tmpp;
	tmpp->next = *shker;
	*shker = tmpp;
}

/**
 * swpp_nod_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it
 * @list: pointer to the head of a doubly-linked list of integers
 * @tail: pointer to the tail of the doubly-linked list
 * @shker: pointer to the current swapping node of the cocktail shaker algo
 */
void swpp_nod_behind(listint_t **list, listint_t **tail, listint_t **shker)
{
	listint_t *tmp = (*shker)->prev;

	if ((*shker)->next != NULL)
		(*shker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shker)->next;
	(*shker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shker;
	else
		*list = *shker;
	(*shker)->next = tmp;
	tmp->prev = *shker;
	*shker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shker;
	bool shaken_n_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_n_stirred == false)
	{
		shaken_n_stirred = true;
		for (shker = *list; shker != tail; shker = shker->next)
		{
			if (shker->n > shker->next->n)
			{
				swp_nod_ahead_(list, &tail, &shker);
				print_list((const listint_t *)*list);
				shaken_n_stirred = false;
			}
		}
		for (shker = shker->prev; shker != *list;
				shker = shker->prev)
		{
			if (shker->n < shker->prev->n)
			{
				swpp_nod_behind(list, &tail, &shker);
				print_list((const listint_t *)*list);
				shaken_n_stirred = false;
			}
		}
	}
}
