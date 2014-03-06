#include<stdio.h>

#define PRINT_ARR(arr, len) \
	{	\
		int i;	\
		for (i = 0; i < len - 1; i++) { \
			printf("%d, ", *(arr + i));	\
		}	\
		printf("%d\n", *(arr + len - 1)); \
	}	\

#define FLUSH_STDIN \
	{	\
		char c;	\
		while ((c = getchar()) != '\n' && c != EOF);	\
	};	\

