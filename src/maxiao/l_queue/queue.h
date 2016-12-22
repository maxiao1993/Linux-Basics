#include"ywm.h"

#define QElemType int

typedef struct QNode
{
	QElemType	data;
	struct QNode	*next;
}QNode, * QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue(LinkQueue $Q);

Status DestroyQueue(LinkQueue &Q);

Status ClearQueue(LinkQueue &Q);

Status QueueEmpty(LinkQueue &Q);

int Queuelength(LinkQueue Q);

Status GetHead(LinkQueue Q,QElemType &e);

Status EnQueue(LinkQueue &Q,QElemType e);

Status DeQueue(LinkQueue &Q,QElemType &e);

Status QueueTraverse(LinkQueue Q,visit());
