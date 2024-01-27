#include "deck.h"

/**
 * _strcmp - Compare two strings
 * @st1: first str to compare
 * @st2: second str to compare
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *st1, const char *st2)
{
	while (*st1 && *st2 && *st1 == *st2)
	{
		st1++;
		st2++;
	}

	if (*st1 != *st2)
		return (*st1 - *st2);
	return (0);
}

/**
 * g_value - Get the numerical value of a card
 * @card: pointer to deck_node_t card
 *
 * Return: numerical value of card
 */
char g_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * ins_sort_deck_kind - Sort a deck of cards from spades to diamonds_
 * @dec: pointer to head of a deck_node_t doubly-linked list_
 */
void ins_sort_deck_kind(deck_node_t **dec)
{
	deck_node_t *ite, *ins, *tmp;

	for (ite = (*dec)->next; ite != NULL; ite = tmp)
	{
		tmp = ite->next;
		ins = ite->prev;
		while (ins != NULL && ins->card->kind > ite->card->kind)
		{
			ins->next = ite->next;
			if (ite->next != NULL)
				ite->next->prev = ins;
			ite->prev = ins->prev;
			ite->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = ite;
			else
				*dec = ite;
			ins->prev = ite;
			ins = ite->prev;
		}
	}
}

/**
 * ins_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king_
 * @dec: A pointer to the head of a deck_node_t doubly-linked list_
 */
void ins_sort_deck_value(deck_node_t **dec)
{
	deck_node_t *ite, *ins, *tmp;

	for (ite = (*dec)->next; ite != NULL; ite = tmp)
	{
		tmp = ite->next;
		ins = ite->prev;
		while (ins != NULL &&
		       ins->card->kind == ite->card->kind &&
		       g_value(ins) > g_value(ite))
		{
			ins->next = ite->next;
			if (ite->next != NULL)
				ite->next->prev = ins;
			ite->prev = ins->prev;
			ite->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = ite;
			else
				*dec = ite;
			ins->prev = ite;
			ins = ite->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds_______
 * @deck: pointer to head of a deck_node_t doubly-linked list
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	ins_sort_deck_kind(deck);
	ins_sort_deck_value(deck);
}
