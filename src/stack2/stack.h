#define STACK_H

//定义结点
typedef struct Node{
	int date;
	struct Node *pNext;

}Node, *pNode;

typedef struct Stack{
	pNode pTop;
	pNode pBot;

}Stack, *pStack;



