#include "binary_trees.h"

/**
* is_bts - check if a given tree is a bst
* @tree: head node of a tree
* Return: 1 is tree is bst or 0 otherwise
*/
int is_bts(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n < tree->n)
		return (0);

	if (is_bts(tree->left) == 0 || is_bts(tree->right) == 0)
		return (0);

	return (1);
}

/**
* _abs - get the absolute value of a given number
* @x: value to get the absolute value
* Return: the absolute value of a given number
*/
int _abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

/**
* diff_max_1_height - check if a given tree is differ at most 1 each subtree
* @tree: head node of a tree
* Return: the height + 1 of a given tree or 0 if the height of a subtree
* differ more than 1
*/
int diff_max_1_height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
		return (1);

	l = diff_max_1_height(tree->left);
	if (l == 0)
		return (0);

	r = diff_max_1_height(tree->right);
	if (r == 0)
		return (0);

	if (_abs(l - r) > 1)
		return (0);

	if (l > r)
		return (1 + l);
	return (1 + r);
}

/**
* binary_tree_is_avl - check if a given tree is a valid AVL tree
* @tree: head node of a tree
* Return: 1 if a given tree is a valid AVL, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_bts(tree) == 0)
		return (0);

	if (diff_max_1_height(tree) == 0)
		return (0);

	return (1);
}
