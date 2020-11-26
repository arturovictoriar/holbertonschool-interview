#include "sort.h"

/**
 * swap_heap - interchange 2 values of a given list
 * @arr: list of numbers
 * @index1: index of the value1 to swap
 * @index2: index of the value2 to swap
 * @len_arr: original len arr
 * Return: Nothing
 */
void swap_heap(int *arr, size_t index1, size_t index2, size_t len_arr)
{
	int temp = 0;

	temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
	print_array(arr, len_arr);
}

/**
 * heapify - organize the given list into max heap
 * @arr: list of integers
 * @node: parent node
 * @len_heap: len of the heap sort arr
 * @len_arr: original len array
 * Return: Nothing
 */
void heapify(int *arr, size_t node, size_t len_heap, size_t len_arr)
{
	size_t pre_node = node;
	size_t child_left = (node * 2) + 1, child_right = (node * 2) + 2;

	if (child_left < len_heap && arr[child_left] > arr[node])
		node = child_left;

	if (child_right < len_heap && arr[child_right] > arr[node])
		node = child_right;

	if (pre_node != node)
		(swap_heap(arr, pre_node, node, len_arr),
		 heapify(arr, node, len_heap, len_arr));
}

/**
 * heap_sort - sort a given list using heapsort
 * @array: list of integers
 * @size: len of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t node = 0, len_heap = size - 1;

	for (node = 0; node <= (size / 2) - 1; node++)
		heapify(array, ((size / 2) - 1) - node, size, size);

	for (node = 0; node < size; node++)
	{
		if (size - 1 - node != 0)
			swap_heap(array, 0, len_heap, size);

		heapify(array, 0, len_heap, size);
		len_heap--;
	}
}
