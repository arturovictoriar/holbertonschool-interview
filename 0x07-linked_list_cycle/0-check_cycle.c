#include "lists.h"

/**
* check_cycle - Check if exist a cicle in the list
* @list: single linked list with numbers
* Return: 0 no cycle, 1 cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *hare = list, *turtle = list;

	if (!list)
		return (0);

	while (turtle)
	{
		if (!(hare->next) || !(hare->next->next))
			break;
		turtle = turtle->next, hare = hare->next->next;
		if (hare == turtle)
			return (1);
	}
	return (0);
}
