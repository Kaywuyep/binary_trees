#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parnt of the node to create
 * @value: value to store in new node
 * Written by Daniel and Mary
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/*allocate memory for new node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);/*memory allocation failure*/
	}
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}
