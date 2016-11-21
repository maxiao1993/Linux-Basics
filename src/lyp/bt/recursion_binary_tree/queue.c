#include <stdio.h>
#include <stdlib.h>

#include "bt.h"
#include "queue.h"

static struct delqueue *head = NULL;
static struct delqueue *tail = NULL;

static int mark_root = 1;

static int delqueue_empty();
static void enqueue_bt(struct bt *node);
static void dequeue_bt();


void destroy_opt_bt(struct bt *root)
{
    struct bt *node = root;

    if(node == NULL)
        return ;
    
    printf("start destroy\n");
    enqueue_bt(node);
    printf("enqeueu root node\n");
    mark_root = 0;
    
    do{
        dequeue_bt();
    }while(!delqueue_empty());

}


static void enqueue_bt(struct bt *node)
{
    struct delqueue *delnode;

    if(node == NULL)
    {
        printf("node is NULL\n");
        return;
    }
    printf("enqueue node value : %d\n", node->data.value);
    delnode = (struct delqueue *)malloc(sizeof(*delnode));

    delnode->node = node;
    delnode->next = NULL;
    
    if(mark_root){
        head = delnode;
        tail = delnode;
    }else{
        tail->next = delnode;
        tail = delnode;
    }

    return;
}

/* return 1, if left, otherwise return 0 */ 
static int is_left_right(struct bt *parent, struct bt *child)
{
    if(parent->data.value > child->data.value)
        return 1;
    else
        return 0;
}


static void dequeue_bt()
{
    struct delqueue *tmp = head;
    struct bt *node;

    node = tmp->node;
    if(node->left != NULL)
        enqueue_bt(node->left);

    if(node->right != NULL)
        enqueue_bt(node->right);

    head = head->next;
/*
    node->left = NULL;
    node->right = NULL;
    if(is_left_right(node->parent, node))
        node->parent->left = NULL;
    else
        node->parent->right = NULL;
*/
    free(node);
    free(tmp);

}


/* if 1, release last node then delqueue is empty, and the binary tree destroy */
static int delqueue_empty()
{
    /* 最后一个节点 */
    if(tail == head){
        free(head->node);
        free(head);
        return 1;
    }else
        return 0;
}
