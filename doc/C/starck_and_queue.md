# 栈与对列


## 目录
- 一、栈
  - 1.1 栈的定义
  	- 1.1.1 栈的相关概念
  	- 1.1.2 栈的基本操作 
  - 1.2 栈的表示与实现
  	- 1.2.1 栈的数组实现
  	- 1.2.2 栈的链表实现	 
- 二、对列
  - 2.1 对列的定义
    - 2.1.1 队列的相关概念
    - 2.1.2 队列的基本操作
  - 2.2 对列的实现
    - 2.2.1 队列的数组实现
    - 2.2.2 队列的链表实现

# 一、栈
## 1.1 栈的定义
**栈** （stack）是限定仅在表尾进行插入或删除操作的线性表。
###1.1.1 栈的相关概念
**栈顶：**表尾端称为栈顶，允许元素插入与删除的一端。

**栈低：**表头端称为栈底

**空栈：**不含元素的空表称为空栈

**栈顶节点（top）：**指向栈顶的指针

**压栈（push）：**栈的插入操作，又叫进栈，入栈

**弹栈（pop）：**栈的删除操作，也叫出栈

 ![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/1.jpg)

如上图top指向栈顶节点。

 ![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/2.jpg)

当添加一个节点3的时候，只能在栈顶节点，也就是尾节点后添加，这样3节点变成了栈顶，2节点变成了不可见节点，访问的时候只能访问到3节点。入栈时限制了插入地址，只能在栈顶添加节点。

 ![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/3.jpg)

当我们执行出栈的命令时，图2的栈顶元素是3节点，删除的时候只能允许删除栈顶的元素，这样子3节点被删除，top指向删除后的栈顶2节点

形象的说，栈是一个**先进后出**的线性表。

### 1.1.2 栈的基本操作
- 压栈（如图一）

![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/1.1.jpg)

- 弹栈(如图二)

![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/21.2.jpg)

- 判断栈是否为空
- 求栈的大小
- 获取栈顶元素的值


## 1.2 栈的表示与实现
栈是一个表，因此任何实现表的方法都能实现栈。

有两个经常使用的方法：一种方法是使用数组；另一种方法是使用指针。

### 1.2.1栈的数组实现（连续栈）
栈的第一种实现方法是使用数组。

它是利用一组地址连续的存储单元以此存放自栈底到栈顶的数据元素，同时设指针top指示栈顶的当前位置。空栈的栈顶指针值为零。

当它使用数组表示时，通常以数组的头做为栈底，以数组头到数组尾做为栈顶的生长方向：

![](https://github.com/jvshwang/Linux-Basics/blob/master/doc/img/stark_and_queue/3.1.jpg)

[栈的数组实现](https://github.com/jvshwang/Linux-Basics/blob/master/src/stack/arr_stack.c)

### 1.2.2栈的链表实现 
栈的第二种 实现方法是使用链表。

[链表实现](https://github.com/jvshwang/Linux-Basics/blob/master/src/stack/l_stack.c)

# 二、队列

## 2.1队列的定义
与栈一样，队列也是表。但使用队列是插入在一端进行而删除则在另一端进行。

队列中数据是按照"先进先出（FIFO, First-In-First-Out）"方式进出队列的。

### 2.1.1队列的相关概念
**队头：**在表中允许删除的一端。
**队尾：**在表中允许插入的一端。
**入队：**向队尾插入元素的操作。
**出队：**从队头取出元素的操作。

### 2.1.2队列的基本操作
