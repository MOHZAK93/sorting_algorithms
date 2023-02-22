#include "sort.h"
/**
 * cocktail_sort_list - sorts an array of integers in ascending
 * order using cocktail sort algorithm
 *
 * @list: list to be sorted
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
				swap_list_nodes(temp->next, temp, list);
			else
				temp = temp->next;
		}
		tail = temp;
		while (temp->prev != head)
		{
			if (temp->n < temp->prev->n)
				swap_list_nodes(temp, temp->prev, list);
			else
				temp = temp->prev;
		}
		head = temp;
	} while (head != tail);
}

/**
 * swap_list_nodes - swap adjacent nodes
 *
 * @a: first node
 * @b: second node
 * @list: list
 */
void swap_list_nodes(listint_t *a, listint_t *b, listint_t **list)
{
	listint_t *c, *d;

	c = a->next;
	d = b->prev;
	if (c)
		c->prev = b;
	if (d)
		d->next = a;
	a->prev = d;
	b->next = c;
	a->next = b;
	b->prev = a;
	if (*list == b)
		*list = a;
	print_list(*list);
}
