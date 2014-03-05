#include<stdio.h>
#include<stdlib.h>

#define PRT_HEAP(h)	\
	{	\
		int i;	\
		for (i = 0; i < h->len; i++) {	\
			printf("%d ", *(h->arr + i));	\
		}	\
		printf("\n");	\
	}	\

#define HEAP_PARENT_NUM(num) ((num - 1) / 2)

#define HEAP_LEFT_NUM(num)	((num) * 2 + 1)

#define HEAP_RIGHT_NUM(num)	((num) * 2 + 2)

#define FLUSH_STDIN \
	{	\
		char c;	\
		while ((c = getchar()) != '\n' && c != EOF);	\
	};	\

typedef struct _heap {
	int *arr;
	int len;
	int size;
} Heap;

void init_heap(Heap *h)
{
	h->size	= 8;
	h->arr	= (int *) malloc(sizeof(int) * h->size);
	h->len	= 1;
}

void add_heap(Heap *h, int num)
{
	int cur;

	cur	= h->len;	
	if (cur > 0) {
		while (1) {
			if (cur == 0) {
				break;
			}

			if (num > *(h->arr + HEAP_PARENT_NUM(cur))) {
				*(h->arr + cur)	= *(h->arr + HEAP_PARENT_NUM(cur));
				cur	= HEAP_PARENT_NUM(cur);
			} else {
				break;
			}
		}
	} else {
		*(h->arr + cur)	= num;
	}
	h->len++;
}

int find_max_heap(Heap *h)
{
	return *(h->arr);
}

void delete_heap(Heap *h, int num)
{
	int cur;
	
	cur		= 0;
	while (1) {
		if (num > *(h->arr + cur)) {
			break;
		} else if (num == *(h->arr + cur)) {
			
		} else {
			
		}
	}	
}

int main()
{
	Heap *h;
	int num;
	char op;

	h	= (Heap *) malloc(sizeof(Heap));

	init_heap(h);

	
	while (1) {
		printf("please input option:\n");
		scanf("%c", &op);
		FLUSH_STDIN;
		if (op == 'a') {
			printf("please input will add num:\n");
			scanf("%d", &num);
			FLUSH_STDIN;
			add_heap(h, num);

			PRT_HEAP(h);
		} else if (op == 'd') {
			printf("please input will delete num:\n");
			scanf("%d", &num);
			FLUSH_STDIN;
			delete_heap(h, num);
			
//			PRT_HEAP(h);
		} else if (op == 'f') {
			printf("the max is %d\n", find_max_heap(h));
		} else {
			printf("exit program.\n");
			
			PRT_HEAP(h);
			break;
		}
	}
}
