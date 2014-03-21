#include <stdio.h>

struct {
	unsigned int is_read : 1;
	unsigned int is_write : 1;
	unsigned int is_execute : 1;
} flags;


int main()
{

	printf("flags sizeof is %d\n", sizeof(flags));

	flags.is_read	= 1;
	flags.is_write	= 1;
	flags.is_execute	= 1;
	printf("flags is %d\n", flags);
}
