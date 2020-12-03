#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	int array[] = {
		0, 1, 2, 5, 5, 6, 6, 7, 8, 9
	};
	int array1[] = {
		4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7
	};
	size_t size1 = sizeof(array1) / sizeof(array1[0]);
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
	printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
	printf("Found %d at index: %d\n\n", 999, advanced_binary(array, size, 999));
	printf("Found %d at index: %d\n\n", 2, advanced_binary(array, size, 2));
	printf("Found %d at index: %d\n\n", 1, advanced_binary(array, size, 1));
	printf("Found %d at index: %d\n\n", -1, advanced_binary(array, size, -1));
	printf("Found %d at index: %d\n\n", 4, advanced_binary(array, size, 4));

	printf("Found %d at index: %d\n\n", 5, advanced_binary(array1, size1, 5));
	printf("Found %d at index: %d\n\n", 4, advanced_binary(array1, size1, 4));
	printf("Found %d at index: %d\n\n", 7, advanced_binary(array1, size1, 7));
	printf("Found %d at index: %d\n\n", 8, advanced_binary(array1, size1, 8));
	return (0);
}
