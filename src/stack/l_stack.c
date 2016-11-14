#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define true 1
#define false 0

typedef int datatype;

typedef struct singly
{
	datatype  node;
	struct singly *pnext;
}Node, *pNode;

typedef struct stack
{
	pNode TOP;
	pNode BOT;

}Stack,*pStack;


void Init_stack(pStack ps)
{
	ps -> TOP = (pNode)malloc(sizeof(Node));

	if (NULL == ps->TOP)
	{
		printf("失败\n");
	}
	else
	{
		ps -> BOT = ps -> TOP;
		ps -> TOP -> pnext = NULL;
	}
	return;
}

int Push_stack(pStack ps, int data)
{
	pNode pnew = (pNode)malloc(sizeof(Node));

	if (NULL == pnew)
	{
		return -1;
	}

	pnew -> node = data;
    pnew -> pnext = ps ->TOP;
	ps -> TOP = pnew;
}

void Empty_stack(pStack ps)
{
	if (ps -> TOP == ps ->BOT)
	{
		printf("yes!\n");
	}
	else
	{
		printf("no!\n");
	}
}


int Pop_stack(pStack ps)
{
	pNode pPOP = NULL;
	int r_val;
	if (ps -> TOP == ps -> BOT)
	{
		printf("is empty!\n");
	}
	else
	{
		r_val = ps ->TOP -> node;
		pPOP = ps -> TOP;
		ps -> TOP = ps -> TOP -> pnext;
		free(pPOP);
		return r_val;
	}
}

void Print_stack(pStack ps)
{
	pNode pnew = ps -> TOP;

	while (pnew != ps -> BOT)
	{
		printf("%d",pnew->node);
		pnew = pnew->pnext;
	}
	return;
}

void Clear_stack(pStack ps)
{
	pNode pnew = NULL;
	while (ps ->TOP != ps -> BOT)
	{
		pnew = ps ->TOP;
		ps -> TOP = ps -> TOP ->pnext;
		free(pnew);
	}
	return;
}
void main(void)
{
	Stack s;
	int i,r,n,m,d;
        Init_stack(&s);
	do
	{
		printf("1:input,2:pop,3:empty,4:print,5:clean:\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1 :
				printf("输入的个数:");
				scanf("%d",&m);

				for (i=0;i<m;i++)
				{
					printf("第%d个数：",i+1);
					scanf("%d",&d);
					
					if(Push_stack(&s,d))
					{
						continue;
					}
					else
					{
						printf("失败\n");
					}
				}
				break;
			case 2 :
				Print_stack(&s);
			        printf("去掉几个：");
				scanf("%d",&d);
				printf("去掉数字为：");
				for(i=0;i<d;i++)
				{
					r  = Pop_stack(&s);
					printf("%d",r);
				}
				break;	
			case 3:
				Empty_stack(&s);
	 			break; 
			case 4:
				Print_stack(&s);
				break;
			case 5:
				Clear_stack(&s);
				break;
			default:
				printf("请重新：\n");
				break;
		}
	}while(n != 0);
	
	return;
}
