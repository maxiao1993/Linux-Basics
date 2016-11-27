#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bt.h"

#define BUF_SIZE 20

void print_node_info(struct bt *node)
{
    if(!node){
        printf("it is NULL node\n");
        return;
    }

    printf("node value : %d\n", node->data.value);
    if(node->left == NULL)
        printf("left NULL\n");
    else
        printf("node left : %d\n", node->left->data.value);
    
    if(node->right == NULL)
        printf("right NULL\n");
    else
        printf("node right : %d\n", node->right->data.value);
   
    if(node->parent == NULL)
        printf("It's root node\n");
    else
        printf("parent : %d\n", node->parent->data.value);
    
    putchar('\n');

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

static void insert_node(struct bt *insert_local, struct bt *node)
{
    if(is_left_right(insert_local, node)){
        insert_local->left = node;
    }else{
        insert_local->right = node;
    }

    node->parent = insert_local;

}



static struct bt *traversal(struct bt *node, struct bt *key)
{
    struct bt *pos = node;

    if(!pos)
        return NULL;
    
    if(pos->data.value > key->data.value){
        if(pos->left != NULL){
            return traversal(pos->left, key);
        }
    }else{
        if(pos->right != NULL){
            return traversal(pos->right, key);
        }
    }
    
    return pos;
}

struct bt *search_opt_node(struct bt *node, int value)
{
    if(node->data.value == value)
        return node;
    else if(node->data.value > value){
        if(node->left != NULL)
            return search_opt_node(node->left, value);
    }
    else{
        if(node->right != NULL)
            return search_opt_node(node->right, value);
    }
    return NULL;
}

void insert_opt_node(struct bt *root, int value)
{
    struct bt *newnode;
    struct bt *pos;

    newnode = create_new_node(value);
    pos = traversal(root, newnode);
    insert_node(pos, newnode);

}

/*
* 依据bt.txt, 创建一颗二叉树 
*                    10
*                 /      \
*                5         18
*               /  \      /   \
*              3     8    16   19
*             / \   / \     \    \
*            2   4  6  9    17    20
*           /        \
*          1          7
*/
struct bt *init_opt_bt(void)
{
    struct bt *root = NULL;
    FILE *fp;
    char buf[BUF_SIZE];
    
    fp = fopen("./bt1.txt", "r");

    while(fgets(buf, BUF_SIZE, fp) != NULL){
        int value;
        struct bt *node;
        struct bt *pos;

        value = atoi(buf);

        node = create_new_node(value);
        
        pos = traversal(root, node);
        if(!pos){
            root = node;
            continue;
        }

        insert_node(pos, node);
    }
    
    return root;
}

static void delete_node(struct bt *del);

void delete_opt_node(struct bt *root, int value)
{
    struct bt *del;

    del = search_opt_node(root, value);
    
    if(del == NULL){
        printf("delete node not exist\n");
        return ;
    }

    delete_node(del);
}

static void delete_node(struct bt *del)
{
    struct bt *parent_del;
    struct bt *mostleft;


    if(del == NULL){
        printf("delete node not exist\n");
        return;
    }
    
    parent_del = del->parent;

    /*node that has not child */
    if(del->left == NULL && del->right == NULL){
        printf("not child \n");
        if(is_left_right(parent_del, del))
            parent_del->left = NULL;
        else
            parent_del->right = NULL;

        goto free_del;
    }


    /* node that has only one child */
    /* first only right child */
    if(del->left == NULL && del->right != NULL){
        printf("only right child\n");
        if(is_left_right(parent_del, del)){
            parent_del->left = del->right;
            //printf("parent_del left : %d\n", parent_del->left->data.value);
        }else{
            parent_del->right = del->right;
            //printf("parent_del right : %d\n", parent_del->right->data.value);
        }
        del->right->parent = parent_del;
        goto free_del;
    }

    /* second only left child */
    if(del->left != NULL && del->right == NULL){
        printf("only left child\n");
        if(is_left_right(parent_del, del)){
            parent_del->left = del->left;
            //printf("parent_del left : %d\n", parent_del->left->data.value);
        }else{
            parent_del->right = del->left;
            //printf("parent_del right : %d\n", parent_del->right->data.value);
        }
        del->left->parent = parent_del;
        goto free_del;
    }


    /* node with two children */
    printf("node with two children \n");
    
    mostleft = find_mostleft(del->right);
   // printf("mostleft : %d\n", mostleft->data.value); 
   
    /* replace del with mostleft */
    change_del_mostleft(del, mostleft);
    /*
    printf("after replace\n");
    print_node_info(del);
    print_node_info(mostleft);
    printf("---------------------------\n");
    */
    /* mostleft delete */
    delete_node(mostleft);
    return;

    
    
     
free_del:
    free(del);
    return;
}
