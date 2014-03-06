#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inout.h"
//printf("%d ", *(stk->arr + i));	
typedef struct _stack {
	int *arr;
	int topnum;
	int size;
} stack;

void resize_stack(stack *stk, int size)
{
	int *p_arr;
	p_arr	= malloc(sizeof(int) * size);
	memcpy(p_arr, stk->arr, sizeof(int) * stk->size);
	stk->size	= size;
	stk->arr	= p_arr;
}

void push_stack(stack *stk, int num)
{
	if (stk->topnum == stk->size) {
		resize_stack(stk, stk->size * 2);
	}
	*(stk->arr + stk->topnum)	= num;
	stk->topnum++;
}

int top_stack(stack *stk)
{
	int num;
	if (stk->topnum == 0) {
		return 0;
	}
	if (stk->topnum <= stk->size / 4) {
		resize_stack(stk, stk->size / 2);
	}
	num	= *(stk->arr + stk->topnum - 1);
	stk->topnum--;

	return num;
}

void init_stack(stack *stk)
{
	stk->size	= 8;
	stk->arr	= (int *)malloc(sizeof(int) * stk->size);
	stk->topnum	= 0;
}

int main()
{
	stack *stk;
	int num;
	char op;

	stk = (stack *)malloc(sizeof(stack));
	init_stack(stk);

	while (1) {
		printf("please input option:\n");
		scanf("%c", &op);
		FLUSH_STDIN;
		if (op == 'p') {
			printf("please input will push num:\n");
			scanf("%d", &num);
			FLUSH_STDIN;
			push_stack(stk, num);

			PRINT_ARR(stk->arr, stk->topnum);
			printf("stk size is %d, topnum is %d\n", stk->size, stk->topnum);
		} else if (op == 't') {
			num	= top_stack(stk);
			printf("top stack num is %d\n", num);
			
			PRINT_ARR(stk->arr, stk->topnum);
			printf("stk size is %d, topnum is %d\n", stk->size, stk->topnum);
		} else {
			printf("exit program.\n");
			
			PRINT_ARR(stk->arr, stk->topnum);
			break;
		}
	}
}
