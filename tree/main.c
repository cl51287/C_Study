#include<stdio.h>

typedef struct _tree_node {
	TreeNode *left_node;
	TreeNode *right_node;
	int num;
} TreeNode;

typedef struct _tree {
	int size;
	TreeNode *head_node;
} Tree;

void add_tree(TreeNode *tree, int num)
{
	TreeNode *p_cur	= tree->head_node, **pp_cur	= &tree->head_node;

	while (p_cur != NULL) {
		if (num < p_cur->num) {
			pp_cur	= &p_cur->left;
			p_cur	= p_cur->left;
		} else if (num > p_cur->num) {
			pp_cur	= &p_cur->right;
			p_cur	= p_cur->right;
		} else {
			return ;
		}
	}

	p_cur	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_cur->num	= num;
	*pp_cur	= p_cur;
	tree->size++;
}

int main()
{
	int num;
	Tree *tree;

	tree	= malloc(sizeof (Tree *));
	
	printf("please input the tree num:\n");
	scanf();
}
