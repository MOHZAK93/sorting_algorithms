#include "sort.h"
/**
 * cocktail_sort_list - sorts an array of integers in ascending
 * order using cocktail sort algorithm
 *
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail, *temp;

	if (!list || !*list)
		return;
	temp = *list;
	head = tail = NULL;
	do {
		while (temp->next)
		{
			if (temp->n > temp->next->n)
				swap_listint_t(temp->next, temp, list);
			else
				temp = temp->next;
		}
		tail = temp;
		while (temp->prev != head)
		{
			if (temp->n < temp->prev->n)
				swap_listint_t(temp, temp->prev, list);
			else
				temp = temp->prev;
		}
		head = temp;
	} while (head != tail);
}

/**
 * swap_node - swap adjacent nodes
 *
 * @x: first node
 * @y: second node
 */

void swap_node(listint_t *x, listint_t *y)
{
	x->next = y->next;
	if (y->next)
		y->next->prev = x;
	y->next = x;

	y->prev = x->prev;
	if (x->prev)
		x->prev->next = y;
	x->prev = y;
}
