#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using insertion sort
 *
 * @list: doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp;

	if (!list || !(*list))
		return;

	temp = (*list)->next;
	while (temp)
	{
		head = temp;
		temp = temp->next;
		while (head && head->prev)
		{
			if (head->prev->n > head->n)
			{
				swap_node(head->prev, head);
				if (!head->prev)
					*list = head;
				print_list((const listint_t *)*list);
			}
			else
			{
				head = head->prev;
			}
		}
	}
}

/**
 * swap_node - swap two nodes
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
