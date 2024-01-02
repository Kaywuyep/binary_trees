#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
	{
		/*Cannot insert left child to a NULL parent*/
		return (NULL);
	}
	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
	{
		return (NULL);/*memory allocation failed*/
	}
	newNode->left = parent->left;
	if (newNode->left != NULL)
	{
		newNode->left->parent = newNode;
	}
	parent->left = newNode;
	return (newNode);
}
