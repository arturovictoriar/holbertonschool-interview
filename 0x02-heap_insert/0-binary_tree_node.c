#include "binary_trees.h"

/**
 * binary_tree_node - create a node
 * @parent: pointer to pointer of first node of binary_trees_t
 * @value: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	new_node->parent = parent;

	return (new_node);
}
