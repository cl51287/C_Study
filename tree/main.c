#include<stdio.h>
#include<stdlib.h>
#include "../inout.h"
#include<string.h>


struct _tabs {
	int len;
	char **str;
} *tabs;

typedef struct _tree_node {
	struct _tree_node *left_node;
	struct _tree_node *right_node;
	int num;
} TreeNode;

typedef struct _tree {
	int size;
	TreeNode *head_node;
} Tree;

void print_tree(Tree *tree);	

void add_tree(Tree *tree, int num)
{
	TreeNode *p_cur	= tree->head_node, **pp_cur	= &tree->head_node;

	while (p_cur != NULL) {
		if (num < p_cur->num) {
			pp_cur	= &p_cur->left_node;
			p_cur	= p_cur->left_node;
		} else if (num > p_cur->num) {
			pp_cur	= &p_cur->right_node;
			p_cur	= p_cur->right_node;
		} else {
			return ;
		}
	}

	p_cur	= (TreeNode *) malloc(sizeof(TreeNode *));
	p_cur->num	= num;
	*pp_cur	= p_cur;
	tree->size++;
}

void find_tree(Tree *tree, int num, int a[3])
{
	TreeNode *p_cur = tree->head_node;
	if (p_cur == NULL) { 
		a[0]	= 0;
	}
	
	while (num != p_cur->num) {
		a[0]	= p_cur->num;
		if (p_cur->num > num) {
			p_cur	= p_cur->left_node;
		} else {
			p_cur	= p_cur->right_node;
		}

		if (p_cur == NULL) {
			a[0]	= -1;
			return ;
		}
	}
	a[1]	= p_cur->left_node == NULL ? 0 : p_cur->left_node->num;
	a[2]	= p_cur->right_node == NULL ? 0 : p_cur->right_node->num;
	return ;
}

TreeNode * _delete_treenode(TreeNode *tree_node, int num)
{
	if (tree_node->num == num) {
		if (tree_node->left_node == NULL && tree_node->right_node == NULL) {
			free(tree_node);
			return NULL;
		} else {
			if (tree_node->left_node && tree_node->right_node) {
				if (num % 2) {
					tree_node->num	= tree_node->left_node->num;
					tree_node->left_node	= _delete_treenode(tree_node->left_node, tree_node->left_node->num);
				} else {
					tree_node->num	= tree_node->right_node->num;
					tree_node->right_node	= _delete_treenode(tree_node->right_node, tree_node->right_node->num);
				}
				return tree_node;
			} else {
				TreeNode *p;
				if (tree_node->left_node) {
					p	= tree_node->left_node;
				} else {
					p	= tree_node->right_node;
				}
				free(tree_node);
				return p;
			}
		}
		
	} else if (tree_node->num < num) {
		tree_node->right_node	= _delete_treenode(tree_node->right_node, num);
		return tree_node;
	} else {
		tree_node->left_node	= _delete_treenode(tree_node->left_node, num);
		return tree_node;
	}
}

void delete_tree(Tree *tree, int num)
{
	if (tree->head_node == NULL) {
		return ;
	}

	tree->head_node	= _delete_treenode(tree->head_node, num);
}

int main()
{

	int num;
	char op;
	Tree *tree;

	tree	= malloc(sizeof (Tree *));

	add_tree(tree, 60);

	TreeNode *cur, *new1, *new2;
	cur	= tree->head_node;
	new1	= (TreeNode *) malloc(sizeof(TreeNode *));
	new1->num	= 70;
	new2	= (TreeNode *) malloc(sizeof(TreeNode *));
	new2->num	= 50;
//	cur->right_node	= new1;
//	cur->left_node	= new2;
//	add_tree(tree, 70);
//	add_tree(tree, 50);
	print_tree(tree);

	free(new1);
	free(new2);
//	free(tree->head_node->left_node);
//	free(tree->head_node->right_node);
//	delete_tree(tree, 70);
//	delete_tree(tree, 50);
//	print_tree(tree);

	new1	= (TreeNode *) malloc(sizeof(TreeNode *));
	if (new1->left_node) {
		printf("qqq--");
	}
//	add_tree(tree, 70);
//	print_tree(tree);

	while (1) {	
		printf("please input action:\n");
		scanf("%c", &op);
		FLUSH_STDIN;		

		if (op == 'a') {
			while (1) {
				printf("please input to add num:\n");
				scanf("%d", &num);
				FLUSH_STDIN;
				
				if (num == 0) {
					break;
				}
		
				add_tree(tree, num);
		
				print_tree(tree);
			}
		} else if (op == 'f') {
			while (1) {
				printf("please input to find num:\n");
				scanf("%d", &num);
				FLUSH_STDIN;

				if (num == 0) {
					break;
				}

				int a[3];
				find_tree(tree, num, a);
				if (a[0] == -1) {
					printf("can not find %d\n", num);
				} else  {
					printf("find %d, it's parent num is %d, left num is %d, right num is %d.\n", num, a[0], a[1], a[2]);
				}
			}
		} else if (op == 'd') {
			while (1) {
				printf("please input to delete num:\n");
				scanf("%d", &num);
				FLUSH_STDIN;

				if (num == 0) {
					break;
				}

				delete_tree(tree, num);
				print_tree(tree);
			}
		} else if (op == 's') {
			print_tree(tree);
		} else {
			return ;
		}
	}
}

void print_tree(Tree *tree)
{
	void _print_treenode(TreeNode *tree_node, int tabnum);
	_print_treenode(tree->head_node, 0);
}

void _print_treenode(TreeNode *tree_node, int tabnum)
{
	char *_dup_tab(int num);

	if (tree_node) {
		if (tree_node->right_node) {
			_print_treenode(tree_node->right_node, tabnum + 1);
		}
		printf("%s%d,%x\n", _dup_tab(tabnum), tree_node->num, tree_node);
		if (tree_node->left_node) {
			_print_treenode(tree_node->left_node, tabnum + 1);
		}
	}
}

char *_dup_tab(int num)
{
	if (tabs == NULL) {
		tabs	= malloc(sizeof(struct _tabs *));
		tabs->len	= 8;
		tabs->str	= (char **) malloc(sizeof(char *) * 8);
		*tabs->str	= "\0";
	}

	if (tabs->len < num - 1) {
		char **str;
		str	= (char **) malloc(sizeof(char *) * tabs->len * 2);
		memcpy(str, tabs->str, tabs->len * 2);
		tabs->len	= tabs->len * 2;
	}

	if (*(tabs->str + num)) {
		return *(tabs->str + num);
	} else {
		if (num > 0) {
			*(tabs->str + num)	= malloc(sizeof(char) * num + 1);
			int i = 0;
			for (i = 0; i < num; i++) {
				*(*(tabs->str + num) + i)	= '\t';
			}
			*(*(tabs->str + num) + num)	= '\0';
			return *(tabs->str + num);
		} else {
			return *(tabs->str);
		}
	}
}
