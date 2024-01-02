#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 * If parent already has a right-child, the new node takes its place, and the
 * old right-child becomes the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightChild;

	if (parent == NULL)
	{
		/*Cannot insert right child to a NULL parent*/
		return (NULL);
	}
	rightChild = binary_tree_node(parent, value);
	if (rightChild == NULL)
		return (NULL);/*memory allocation failed*/
	rightChild->right = parent->right;
	if (rightChild->right != NULL)
	{
		/*Set the parent of the old right-child to the new node*/
		rightChild->right->parent = rightChild;
	}
	/*Set the new node as the right-child of the parent*/
	parent->right = rightChild;
	return (rightChild);
}
