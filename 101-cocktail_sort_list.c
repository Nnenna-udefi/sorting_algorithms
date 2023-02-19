#include "sort.h"

/**
 * swap_nodes - swap two nodes of a doubly linked list
 * @list: doubly linked list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	left = *list;
	right = left;
	while (right->next != NULL)
		right = right->next;
	while (swapped == 1)
	{
		swapped = 0;
		while (left != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				swapped = 1;
				print_list(*list);
			}
			else
				left = left->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		right = right->prev;
		while (right != left)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				swapped = 1;
				print_list(*list);
			}
			else
				right = right->prev;
		}
		left = left->next;
	}
}

