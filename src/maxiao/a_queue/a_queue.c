/*
 *
 */
#include"queue.h"
#include<stdio.h>
#include<assert.h>

#define	QUEUE_SIZE	5			/**/
#define ARRAY_SIZE	(QUEUE_SIZE + 1)	/**/

/*
 *
 */
static	QUEUE_TYPE	queue[ARRAY_SIZE];
static	unsigned int	front = 1;
static	unsigned int	rear = 0;

/*
 *	insert
 */
void
insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear = (rear + 1) % ARRAY_SIZE;
	queue[rear] = value;
}

/*
 *	delete
 */
void
delete(void)
{
	assert(!is_empty());
	front = (front + 1) % ARRAY_SIZE;
}

/*
 *	first
 */
QUEUE_TYPE first(void)
{
	assert(!is_empty());
	return	queue[front];
}

/*
 *	is_empty
 */
int
is_empty(void)
{
	return (rear + 1) % ARRAY_SIZE == front;
}

/*
 *	is_full
 */
int
is_full(void)
{
	return (rear + 2) % ARRAY_SIZE == front;
}
