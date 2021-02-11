#include "sort.h"

/**
 * top_down_merge_sort - sort 2 subarray
 * @arr: list of numbers
 * @c_arr: copy of the list
 * @start: start index
 * @mid: mid index
 * @end: end index
 */
void top_down_merge_sort(int *arr, int *c_arr, int start, int mid, int end)
{
	int i = 0, j = 0, k = 0;

	i = start, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&(c_arr[start]), mid - start);
	printf("[right]: ");
	print_array(&(c_arr[mid]), end - mid);

	k = start;
	while (k < end)
	{
		/*Sort depending the value of the head left and head right*/
		if (i < mid && (j >= end || arr[i] <= arr[j]))
		{
			c_arr[k] = arr[i];
			i++;
		}
		else
		{
			c_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	printf("[Done]: ");
	print_array(&(c_arr[start]), end - start);
}

/**
 * arr_cpy - copy an array
 * @array: list of numbers
 * @new_arr: memory to store the array
 * @size: lenght of the array
 * Return: nothing
 */
void arr_cpy(int *array, int *new_arr, size_t size)
{
	size_t i = 0;

	/*Copy the data of the array in the new array*/
	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		i++;
	}
}

/**
 * top_down_merge_split - use divide an conquer to split the array
 * @arr: arr
 * @c_arr: copy array
 * @start: start index
 * @end: end index
 * @s: entire size of arr
 * Return: nothing
 */
void top_down_merge_split(int *arr, int *c_arr, int start, int end, size_t s)
{
	int mid = 0;

	if (end - start <= 1)
		return;
	mid = (end + start) / 2;

	top_down_merge_split(arr, c_arr, start, mid, s);
	top_down_merge_split(arr, c_arr, mid, end, s);
	/*Organize the subarrays*/
	top_down_merge_sort(arr, c_arr, start, mid, end);
	/*update the merge*/
	arr_cpy(c_arr, arr, s);
}

/**
 * merge_sort - sort an array using divide and conquer
 * @array: list of number
 * @size: lenght of the array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *c_array = NULL;

	/*Allocate memory for copy array*/
	c_array = malloc(sizeof(int) * size);
	if (c_array == NULL)
		return;

	/*Copy the entry array*/
	arr_cpy(array, c_array, size);

	/*Divide and conquer sort*/
	top_down_merge_split(array, c_array, 0, (int) size, size);
	/*Copy the data sorted in the entry array*/
	i = 0;
	while (i < size)
	{
		array[i] = c_array[i];
		i++;
	}
	/*Free the heap memory allocated*/
	free(c_array);
}
