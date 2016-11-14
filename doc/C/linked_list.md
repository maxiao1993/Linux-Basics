# 基本链表（linked list）算法
起草人：赵益民(zhaoym2016@lzu.edu.cn)

## 基本结构定义
链表可以有多种形式定义，它可以是单链接(singly linked)的或者是双链接(double linked)的，可以是有序的也可以是无序的，可以是循环的也可以是非循环的。

单链接和双链接由于在部分操作中存在差异，因此以下主要讨论这两种类型

> 单链表
```c 
    typedef struct singly_linked_list {
        int val;
        struct singly_linked_list *next;
    } snode;
```

> 双向链表 
```c
    typedef struct double_linked_list {
        int val;
        struct double_linked_list *next;
        struct double_linked_list *prev;
    } dnode;
```

## 链表的搜索
过程list_search(L,k)采用简单的线性搜索方法，用于查找链表L中第一个关键字为k的元素，并返回改指针。如果没有关键字为k的对象，返回NULL。

```c
    snode *list_search(snode *L, int k){
        snode *p = L;
        while((p != NULL) && (p.val != k)){
            p = p->next;
        }
        return p;
    }
```

## 链表的插入
链表的插入分多种情况，简单的插入例如只插入到链表头或者链表尾，复杂的情况如插入到指定的位置

这里只介绍简单的链表头插入和链表尾插入
```c
    //单链表
    snode *list_add(snode *L, snode *x){
        if(x != NULL)
            x->next = L;
        return x;
    }

    void list_add_tail(snode *L, snode *x){
        snode *p = L;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = x;
        return;
    }


    //双链表
    dnode *list_add(dnode *L, dnode *x){
        if(x != NULL)
            x->next = L;
        if(L != NULL)
            L->prev = x;
        L = x;
        x->prev = NULL;
        return L;
    }
```
## 链表的删除
链表的删除情况也较多：
- 已知节点指针，在单链表或者双向链表两种情况下删除该节点
- 已知关键字，删除第一个或者所有值为关键字的链表节点。 

代码分别如下
### 已知节点指针
```c
    //单链表
    snode *list_delete(snode *L, snode *x){
        if(L == NULL || x == NULL)
            return;
        if(L == x)
            return L->next;
        snode *p = L;
        do{
            if(p->next == x){
                p->next = x->next;
                break;
            }
        }while( p = p->next );
        return L;
    }

    //双向链表
    void list_delete(dnode *L, dnode *x){
        if( x == NULL)
            return;
        if( x-> prev != NULL)
            x->prev->next = x->next;
        else
            L = x->next;
        if( x->next != NULL)
            x->next->prev = x->prev
    }
```
### 已知关键字
当给定关键字时，我们首先使用链表的搜索操作找到指针，然后再利用上面定义的删除给定节点指针的方式删除我们想要删除的节点即可
```c 
    //单链表：已知链表L和关键字k
    snode *p;
    p = list_search(L, k);
    list_delete(L, p);

    //双向链表：已知链表L和关键字k
    dnode *p;
    p = list_search(L, k);
    list_delete(L, p);
```

当要删除所有值为关键字的链表节点时，只需要添加一个while循环即可
```c
    //单链表：已知链表L和关键字k
    snode *p;
    while(p = list_search(L, k)){
        L = list_delete(L, p);
    }

    //上面这种方法效率并不是很好,我们希望一遍过(one-pass),那我们可以这样实现
    snode* removeElements(snode* L, int k) {
        snode *newHead = {-1, NULL};
        snode *p = newHead;
        newHead->next = L;
        while(p->next){
            if(p->next->val == k){
                p->next = p->next->next;
            }else
                p = p->next;
        }
        return newHead->next;
    }

    //双向链表：已知链表L和关键字k
    dnode *p;
    while(p = list_search(L, k)){
        list_delete(L, p);
    }

```

# 高级链表（advanced linked list）算法
## 判断循环链表
如何判断一个链表是否是循环的?

以下是一种有效的实现.
```c 
    int hasCycle(ListNode *head) {
        ListNode *fast;
        ListNode *slow;
        fast = slow = head;
        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return 1;
        }
        return 0;
    }
```

