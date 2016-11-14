#include<stdio.h>
#include<malloc.h>

static int * arr ;
static int count;

void Create_queue()
{
	int si;

	printf("size:\n");
	scanf("%d",&si);
    
	arr = (int *)malloc(si*sizeof(int));

	if (!arr)
	{
		printf("is error:\n");
	}
	count = 0;

}

int D_queue()
{
	if(arr)
	{
		free(arr);
		arr = NULL;
	}
	return 0;
}

void Add_queue(int val)
{
	arr[count++]=val;
}

int f_queue()
{
	return arr[0];
}

int Pop_queue()
{
	int i =0;
	int ret = arr[0];

	count--;
	while(i++<count)
		arr[i-1]=arr[i];

	return ret;
}

int Empety_queue()
{
	return count == 0;
}

void main(void)
{
	int i,val;

	do
	{
		printf("1:create,2:add,3pop,4:d\n");
		scanf("%d",&i);

		switch(i)
		{
			case 1:
				Create_queue();
				break;
			case 2:
				printf("val:\n");
				scanf("%d",&val);
				Add_queue(val);
				break;
			case 3:
				printf("is %d",Pop_queue());
				break;
			case 4:
				D_queue();
				break;

		}
	}while(i != 0);
	
	return ;
}
