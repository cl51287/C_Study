#include<stdio.h>
#include<stdlib.h>
#include "../inout.h"
#include<string.h>

struct _tabs {
	int len;
	char **str;
} *tabs;

void print_tree(Tree *tree)
{
	void _print_treenode(TreeNode *tree_node, int tabnum);
	_print_treenode(tree->head, 0);
}

void _print_treenode(TreeNode *tree_node, int tabnum)
{
	char *_dup_tab(int num);

	if (tree_node) {
		if (tree_node->right) {
			_print_treenode(tree_node->right, tabnum + 1);
		}
#ifdef DEBUG
		int p, l, r;
		p	= tree_node->parent ? tree_node->parent->num : 0;
		l	= tree_node->left ? tree_node->left->num : 0;
		r	= tree_node->right ? tree_node->right->num : 0;
		printf("%s%d,p %d,l %d,r %d,h %d\n", _dup_tab(tabnum), tree_node->num, p, l, r, tree_node->height);
#else
		printf("%s%d\n", _dup_tab(tabnum), tree_node->num);
#endif
		if (tree_node->left) {
			_print_treenode(tree_node->left, tabnum + 1);
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
