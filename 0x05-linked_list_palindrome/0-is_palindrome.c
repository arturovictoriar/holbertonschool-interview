#include "lists.h"

/**
 * is_palindrome - check if the single linked list (sll) is a palindrome
 * @head: first element of the sll
 * Return: 1 on succes 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *copy_head = *head;
    int len_head = 0, array_head[3000], i = 0;

    if (!*head)
        return (1);

    while (copy_head)
    {
        array_head[len_head] = copy_head->n;
        len_head++, copy_head = copy_head->next;
    }

    for (i = 0; i < len_head; i++)
        if (array_head[i] != array_head[len_head - 1 - i] || i > len_head / 2)
            break;

    if (i <= len_head / 2)
        return (0);
    return (1);
}