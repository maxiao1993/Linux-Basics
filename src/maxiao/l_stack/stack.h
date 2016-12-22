/*一个堆栈模块的接口*/

#define STACK_TYPE int 		//堆栈所存储的数据类型


/*
 *destroy_stack
 */
void destroy_stack(void);

/*push
 *把一个新值压入到堆栈中，他的参数是所需要被压入的值。
 * */
void push(STACK_TYPE value);

/*pop
 *从堆栈弹出一个值，并将其丢弃。
 * */
void pop(void);

/*top
 *返回堆栈顶部元素的值，但不对堆栈进行修改。
 * */
STACK_TYPE top(void);

/*is_empty
 *如果堆栈为空，返回TRUE，否则返回FALSE。
 * */
int is_empty(void);

/*is_full
 *如果堆栈已满，返回TRUE，否则返回FALSE。
 * */
int is_full(void);
