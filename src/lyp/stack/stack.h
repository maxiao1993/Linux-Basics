#ifndef _STACK_H
#define _STACK_H

#define STACK_BOT_CURR 0
#define STACK_TOP_CURR 20

#define STACK_BOT_PREV -1
#define STACK_TOP_PREV 19

#define DESTROY_MARK 1
#define PUSH_MARK 0

struct stack{
    int top;
    int data[20];

    void (*pop)(struct stack *s, int val);
    int (*push)(struct stack *s, int mark);
    void (*check_top)(struct stack *s);
    int (*is_empty)(struct stack *s);
    int (*is_overflow)(struct stack *s);

};


extern void create_curr(struct stack **);
extern void create_prev(struct stack **);




extern void destroy(struct stack **);
#endif
