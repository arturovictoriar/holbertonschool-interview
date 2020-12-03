#include "search_algos.h"

/**
 * b - Searching in binary tree
 * @array: list of integers
 * @l: first element in the array
 * @r: last element in the array
 * @v: value to search
 * Return: the index of the value found, -1 otherwise
 */
int b(int *array, int l, int r, int v)
{
	int mid = -1, result_l = -1, result_r = -1, i = 0;

	if (l > r)
		return (-1);

	printf("Searching in array: ");
	for (i = l; i <= r; i++)
	{
		if (i != l)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	mid = (l + r) / 2;

	if (mid == l && array[mid] > v)
		return (-1);
	else if (mid == l && array[mid] == v)
		return (mid);

	if (array[mid] >= v)
		result_l = b(array, l, mid, v);
	else
		result_r = b(array, mid + 1, r, v);

	if (result_l != -1)
		return (result_l);
	else if (result_r != -1)
		return (result_r);
	return (-1);
}

/**
 * advanced_binary - searches the first value in a sorted array of integers
 * @array: list of integers
 * @size: lenght list
 * @value: value to searches
 * Return: the index of the value found, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (b(array, 0, (int) size - 1, value));
}
