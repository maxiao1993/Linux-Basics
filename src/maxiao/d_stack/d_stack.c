/*
 *一个用动态分配数组实现的堆栈
 *堆栈的长度在创建堆栈的函数被调用时给出，该函数必须在任何其他操作堆栈的函数被调用之前调用。
 */

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 *用于存储堆栈元素的数组和指向堆栈顶部元素的指针。
 */

static		STACK_TYPE	*stack;
static		int	stack_size;
static		int		top_element = -1;

/*
 *	create_stack
 */
void
create_stack(int size)
{
	assert(stack_size == 0);
	stack_size = size;
	//assert(stack_size == 0);
	stack = malloc(stack_size * sizeof(STACK_TYPE));
	assert(stack != NULL);
}

/*
 *	destroy_stack
 */
void
destroy_stack(void)
{
	assert(stack_size > 0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}

/*
 *	push
 */
void
push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

/*
 *	pop
 */
void
pop(void)
{
	assert(!is_empty());
	top_element -= 1;
}

/*
 *	top
 */
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

/*
 *	is_empty
 */
int
is_empty(void)
{
	assert(stack_size > 0);
	return top_element == -1;
}

/*
 *	is_full
 */
int
is_full(void)
{
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}