在此基础之上, 问:  
1.如果已知是循环链表, 怎么知道他的循环部分有多少个节点?即环有多大?  
2.同样已知是循环链表, 怎么获得那个循环开始的节点?以及表头距这个节点有多远?

```c 
    snode *detectCycle(snode *head) {
        snode *fast = head, *slow = head;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)
            return NULL;
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
```
## LeetCode OJ中的一些算法题
### ID: 24 -- Swap Nodes in Pairs
> Given a linked list, swap every two adjacent nodes and return its head.  
> For example,  
>> Given 1->2->3->4, you should return the list as 2->1->4->3.  

> Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

```c 
    snode* swapPairs(snode* head) {
        snode newHead = {-1, NULL} ;
        snode *p = newHead;
        p->next = head;
        snode *q = p->next;
        while(q && q->next){
            snode *tmp = q;
            q = q->next;
            tmp->next = q->next;
            q->next = tmp;
            p->next = q;
            q = tmp->next;
            p = tmp;
        }
        return newHead.next;
    }

```

### ID: 92. Reverse Linked List II
> Reverse a linked list from position m to n. Do it in-place and in one-pass.  
>For example:
>> Given 1->2->3->4->5->NULL, m = 2 and n = 4,   
>> return 1->4->3->2->5->NULL.

>Note:
>> Given m, n satisfy the following condition:  
>> 1 ≤ m ≤ n ≤ length of list.  

```c 
    snode* reverseBetween(snode* head, int m, int n) {
        snode newHead = {-1, NULL};
        snode *q = newHead, *p1, *p2, *tmp, *pre;
        q->next = head;
        for(int i = 0; i < m-1; i++){
            q = q->next;
        }
        p1 = q;
        p2 = q->next;
        pre = p1;
        q = q->next;
        for(int i = m; i <= n; i++){
            snode *tmp = q;
            q = q->next;
            tmp->next = pre;
            pre = tmp; 
        }
        p1->next = pre;
        p2->next = tmp;
            
        return newHead.next;
    }
```
## 内核中链表的实现
在linux的内核中提供了链表的使用接口, 实现的都是是双向链表, 所有链表操作的代码都在<linux/list.h>中实现, 而结构体struct list_head在<linux/type.h>中定义.
```c 
    struct list_head {
	    struct list_head *next, *prev;
    };
```

### 链表的使用
类似于:
```c
    struct fox{
        unsigned long   tail_length;
        unsigned long   weight;
        int             is_fantastic;
        struct list_head list;
    }

    list_add(&f->list, &fox_list);
```

### 初始化工作
```c 
    #define LIST_HEAD_INIT(name) { &(name), &(name) }

    #define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)

    static inline void INIT_LIST_HEAD(struct list_head *list)
    {
        WRITE_ONCE(list->next, list);
        list->prev = list;
    }
```

WRITE_ONCE是一个宏定义, 定义在<linux/compiler.h>中
```c 
    static __always_inline void __write_once_size(volatile void *p, void *res, int size)
    {
        switch (size) {
        case 1: *(volatile __u8 *)p = *(__u8 *)res; break;
        case 2: *(volatile __u16 *)p = *(__u16 *)res; break;
        case 4: *(volatile __u32 *)p = *(__u32 *)res; break;
        case 8: *(volatile __u64 *)p = *(__u64 *)res; break;
        default:
            barrier();
            __builtin_memcpy((void *)p, (const void *)res, size);
            barrier();
        }
    }

    #define WRITE_ONCE(x, val) \
    ({							\
        union { typeof(x) __val; char __c[1]; } __u =	\
            { .__val = (__force typeof(x)) (val) }; \
        __write_once_size(&(x), __u.__c, sizeof(x));	\
        __u.__val;					\
    })
```

