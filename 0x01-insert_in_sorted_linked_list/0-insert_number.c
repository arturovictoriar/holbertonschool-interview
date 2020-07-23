#include "lists.h"

/**
 * insert_node - insert a new node at the right order
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *prev = NULL;
	listint_t *new = NULL;
	listint_t *current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (current->next != NULL)
		{
			if (new->n > current->n)
			{
				prev = current;
				current = current->next;
			}
			else
				break;
		}
		if (new->n > current->n && current->next == NULL)
		{
			new->next = current->next;
			current->next = new;
		}
		else if (!prev)
		{
			new->next = current;
			*head = new;
		}
		else
		{
			prev->next = new;
			new->next = current;
		}
	}
	return (new);
}
