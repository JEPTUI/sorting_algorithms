#include "sort.h"
/**
 * swap - swaps items of alist
 * @tmp: first item to swap
 * @cur: end item to swap
 * @list: doubly linked list
 *
 */
void swap(listint_t *tmp, listint_t *cur, listint_t **list)
{
	if (!(tmp->prev))
	{
		tmp->next = cur->next;
		if (cur->next)
			cur->next->prev = tmp;
		cur->next = tmp;
		cur->prev = NULL;
		tmp->prev = cur;
		*list = cur;
	}
	else
	{
		cur->prev->next = cur->next;
		if (cur->next)
			cur->next->prev = cur->prev;
		tmp->prev->next = cur;
		cur->prev = tmp->prev;
		tmp->prev = cur;
		cur->next = tmp;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 *	ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *nextnode;
	int swapped;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	cur = (*list);
	do {
		swapped = 0;
		while (cur->next)
		{
			nextnode = cur->next;
			if (nextnode && cur->n > nextnode->n)
			{
				swap(cur, nextnode, list);
				swapped = 1;
				print_list((*list));
			}
			else
				cur = cur->next;
		}
		cur = cur->prev;
		while (cur->prev)
		{
			nextnode = cur->prev;
			if (nextnode && cur->n < nextnode->n)
			{
				swap(nextnode, cur, list);
				swapped = 1;
				print_list((*list));
			}
			else
				cur = cur->prev;
		}
		cur = cur->next;
	} while (swapped);
}
