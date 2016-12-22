#include<stdio.h>
#include"stack.h"

#define N_VALUE 10
int
main(void)
{
	int a[N_VALUE]={1,2,3,4,5,6,7,8,9,10};	
	int * p;
	int i;
	for(p = &a[0];p<&a[N_VALUE];)
		push(*p++);

	for(i = 0;i < N_VALUE;i++)
	{
	       	printf("%d ",top());
		pop();
	}

	printf("\n");
	
	return 0;
}
