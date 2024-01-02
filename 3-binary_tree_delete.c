#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * If tree is NULL, do nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return; /*Do nothing if the tree is NULL*/
	}

	binary_tree_delete(tree->left); /*Recursively delete left subtree*/
	binary_tree_delete(tree->right); /*Recursively delete right subtree*/

	free(tree); /*Free the current node*/
}
