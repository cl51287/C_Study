#include <stdio.h>

int main()
{
	char s[]	= "abc";
	char *ps	= "abc";


	printf("s is %p\n", s);
	printf("ps is %p\n", ps);

	ps	= s;
	//s	= ps;
}
