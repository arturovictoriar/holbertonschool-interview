#include "binary_trees.h"

/**
 * swap_numbers - swap two numbers in nodes
 * @node_1: first pointer node of binary_trees_t
 * @node_2: second pointer node of binary_trees_t
 * @root: pointer to pointer of first node of binary_trees_t
 * Return: 1 on succes otherwise 0
 */
int swap_numbers(heap_t *node_1, heap_t *node_2, heap_t **root)
{
	heap_t *temp_left = NULL, *temp_right = NULL;

	temp_left = node_1->left;
	temp_right = node_1->right;

	if (node_1->left)
		node_1->left->parent = node_2;
	if (node_1->right)
		node_1->right->parent = node_2;
	node_1->parent = node_2->parent;
	if (node_1 == node_2->left)
	{
		node_1->left = node_2;
		node_1->right = node_2->right;
	}
	else
	{
		node_1->right = node_2;
		node_1->left = node_2->left;
	}

	if (node_2->parent)
	{
		if (node_2->parent->left == node_2)
			node_2->parent->left = node_1;
		else
			node_2->parent->right = node_1;
	}
	else
		*root = node_1;

	if (node_2->left && node_2->left != node_1)
		node_2->left->parent = node_1;
	if (node_2->right && node_2->right != node_1)
		node_2->right->parent = node_1;
	node_2->parent = node_1;
	node_2->left = temp_left;
	node_2->right = temp_right;

	return (1);
}

/**
 * sort_max_heap - check if a node can store the new node
 * @new_node: address of the new element
 * @root: pointer to pointer of first node of binary_trees_t
 * Return: 1 on succes otherwise 0
 */
int sort_max_heap(heap_t *new_node, heap_t **root)
{
	heap_t *temp_node = NULL;

	temp_node = new_node;
	while (temp_node->parent && temp_node->n > temp_node->parent->n)
	{
		swap_numbers(temp_node, temp_node->parent, root);
	}

	return (1);
}

/**
 * pow_two - calcule the "n" pow 2
 * @tree_levels: current height of the binary_tree
 * Return: "tree_levels" pow 2
 */
int pow_two(int tree_levels)
{
	int init_num = 0, pow_two_result = 1;

	if (tree_levels == 0)
		return (1);
	for (init_num = 0; init_num < tree_levels; init_num++)
		pow_two_result *= 2;
	return (pow_two_result);
}

/**
 * check_node - check if a node can store the new node
 * @root: pointer to pointer of first node of binary_trees_t
 * @new_node: address of the new element
 * @tree_levels: current height of the binary_tree
 * Return: 1 on succes otherwise 0
 */
int check_node(heap_t **root, heap_t *new_node, int tree_levels)
{
	heap_t *relative_root = NULL;
	int index = 0, num_nodes = 1, deep_num = 0;
	float levels = 0, one_node = 0;

	num_nodes = pow_two(tree_levels);
	for (index = 0; index < num_nodes; index++)
	{
		relative_root = *root;
		deep_num = 0;
		while (deep_num < tree_levels)
		{
			one_node = pow_two(tree_levels) / (index + 1);
			levels = (pow_two(tree_levels) /
				pow_two(tree_levels - 1 - deep_num));
			if (one_node < levels)
				relative_root = relative_root->right;
			else
				relative_root = relative_root->left;
			deep_num++;
		}
		if (!(relative_root->left))
			relative_root->left = new_node;
		else if (!(relative_root->right))
			relative_root->right = new_node;
		else
			continue;
		new_node->parent = relative_root;
		sort_max_heap(new_node, root);
		return (1);
	}

	return (0);
}

/**
 * heap_insert - insert a node in binary tree using max heap
 * @root: pointer to pointer of first node of binary_trees_t
 * @value: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int tree_levels = 0;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}

	while (!check_node(root, new_node, tree_levels))
	{
		tree_levels++;
	}

	return (new_node);
}
