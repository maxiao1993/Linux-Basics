#include<stdio.h>
#include <stdlib.h>

//栈的初始化
void Init_stack(pStack ps)
{
	ps->pTop = (pNode)malloc(sizeof(Node));
   if(NULL == ps->pTop )	
   {
	   ptintf("内存分配失败\n");
	   exit(-1);
   }
   else 
   {
	   ps->pBot = ps->pTop;
	   ps->pTop->pNext = NULL;
   }
   return ;

}


int Push_stack(pStack ps,int val)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL = pNext)
	{
		return 0;
	}
	else
	{

	}
}

