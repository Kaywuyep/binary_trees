#include "binary_trees.h"

/**
 * countNode - function to count the number of nodes in the tree
 * @root: pointer to the root node of the tree
 * Return: number of nodes
 */
size_t countNode(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);/*if root is null return 0*/
	return (1 + countNode(root->left) + countNode(root->right));
}

/**
 * sub_is_complete - a sub function that checks if a
 * binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @idx: index
 * @nodeCount: number of nodes
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int sub_is_complete(const binary_tree_t *tree, int idx, int nodeCount)
{
	if (tree == NULL)
		return (1);

	if (idx >= nodeCount)
		return (0);

	return (sub_is_complete(tree->left, 2 * idx + 1, nodeCount)
			&& sub_is_complete(tree->right, 2 * idx + 2,
				nodeCount));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count_nodes = countNode(tree);

	if (tree == NULL)
		return (0);
	return (sub_is_complete(tree, 0, count_nodes));
}
