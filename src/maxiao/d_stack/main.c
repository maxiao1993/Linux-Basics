#include"stack.h"
#include<stdio.h>

#define N_VALUE 10
int
main(void)
{	
	int i;
	int n;
        int a[N_VALUE] = {1,2,3,4,5,6,7,8,9,10};
	int * p;

	printf("Please input a number bigger than 10: ");
	scanf("%d",&n);
	create_stack(n);

	for(p = &a[0];p < &a[N_VALUE];)
		push(*p++);

	for(i = 0;i < N_VALUE;i++)
	{
		printf("%d ",top());
		pop();
	}
	printf("\n");
	
	destroy_stack();
	return 0;
}
