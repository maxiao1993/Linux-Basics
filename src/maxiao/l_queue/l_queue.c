#include"queue.h"

Status InitQueue(LinkQueue &Q)
{

	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(OVERFLOW);
	Q.front -> next = NULL;
	return OK;
}
Status DestroyQueue(LinkQueue &Q)
{

	while(Q.front)
	{
		Q.rear = Q.front -> next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}


Status EnQueue(LinkQueue &Q,QElemType e)
{
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);

	p -> data = e;
	p -> next = NULL;
	Q.rear -> next = p;
	Q.rear = p;
	return OK;
}
