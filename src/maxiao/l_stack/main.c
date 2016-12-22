#include"stack.h"
#include<stdio.h>

#define N_VALUE	8

int
main(void)
{
	int count;
	int i;
	int * p;
	int a[N_VALUE] = {1,2,3,4,5,6,7,8};

	for(p = &a[0];p < &a[N_VALUE];)
	{
		push(*p++);
		count++;
	}

	for(i = 0;i < count; i++)
	{
		printf("%d ",top());
		pop();
	}
	printf("\n");

	destroy_stack();
}
