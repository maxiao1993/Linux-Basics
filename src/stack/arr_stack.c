#include<stdio.h>
#include<malloc.h>

static int *arr;
static int count;

//创栈
int Create_stack()
{
	int n;
	printf("please input value of stack member:\n");
	scanf("%d",&n);

	arr = (int *)malloc(n*sizeof(int));

	if(!arr)
	{
		printf("create error\n");
		return -1;
	}

	return 0;
}

//删除
int d_stack()
{
	if(arr)
	{
		free(arr);
		arr = NULL;
	}
	return 0;
}

//压栈
void Push_stack(int val)
{
	arr[count++] = val;
}

//元素个数
int Size_stack(){
	return count;
}

//栈顶元素
int Peek_stack()
{
	if(arr){

		return arr[count -1];
	}
	else 
		return -1;
}

//弹栈
int Pop_stack()
{
	if(Size_stack()){

		int ret = arr[count-1];
		count--;
	}
	else
		return -1;
}

//打印栈
void Printf_stack()
{
	if(count == 0)
	{
		printf("is empty\n");
		return;
	}

	int i=count - 1;

	while(i>=0)
	{

		printf("%d",arr[i]);
		i--;

	}
}

void main(void)
{
	  while (1)
	  {
		  int n,m;
		  printf("1:c,2:push,3:peek,4:pop,5:size,6:print,7:d\n");
		  scanf("%d",&n);
		 
		  switch(n)
		  {
			  case 1 :
					Create_stack();
				 	break;
			  case 2 :
					printf("pl\n");
					scanf("%d",&m);
					Push_stack(m);
				 	break;
			  case 3 :
					printf("%d\n",Peek_stack());
				 	break; 
			  case 4 :
					Pop_stack();
				 	break;
			  case 5 :
					printf("%d\n",Size_stack());
					break;
			  case 6 :
					Printf_stack();
					break;
			  case 7 :
					goto out;
		  }
	  }

	out :
	  d_stack();

	return;
}
