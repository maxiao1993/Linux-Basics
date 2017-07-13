#ifndef _BT_H
#define _BT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct bt_data{
    int value;
};

struct bt{
    struct bt_data data;

    struct bt *left;
    struct bt *right;
    struct bt *parent;
};

extern void print_node_info(struct bt *node);
extern struct bt *init_opt_bt();
extern struct bt *search_opt_node(struct bt *root, int value);
extern void insert_opt_node(struct bt *root, int value);
extern void delete_opt_node(struct bt *root, int value);
extern void destroy_opt_bt(struct bt *root);


static inline struct bt *create_new_node(int value)
{
    struct bt *newnode;
    
    newnode = (struct bt *)malloc(sizeof(*newnode));
    memset(newnode, 0, sizeof(*newnode));
    
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data.value = value;

    return newnode;
}

static inline struct bt *find_mostleft(struct bt *node)
{
    if(node->left != NULL)
        return find_mostleft(node->left);
    else
        return node;
}

static inline void change_del_mostleft(struct bt *del, struct bt *mostleft)
{
    del->data.value = mostleft->data.value;    
}

#endif
