#ifndef _BT_H
#define _BT_H

#include <stdio.h>

#define INIT_BT_ROOT(root) {{10}, NULL, NULL} 


struct bt_data{
    int value;
};

struct bt{
    struct bt_data data;

    struct bt *left;
    struct bt *right;
};


extern void create_original_bt(struct bt *root);
extern struct bt *search_opt_node(struct bt *root, int key);
extern void insert_opt_node(struct bt *root, int new_node_value);
extern void delete_opt_node(struct bt *root, int delete_value);
extern void print_node_info(struct bt *node);


static void inline define_node(struct bt *node, int value)
{
    node->left = NULL;
    node->right = NULL;
    node->data.value = value;
}

#endif
