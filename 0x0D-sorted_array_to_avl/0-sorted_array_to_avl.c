#include "binary_trees.h"

/**
 * create_alv_node - create a node for a binary tree
 * @n: value to insert in the node
 * Return: a node on succes
 */
avl_t *create_alv_node(int n)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * make_binary_tree - make the avl binary tree
 * @array: list of number to convert to b_tree
 * @first: index of the first num in the list
 * @last: index of the last num in the list
 * @parent: pointer with the parent address
 * @or: n--neutro, l--left, r--right position
 * Return: a pointer head of the tree in succes, NULL otherwise
 */
avl_t *make_binary_tree(int *array, size_t first, size_t last,
	avl_t *parent, char or)
{
	avl_t *new_node = NULL, *last_node = NULL;

	if (last - first > 1)
	{
		new_node = create_alv_node(array[(int)((last + first) / 2) - 1]);
		new_node->parent = parent;
		if (or == 'l')
			parent->left = new_node;
		else if (or == 'r')
			parent->right = new_node;
		make_binary_tree(array, first, (int)((last + first) / 2) - 1, new_node, 'l');
		make_binary_tree(array, (int)((last + first) / 2) + 1, last, new_node, 'r');
	}
	else if (last - first == 1)
	{
		new_node = create_alv_node(array[last - 1]);
		last_node = create_alv_node(array[first - 1]);
		if (or == 'l')
		{
			parent->left = new_node, new_node->parent = parent;
			last_node->parent = new_node, new_node->left = last_node;
		}
		else if (or == 'r')
		{
			parent->right = last_node, last_node->parent = parent;
			new_node->parent = last_node, last_node->right = new_node;
		}
		else
			new_node->left = last_node, last_node->parent = new_node;
	}
	else
	{
		new_node = create_alv_node(array[last - 1]);
		new_node->parent = parent;
		if (or == 'l')
			parent->left = new_node;
		else if (or == 'r')
			parent->right = new_node;
	}
	return (new_node);
}

/**
 * sorted_array_to_avl - convert a sorted array to an avl b_tree
 * @array: sorted list of numbers
 * @size: size of the array
 * Return: a pointer head of the tree in succes, NULL otherwise
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (make_binary_tree(array, 1, size, NULL, 'n'));
}
