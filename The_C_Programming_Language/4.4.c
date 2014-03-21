#include <stdio.h>


int main()
{
	extern a;
	a	= 10;
	pa();
}

int pa()
{
	extern a;
	printf("a is %d\n", a);
}

int a;
