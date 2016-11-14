#include<stdio.h>  
#include<malloc.h>        //包含了malloc函数  
/* 
 *循环队列，用数组实现 
 */  
//队列结构体定义  
typedef struct Queue  
{  
    int * pBase;    //用于动态分配内存,pBase保存数组的首地址  
    int front;      //指向头结点  
    int rear;       //指向最后一个元素的下一结点  
} QUEUE;  
//函数声明  
void initQueue(QUEUE * pQueue);                 //队列初始化的函数  
bool isEmpty(QUEUE * pQueue);                   //判断队列是否为空的函数  
bool isFull(QUEUE * pQueue);                    //判断队列是否满的函数  
bool enQueue(QUEUE * pQueue, int value);        //入队的函数   
bool outQueue(QUEUE * pQueue, int * pValue);    //出队的函数,同时保存出队的元素  
void traverseQueue(QUEUE * pQueue);             //遍历队列的函数  
/* 
 *主程序 
 */  
int main(void)  
{  
    int value;          //用于保存出队的元素  
    //创建队列对象  
    QUEUE queue;  
    //调用初始化队列的函数  
    initQueue(&queue);  
    //调用出队函数  
    enQueue(&queue, 1);  
    enQueue(&queue, 2);  
    enQueue(&queue, 3);  
    enQueue(&queue, 4);  
    enQueue(&queue, 5);  
    enQueue(&queue, 6);  
    enQueue(&queue, 7);  
    enQueue(&queue, 8);  
    //调用遍历队列的函数  
    traverseQueue(&queue);  
    //调用出队函数  
    if(outQueue(&queue, &value))  
    {  
        printf("出队一次，元素为：%d\n", value);  
    }  
    traverseQueue(&queue);  
    if(outQueue(&queue, &value))  
    {  
        printf("出队一次，元素为：%d\n", value);  
    }  
    traverseQueue(&queue);  
    getchar();  
    return 0;  
}  
/* 
 *初始化函数的实现 
 */  
void initQueue(QUEUE * pQueue)  
{  
    //分配内存  
    pQueue->pBase = (int *)malloc(sizeof(int) * 6);          //分配6个int型所占的空间  
    pQueue->front = 0;       //初始化时，front和rear值均为0  
    pQueue->rear = 0;  
    return;  
}  
/* 
 *入队函数的实现 
 */  
bool enQueue(QUEUE * pQueue, int value)  
{  
    if(isFull(pQueue))  
    {  
        printf("队列已满,不能再插入元素了!\n");  
        return false;  
    }  
    else  
    {  
        //向队列中添加新元素  
        pQueue->pBase[pQueue->rear] = value;  
        //将rear赋予新的合适的值  
        pQueue->rear = (pQueue->rear+1) % 6;  
        return true;  
    }  
}  
/* 
 *出队函数的实现 
 */  
bool outQueue(QUEUE * pQueue, int * pValue)  
{  
    //如果队列为空,则返回false  
    if(isEmpty(pQueue))  
    {  
        printf("队列为空，出队失败!\n");  
        return false;  
    }  
    else  
    {  
        *pValue = pQueue->pBase[pQueue->front];       //先进先出  
        pQueue->front = (pQueue->front+1) % 6;      //移到下一位置  
        return true;  
    }  
}  
/* 
 *遍历队列的函数实现 
 */  
void traverseQueue(QUEUE * pQueue)  
{  
    int i = pQueue->front;           //从头开始遍历  
    printf("遍历队列：\n");  
    while(i != pQueue->rear)     //如果没有到达rear位置，就循环  
    {  
        printf("%d  ", pQueue->pBase[i]);  
        i = (i+1) % 6;              //移到下一位置  
    }     
    printf("\n");  
    return;  
}  
/* 
 *判断队列是否满的函数的实现 
 */  
bool isFull(QUEUE * pQueue)  
{  
    if((pQueue->rear+1) % 6 == pQueue->front)     //队列满  
        return true;  
    else  
        return false;  
}  
/* 
 *判断队列是否为空函数的实现 
 */  
bool isEmpty(QUEUE * pQueue)  
{  
    if(pQueue->front == pQueue->rear)  
        return true;  
    else  
        return false;  
}
