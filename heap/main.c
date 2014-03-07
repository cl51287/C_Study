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
	h->len	= 0;
}

void add_heap(Heap *h, int num)
{
	int cur;
	int p;

	cur	= h->len;
	do {
		if (cur == 0) {
			break;
		}

		p	= HEAP_PARENT_NUM(cur);
		if (num > *(h->arr + p)) {
			*(h->arr + cur)	= *(h->arr + p);
			cur	= p;
		} else {
			break;
		}
	} while (1);
	
	*(h->arr + cur)	= num;
	h->len++;
}

int find_max_heap(Heap *h)
{
	return *(h->arr);
}

void delete_max_heap(Heap *h)
{
	int cur	= 0, max;
	
	do {
		if (*(h->arr + HEAP_RIGHT_NUM(cur)) > *(h->arr + HEAP_LEFT_NUM(cur))) {
			*(h->arr + cur)	= *(h->arr + HEAP_RIGHT_NUM(cur));
			if (HEAP_RIGHT_NUM(cur) >= h->len) {
				break;
			}
			cur	= HEAP_RIGHT_NUM(cur);
		} else {
			*(h->arr + cur)	= *(h->arr + HEAP_LEFT_NUM(cur));
			if (HEAP_LEFT_NUM(cur) >= h->len) {
				break;
			}
			cur	= HEAP_LEFT_NUM(cur);
		}
	} while (1);

	*(h->arr + cur)		= *(h->arr + h->len - 1);
	*(h->arr + h->len - 1)	= 0;
	h->len--;
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
			delete_max_heap(h);
			
			PRT_HEAP(h);
		} else if (op == 'f') {
			printf("the max is %d\n", find_max_heap(h));
		} else {
			printf("exit program.\n");
			
			PRT_HEAP(h);
			break;
		}
	}
}
