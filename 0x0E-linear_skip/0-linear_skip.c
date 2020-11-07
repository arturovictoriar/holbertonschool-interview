#include "search.h"

/**
 * linear_skip - Linear search in a skip list
 * @list: linked list array with all the number
 * @value: value to search
 * Return: a pointer of the value found, NULL otherwise
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *list_c = list, *next_ex = NULL;

	if (!list)
		return (NULL);
	if (list_c->express && (list_c->index == list_c->express->index))
		return (printf("Value checked at index [%u] = [%d]\n",
					   (unsigned int)list_c->index, list_c->n),
				(list_c->n == value) ? list_c : NULL);
	while (list_c->express)
	{
		printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)list_c->express->index, list_c->express->n);
		if (value >= list_c->n && value <= list_c->express->n)
		{
			printf("Value found between indexes [%u] and [%u]\n",
				   (unsigned int)list_c->index, (unsigned int)list_c->express->index);
			break;
		}
		list_c = list_c->express;
	}
	if (!list_c->express)
	{
		next_ex = list_c;
		while (next_ex->next)
			next_ex = next_ex->next;
		printf("Value found between indexes [%u] and [%u]\n",
			   (unsigned int)list_c->index, (unsigned int)next_ex->index);
	}
	next_ex = list_c->express;
	while (list_c)
	{
		printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)list_c->index, list_c->n);
		if (list_c == next_ex || list_c->n == value)
			break;
		list_c = list_c->next;
	}
	if (!list_c || (list_c == next_ex && list_c->n != next_ex->n))
		return (NULL);
	return (list_c);
}
