#include "lists.h"

/**
* find_listint_loop - find the first node of a loop in a linked list
* @head: pointer with the first position of the linked list
* Return: A pointer with the begin of the loop, NULL otherwise
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t = NULL, *h = NULL;

	t = JUMP_T(head);
	if (t)
		h = JUMP_H(head);
	else
		return (NULL);

	while (t != h)
	{
		t = JUMP_T(t), h = JUMP_T(h) ? JUMP_H(h) : NULL;
		if (t == NULL || h == NULL)
			return (NULL);
	}

	t = head;
	while (t != h)
		t = JUMP_T(t), h = JUMP_T(h);

	return (t);
}
