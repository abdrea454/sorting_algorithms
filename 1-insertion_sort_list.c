#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort ailgorithm
 * @list: pointer to the list head
 * Return: no return
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp = curr->prev;
		while (tmp != NULL && tmp->n > curr->n)
		{
			tmp->next->prev = curr;
			curr->prev = tmp->prev;
			if (curr->prev == NULL)
				*list = curr;
			else
				tmp->prev->next = curr;
			tmp->next = curr->next;
			curr->next = tmp;
			tmp->prev = curr;
			tmp = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}

