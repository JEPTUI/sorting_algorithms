#include "deck.h"

/**
 * _strcmp - compares two strings
 * @str: first string
 * @s: second string
 * Return: string comparison
 */
int _strcmp(const char *str, const char *s)
{
	while (*str && *s && *str == *s)
	{
		str++;
		s++;
	}

	if (*str != *s)
		return (*str - *s);
	return (0);
}

/**
 * card_val - gets a value of a card
 * @card: pointer to a deck of cards
 * Return: card value
 */
char card_val(deck_node_t *card)
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
 * insertionSort - sort deck of cards
 * @deck: deck of cards to sort
 *
 */
void insertionSort(deck_node_t **deck)
{
	deck_node_t *i, *j, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j != NULL && j->card->kind > i->card->kind)
		{
			j->next = i->next;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			i->next = j;
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*deck = i;
			j->prev = i;
			j = i->prev;
		}
	}
}
/**
 * insert_sort - sort sorted cards from diamonds to kings
 * @deck: deck of cards
 *
 */
void insert_sort(deck_node_t **deck)
{
	deck_node_t *i, *j, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j != NULL && j->card->kind == i->card->kind &&
				card_val(j) > card_val(i))
		{
			j->next = i->next;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			i->next = j;
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*deck = i;
			j->prev = i;
			j = i->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck of cards
 *
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck)
		return;
	insertionSort(deck);
	insert_sort(deck);
}
