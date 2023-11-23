#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_tree - Recursively stores each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer for storing tree representation
 *
 * Return: Length of printed tree after processing
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);

	/* Determine if the current node is the left child */
	is_left = (tree->parent && tree->parent->left == tree);

	/* Format the node value and calculate width */
	width = sprintf(b, "(%03d)", tree->n);

	/* Recursively process left and right subtrees */
	left = print_tree(tree->left, offset, depth + 1, s);
	right = print_tree(tree->right, offset + left + width, depth + 1, s);

	/* Populate the buffer with the formatted node value */
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	/* Draw connecting lines between nodes */
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}

	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree in a formatted style
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	/* Check if the tree is empty */
	if (!tree)
		return;

	/* Calculate the height of the tree */
	height = _height(tree);

	/* Allocate memory for storing the tree representation */
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;

	/* Initialize the buffer with spaces */
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}

	/* Populate the buffer with the tree representation */
	print_tree(tree, 0, 0, s);

	/* Print the formatted tree */
	for (i = 0; i < height + 1; i++)
	{
		/* Remove trailing spaces and print each level of the tree */
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}

	/* Free allocated memory */
	free(s);
}
