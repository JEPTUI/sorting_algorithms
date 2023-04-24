#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *nextnode, *temp;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	sorted = (*list)->next;
	nextnode = sorted->next;
	while (sorted)
	{
		if (sorted->n < sorted->prev->n)
		{
			temp = sorted->prev;
			while (temp && (sorted->n < temp->n))
			{
				if (!(temp->prev))
				{
					temp->prev = sorted;
					sorted->prev->next = sorted->next;
					if (sorted->next)
						sorted->next->prev = sorted->prev;
					sorted->next = temp;
					sorted->prev = NULL;
					*list = sorted;
				}
				else
				{
					sorted->prev->next = sorted->next;
					if (sorted->next)
						sorted->next->prev = sorted->prev;
					temp->prev->next = sorted;
					sorted->prev = temp->prev;
					temp->prev = sorted;
					sorted->next = temp;
				}
				print_list(*list);
				temp = sorted->prev;
			}
		}
		sorted = nextnode;
		sorted ? (nextnode = sorted->next) : (nextnode = NULL);
	}
}
