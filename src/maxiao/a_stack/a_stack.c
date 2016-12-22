/*
 *用一个静态数组实现的堆栈，数组的长度只能通过修改#define定义
 并对模块重新进行编译来实现。
 * */

#include"stack.h"
#include<assert.h>

#define		STACK_SIZE	100	//堆栈中值的数量的最大限制

/*
 *存储堆栈中值的数组和一个指向堆栈顶部元素的指针。
 * */
static		STACK_TYPE	stack[STACK_SIZE];
static		int		top_element = -1;

/*push
 * */
void
push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

/*pop
 * */
void
pop(void)
{
	assert(!is_empty());
	top_element -= 1;
}

/*top
 * */
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

/*is_empty
 * */
int
is_empty(void)
{
	return top_element == -1;
}

/*is_full
 * */
int
is_full(void)
{
	return top_element == STACK_SIZE - 1;
}
