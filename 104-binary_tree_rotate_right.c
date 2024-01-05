#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newRoot, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	newRoot = tree->left;
	tmp = newRoot->right;
	newRoot->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = newRoot;
	newRoot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = newRoot;
		else
			tmp->right = newRoot;
	}

	return (newRoot);
}
