#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tree_node {
	struct _tree_node *left;
	struct _tree_node *right;
	int num;
} TreeNode;

int main()
{
	TreeNode *new1, *new2, *new3;
	TreeNode node1, node2, node3;

/*
	int *pi;
	pi	= malloc(sizeof(int *));
*/
	new1    = (TreeNode *) malloc(sizeof(TreeNode));
//	new1->num   = 70;
	new2    = (TreeNode *) malloc(sizeof(TreeNode));
//	new2->num   = 50;
/*	
	p_tree_node	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_tree_node->num	= 50;
	p_tree_node2	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_tree_node2->num	= 70;
	printf("pi is %p, new1 is %p, new1 left addr is %p, new1 num addr is %p, new2 is %p\n", pi, new1, &new1->left, &new1->num, new2);

	printf("int size is %d, tree_node size is %d, tree_node pointer size is %d\n", sizeof(int), sizeof(TreeNode), sizeof(TreeNode *));
	printf("new2 left addr is %p, new2 left is %p\n", &new2->left, new2->left);

	new1->left	= NULL;
	new1->right	= NULL;
	new1->num	= 0;
*/
/*
	new2->left	= NULL;
	new2->right	= NULL;
	new2->num	= 0;

	printf("new2 is %p, new2 value is %p\n", new2, *new2);
*/
printf("new2 pointer is %p, new2 point value is %p\n", new2, *new2);
	free(new2);
printf("new2 pointer is %p, new2 point value is %p\n", new2, *new2);

printf("new1 pointer is %p, new1 point value is %p\n", new1, *new1);
	free(new1);
printf("new1 pointer is %p, new1 point value is %p\n", new1, *new1);

	new3	= (TreeNode *) malloc(sizeof(TreeNode)); 
	printf("new3 pointer is %p, new3 left value is %p\n", new3, new3->left);
/*
	printf("new2 is %p, new2 value is %p\n", new2, *new2);
*/
/*
	new3	= (TreeNode *) malloc(sizeof(TreeNode));
	memset(new3, 0, sizeof(TreeNode));
	printf("new3 is %p, left addr is %p, left is %p\n", new3, &new3->left, new3->left);
*/
}
