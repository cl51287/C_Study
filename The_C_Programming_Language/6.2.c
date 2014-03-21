#include <stdio.h>
struct point {
	int x;
	int y;
};

int main()
{
	struct point a1, a2;

	int showpoint(struct point *);
	
	a1.x	= 1;
	a1.y	= 2;

	printf("a1.x is %d, a1.y is %d\n", a1.x, a1.y);

	showpoint(&a1);
	printf("a1.x is %d, a1.y is %d\n", a1.x, a1.y);
}

int showpoint (struct point *a1)
{
	a1->x	= 5;
	a1->y	= 6;
}
