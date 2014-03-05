#include <stdio.h>
#include <stdlib.h>
#include <print.h>

#define FLUSH_STDIN \
	{	\
		char c;	\
		while ((c = getchar()) != '\n' && c != EOF);	\
	};	\

//printf("%d ", *(stk->arr + i));	
typedef struct _stack {
	int *arr;
	int topnum;
	int size;
} stack;

void resize_stack(stack *stk, int size)
{
	stk->size	= size;
	stk->arr	= malloc(sizeof(int) * stk->size);
	
}

void push_stack(stack *stk, int num)
{
	*(stk->arr + stk->topnum)	= num;
	stk->topnum++;
}

int top_stack(stack *stk)
{
	int num;
	if (stk->topnum == 0) {
		return 0;
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
		} else if (op == 't') {
			num	= top_stack(stk);
			printf("top stack num is %d\n", num);
			
			PRTINT_ARR(stk->arr, stk->topnum);
		} else {
			printf("exit program.\n");
			
			PRTINT_ARR(stk->arr, stk->topnum);
			break;
		}
	}
}
