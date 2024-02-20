#include "sort.h"

/**
 * _swap - swaps two nodes of doubly linked list.
 * @node: node base to change.
 * @list: double link list head.
 * Return: .
 */

void _swap(listint_t **node, listint_t **list)
{
	listint_t *t = *node, *t2, *t3;


	if (!(*node)->prev)
		*list = (*node)->next;

	t = t3 = *node;
	t2 = t->next;

	t->next = t2->next;
	t3 = t->prev;
	t->prev = t2;
	t2->next = t;
	t2->prev = t3;

	if (t2->prev)
		t2->prev->next = t2;


	if (t->next)
		t->next->prev = t;

	*node = t2;

}

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm.
 * @list: head of list to be sortered (Double Linked List).
 * Return: .
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *h, *a;
	int k = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	h = *list;
	while (m >= n)
	{
		n++;
		while (h->next && k != m)
		{
			if (h->n > h->next->n)
			{
				a = h;
			       _swap(&a, list);
			       print_list(*list);
			       h = a;
			}

			k++;
			h = h->next;
		}

		if (n == 0)
			m = k;
		m--;
		while (h->prev && k >= n)
		{
			if (h->n < h->prev->n)
			{
				a = h->prev;
				_swap(&a, list);
				print_list(*list);
				h = a->next;
			}
			k--;
			h = h->prev;
		}
	}
}
