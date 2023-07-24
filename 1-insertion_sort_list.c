#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the insertion sort agorithm
 * @list: pointer to the address of the list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *temp, *prev;

	if (list == NULL)
	{
		return;
	}

	aux = *list;
	temp = aux->next;
	while (temp != NULL)
	{
		aux = temp;
		temp = temp->next;
		prev = aux->prev;
		while (prev != NULL && (aux->n < prev->n))
		{
			if (prev->prev != NULL)
			{
				prev->prev->next = aux;
			}
			aux->prev = prev->prev;
			prev->next = aux->next;
			if (aux->next != NULL)
			{
				aux->next->prev = prev;
			}
			aux->next = prev;
			prev->prev = aux;
			if (aux->prev == NULL)
			{
				*list = aux;
			}
			prev = aux->prev;
			print_list(*list);
		}
	}
}