### 向链表中插入一个节点
```c
    static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
    {
        next->prev = new;
        new->next = next;
        new->prev = prev;
        WRITE_ONCE(prev->next, new);
    }
    /**
    * list_add - add a new entry
    * @new: new entry to be added
    * @head: list head to add it after
    *
    * Insert a new entry after the specified head.
    * This is good for implementing stacks.
    */
    static inline void list_add(struct list_head *new, struct list_head *head)
    {
        __list_add(new, head, head->next);
    }


    /**
    * list_add_tail - add a new entry
    * @new: new entry to be added
    * @head: list head to add it before
    *
    * Insert a new entry before the specified head.
    * This is useful for implementing queues.
    */
    static inline void list_add_tail(struct list_head *new, struct list_head *head)
    {
        __list_add(new, head->prev, head);
    }
```
### 从链表中删除一个节点
```c 
    /*
    * Delete a list entry by making the prev/next entries
    * point to each other.
    *
    * This is only for internal list manipulation where we know
    * the prev/next entries already!
    */
    static inline void __list_del(struct list_head * prev, struct list_head * next)
    {
        next->prev = prev;
        WRITE_ONCE(prev->next, next);
    }

    /**
    * list_del - deletes entry from list.
    * @entry: the element to delete from the list.
    * Note: list_empty() on entry does not return true after this, the entry is
    * in an undefined state.
    */
    static inline void __list_del_entry(struct list_head *entry)
    {
        __list_del(entry->prev, entry->next);
    }

    static inline void list_del(struct list_head *entry)
    {
        __list_del(entry->prev, entry->next);
        entry->next = LIST_POISON1;
        entry->prev = LIST_POISON2;
    }

    /**
    * list_del_init - deletes entry from list and reinitialize it.
    * @entry: the element to delete from the list.
    */
    static inline void list_del_init(struct list_head *entry)
    {
        __list_del_entry(entry);
        INIT_LIST_HEAD(entry);
    }
```
其中LIST_POISON定义在<linux/posion.h>中,具体定义如下:
```c 
    /*
    * Architectures might want to move the poison pointer offset
    * into some well-recognized area such as 0xdead000000000000,
    * that is also not mappable by user-space exploits:
    */
    #ifdef CONFIG_ILLEGAL_POINTER_VALUE
    # define POISON_POINTER_DELTA _AC(CONFIG_ILLEGAL_POINTER_VALUE, UL)
    #else
    # define POISON_POINTER_DELTA 0
    #endif

    /*
    * These are non-NULL pointers that will result in page faults
    * under normal circumstances, used to verify that nobody uses
    * non-initialized list entries.
    */
    #define LIST_POISON1  ((void *) 0x100 + POISON_POINTER_DELTA)
    #define LIST_POISON2  ((void *) 0x200 + POISON_POINTER_DELTA)

```
### 链表的替换
```c 
    static inline void list_replace(struct list_head *old,
                    struct list_head *new)
    {
        new->next = old->next;
        new->next->prev = new;
        new->prev = old->prev;
        new->prev->next = new;
    }

    static inline void list_replace_init(struct list_head *old,
                        struct list_head *new)
    {
        list_replace(old, new);
        INIT_LIST_HEAD(old);
    }
```
### 链表的移动
```c
    /**
    * list_move - delete from one list and add as another's head
    * @list: the entry to move
    * @head: the head that will precede our entry
    */
    static inline void list_move(struct list_head *list, struct list_head *head)
    {
        __list_del_entry(list);
        list_add(list, head);
    }

    /**
    * list_move_tail - delete from one list and add as another's tail
    * @list: the entry to move
    * @head: the head that will follow our entry
    */
    static inline void list_move_tail(struct list_head *list,
                    struct list_head *head)
    {
        __list_del_entry(list);
        list_add_tail(list, head);
    }
```

### 判断是否为空, 是否是尾部
```c 
/**
    * list_is_last - tests whether @list is the last entry in list @head
    * @list: the entry to test
    * @head: the head of the list
    */
    static inline int list_is_last(const struct list_head *list,
                    const struct list_head *head)
    {
        return list->next == head;
    }

    /**
    * list_empty - tests whether a list is empty
    * @head: the list to test.
    */
    static inline int list_empty(const struct list_head *head)
    {
        return READ_ONCE(head->next) == head;
    }
```
其他更多请查阅内核源代码
