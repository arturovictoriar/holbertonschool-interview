#include "sort.h"

/**
* max_num - find the maximun value number in a array
* @arr: list of numbers
* @size: array length
* Return: the maximun number of an array
*/
int max_num(int *arr, size_t size)
{
	int max_n = 0;
	size_t i = 0;

	for (max_n = arr[0], i = 1; i < size; i++)
		if (arr[i] > max_n)
			max_n = arr[i];

	return (max_n);
}

/**
* radix_order - sort a list depending a specific digit
* @arr: list of numbers
* @size: array length
* @d: digit represent units, decend, etc..
* Return: the array orderer by a specific digit, NULL otherwise
*/
int *radix_order(int *arr, size_t size, int d)
{
	int *sort_d = NULL, dig[10] = {0}, j = 0;
	size_t i = 0;

	sort_d = malloc(sizeof(int) * size);
	if (!sort_d)
		return (NULL);

	for (i = 0; i < size; i++)
		dig[(arr[i] / d) % 10]++;

	for (i = 1; i < 10; i++)
		dig[i] += dig[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		sort_d[dig[(arr[j] / d) % 10] - 1] = arr[j];
		dig[(arr[j] / d) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = sort_d[i];

	free(sort_d);
	return (arr);
}

/**
* radix_sort - sort an array using radix sort method
* @array: list of numbers
* @size: array length
* Return: Nothing
*/
void radix_sort(int *array, size_t size)
{
	int max_n = 0, dig = 0;

	if (array == NULL && size < 2)
		return;

	max_n = max_num(array, size);
	for (dig = 1; (max_n / dig) > 0; dig *= 10)
	{
		if (!radix_order(array, size, dig))
			return;
		print_array(array, size);
	}
}
