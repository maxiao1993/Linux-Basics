#include"queue.h"
#include<stdio.h>
#include"queue.h"
#define N_VALUE 5

int
main(void)
{
	int a[N_VALUE] = {1,2,3,4,5};
	int * p;
	int i;

	for(p = &a[0];p < &a[N_VALUE];)
	{
		insert(*p++);
	}
	
	for(i = 0;i<5;i++)
	{
		printf("%d ",first());
		delete();
	}

	printf("\n");

	return 0;
}
