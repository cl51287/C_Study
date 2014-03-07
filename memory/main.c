#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_node {
	struct _tree_node *left;
	struct _tree_node *right;
	int num;
} TreeNode;

int main()
{
	TreeNode *new1, *new2, *new3;

	new1    = (TreeNode *) malloc(sizeof(TreeNode *));
	new1->num   = 70;
	new2    = (TreeNode *) malloc(sizeof(TreeNode *));
	new2->num   = 50;

/*	
	p_tree_node	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_tree_node->num	= 50;
	p_tree_node2	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_tree_node2->num	= 70;
*/
	printf("new1 is %x, new2 is %x\n", new1, new2);

	printf("int size is %d, tree_node size is %d, tree_node pointer size is %d\n", sizeof(int), sizeof(TreeNode), sizeof(TreeNode *));
	printf("new1 first is %x\n", (*new1).left);

	new1->left	= NULL;
	new1->right	= NULL;
	new1->num	= 0;
	free(new1);
	new2->left	= NULL;
	new2->right	= NULL;
	new2->num	= 0;
	free(new2);

	new3	= (TreeNode *) malloc(sizeof(TreeNode *));
	printf("p_tree_node is %x, left is %x\n", new3, new3->left);
}
