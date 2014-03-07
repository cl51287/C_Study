#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 1

#define LEFT_NODE 0
#define RIGHT_NODE 1

typedef struct _tree_node {
	int num;
	struct _tree_node *left;
	struct _tree_node *right;
	struct _tree_node *parent;
	int height;
} TreeNode;

typedef struct _tree {
	TreeNode *head;
	TreeNode *sentry;
} Tree;

#include "print_tree.c"

void _single_rotate(TreeNode *c_root, int lorr)
{
	TreeNode *p_node, *c_node;

	p_node	= c_root->parent;
	c_node	= lorr ? c_root->right : c_root->left;
	// 0 left rotate, 1 right rotate
	if (!lorr) {
		if (c_node->right) {
			c_root->left	= c_node->right;
			c_node->right->parent	= c_root;	
		} else {
			c_root->left	= NULL;
		}
		c_node->right	= c_root;
	} else {
		if (c_node->left) {
			c_root->right	= c_node->left;
			c_node->left->parent	= c_root;
		} else {
			c_root->right	= NULL;
		}
		c_node->left	= c_root;
	}
	c_root->parent	= c_node;

	c_node->parent	= p_node;
	if (p_node->right == c_root) {
		p_node->right	= c_node;
	} else {
		p_node->left	= c_node;
	}
}

void _double_rotate(TreeNode *c_root, int lorr)
{
	// 0 left rotate, 1 right rotate
	if (!lorr) {
		_single_rotate(c_root->left, 1);
		_single_rotate(c_root, 0);
	} else {
		_single_rotate(c_root->right, 0);
		_single_rotate(c_root, 1);
	}
}

void _insert(TreeNode *tree_node, int num)
{
	if (num > tree_node->num) {
		if (tree_node->right) {
			_insert(tree_node->right, num);
		} else {
			TreeNode *new_node;
			new_node	= (TreeNode *)malloc(sizeof(TreeNode));
			new_node->num	= num;
			new_node->height	= 0;
			new_node->parent	= tree_node;
			tree_node->right	= new_node;
		}
	} else if (num < tree_node->num) {
		if (tree_node->left) {
			_insert(tree_node->left, num);
		} else {
			TreeNode *new_node;
			new_node	= (TreeNode *)malloc(sizeof(TreeNode));
			new_node->num	= num;
			new_node->height	= 0;
			new_node->parent	= tree_node;
			tree_node->left	= new_node;
		}
	} else {
		return ;
	}

	int l_height, r_height;
	l_height	= tree_node->left ? tree_node->left->height : -1;
	r_height	= tree_node->right ? tree_node->right->height : -1;

	if (l_height - r_height > 1) {
		l_height	= tree_node->left->left ? tree_node->left->left->height : -1;
		r_height	= tree_node->left->right ? tree_node->left->right->height : -1;
		if (l_height > r_height) {
			_single_rotate(tree_node, 0);
		} else {
			_double_rotate(tree_node, 0);
		}
	} else if (r_height - l_height > 1) {
		r_height	= tree_node->right->right ? tree_node->right->right->height : -1;
		l_height	= tree_node->right->left ? tree_node->right->left->height : -1;
		if (r_height > l_height) {
			_single_rotate(tree_node, 1);
		} else {
			_double_rotate(tree_node, 1);
		}
	}

	l_height	= tree_node->left ? tree_node->left->height : -1;
	r_height	= tree_node->right ? tree_node->right->height : -1;
	if (l_height > r_height) {
		tree_node->height	= l_height + 1;
	} else {
		tree_node->height	= r_height + 1;
	}
}

void insert(Tree *tree, int num)
{
	TreeNode *sen_r_node;
	sen_r_node	= tree->sentry->right ? tree->sentry->right : tree->sentry;

	tree->head	= sen_r_node;
	_insert(tree->head, num);

	if (sen_r_node != tree->sentry->right) {
		tree->head	= tree->sentry->right;
	}
}

void _delete(TreeNode *tree_node, int num, int lorr)
{
	if (num > tree_node->num) {
		if (tree_node->right) {
			_delete(tree_node->right, num, RIGHT_NODE);
		} else {
		}
	} else if (num < tree_node) {
		if (tree_node->left) {
			_delete(tree_node->left, num, LEFT_NODE);
		}
	} else {
		TreeNode *p_node;
		p_node	= tree_node->parent;
		
		int l_height, r_height;
		l_height	= tree_node->left ? tree_node->left->height : -1;
		r_height	= tree_node->right ? tree_node->right->height : -1;
		if (l_height > r_height) {

		} else if (l_height < r_height) {

		} else {
		}
	}
}

void delete(Tree *tree, int num)
{

}

void find(Tree *tree, int num)
{

}


int main()
{
	Tree *p_tree;
	int i;
	
	p_tree	= (Tree *)malloc(sizeof(Tree));

	TreeNode *sentry;
	p_tree->sentry	= (TreeNode *) malloc(sizeof(TreeNode));
	p_tree->sentry->num	= 0;

	for (i = 0; i < 50; i++) {
		insert(p_tree, rand() % (MAX - MIN + 1) + MIN);
	}
	print_tree(p_tree);
}
