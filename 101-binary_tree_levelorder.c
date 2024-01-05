#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 * the binary tree
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left_height);
	right_height = binary_tree_height(tree->right_height);
	if (left_height >= right_height)
	{
		return (1 + left_height);
	}
	return (1 + right_height);
}

/**
 * binary_tree_level - perform a function on a
 * specific level of a binary tree
 * @tree: pointer to the root of the tree
 * @l: level of the tree to perform a function on
 * @func: function to perform
 *
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;/*if tree is null, do nothing*/
	if (l == 1)
	{
		/*If curr level is 1, perform d func on the curr node's value*/
		func(tree->n);
	}

	else if (l > 1)
	{/*call func of left znd right subtrees with decremented levels*/
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, j;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (j = 1; j <= height; j++)
		binary_tree_level(tree, j, func);
}
