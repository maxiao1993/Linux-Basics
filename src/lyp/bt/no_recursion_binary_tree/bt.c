#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

#define BUF_SIZE 10

/* 打印一个节点的值，以其孩子的值 */
void print_node_info(struct bt *node)
{
    printf("node value : %d\n", node->data.value);
    if(node->left != NULL)
        printf("left is NOT NULL, and its value is %d\n", node->left->data.value);
    else
        printf("left is NULL\n");

    if(node->right != NULL)
        printf("right is NOT NULL, and its value is %d\n", node->right->data.value);
    else
        printf("right is NULL\n");
}

/* 
 * 找到添加节点的父节点的位置
 * 返回 node， 添加节点的父节点的位置
 */
static struct bt *traversal_local(struct bt *root, int key)
{
    struct bt *node = root;

    while(1){
        
        if(node->data.value > key)
            if(node->left != NULL)
                node = node->left;
            else
                break;
        else{
            if(node->right != NULL)
                node = node->right;
            else
                break;
        }
    }
    
    return node;
}

/* 添加节点 */
void insert_opt_node(struct bt *root, int new_node_value)
{
    struct bt *pos;
    struct bt *new;

    pos = traversal_local(root, new_node_value);
    new = (struct bt*)malloc(sizeof(*new));
    define_node(new, new_node_value);

    if(pos->data.value > new->data.value)
        pos->left = new;
    else
        pos->right = new;
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
void create_original_bt(struct bt *root)
{
    FILE *fp = fopen("./bt.txt", "r");
    char buf[BUF_SIZE]= {0};
        
    while(fgets(buf, BUF_SIZE, fp) != NULL){
        int value_tmp;
        value_tmp = atoi(buf);
        insert_opt_node(root, value_tmp); 
    }
}

/*
 *  查找值 
 *  it's possible NULL or NOT NULL 
 */
struct bt *search_opt_node(struct bt *root, int value)
{
    struct bt *node = root;

    while(node != NULL){
        if(node->data.value == value)
            return node;

        if(node->data.value > value)
            node = node->left;
        else
            node = node->right;
    }
    
    return NULL;
}


/* 
 * 辅助函数
 * 删除节点时，遍历这颗树找到删除的节点和其父节点
 * *del 是删除节点的地址
 * *del_parent是删除节点的父节点的地址
 * 同为NULL时，没有这个节点
 */ 
void traversal_delete_safe(struct bt *root, struct bt **del, 
    struct bt **del_parent, int delete){
    
    struct bt *pos, *parent;

    pos = root;
    parent = root;
    while(1){

        if(pos->data.value == delete)
            goto success;

        parent = pos;
        if(pos->data.value > delete){
            pos = pos->left;
        }else{
            pos = pos->right;
        }

        if(pos == NULL)
            goto failure;
            
    }

success: 
    *del = pos;
    *del_parent = parent;
    return;
failure:
    *del = NULL;
    *del_parent = NULL;
    return;    
}

/* if left, return 1; if right, return 0 */
static inline int left_or_right(struct bt *parent, struct bt *child)
{
    return parent->left == child ? 1 : 0;
}

/* 寻找一个节点的右子树的最左节点及其父节点 */
static struct bt* mostleft(struct bt *root, struct bt **mostleft_node_parent)
{
    struct bt *node = root->right;
    struct bt *parent = NULL;   

    while(1){
        if(node->left == NULL)
            break;
        else{
            parent = node;
            node = node->left;
        }
    }

    if(parent == NULL)
        *mostleft_node_parent = root;
    else
        *mostleft_node_parent = parent;

    return node;
}

/* 删除指定节点 */
static void delete_node(struct bt *del, struct bt *del_parent)
{
    struct bt *del_left, *del_right;
    struct bt *mostleft_node, *mostleft_node_parent;

    
    del_left = del->left;
    del_right = del->right;

    printf("del : %d, del_parent : %d\n", 
           del->data.value, del_parent->data.value);

    if(del == del_parent){
        printf("this is the root node, Don't delete\n");
        return;
    }
        
    /*This leaf node */
    if(del_left == NULL && del_right == NULL){
        printf("this is leaf node\n");
        if(left_or_right(del_parent, del))
            del_parent->left = NULL;
        else
            del_parent->right = NULL;

        goto free_del;
    }
    
    /* only one child */
    if((del_left == NULL && del_right != NULL) 
        || (del_right == NULL && del_left != NULL)){
        printf("only one child\n");
        if(left_or_right(del_parent, del)){
            if(del_left != NULL)
                del_parent->left = del_left;
            else
                del_parent->left = del_right;
        }else{
            if(del_left != NULL)
                del_parent->right = del_left;
            else
                del_parent->right = del_right;
        }

        print_node_info(del);
        goto free_del;
    }

    /* This is node with two children */
    /*
     * 若删除节点有两个孩子，那删除操作：
     * 1 找到节点的右子树的最左孩子
     * 2 最左孩子代替删除节点
     * 3 删除最左孩子
     */ 
    printf("this is node with two children\n");
    /* 
     *  已经找到删除节点右子树的最左边的节点，
     *  即右子树中数值最小的节点
     *  mostleft_node_parent 指向这个节点的父节点
     */
    mostleft_node = mostleft(del, &mostleft_node_parent);
    
    /* 用mostleft_node代替 */
    del->data.value = mostleft_node->data.value;
    print_node_info(del);


    /* 删除mostleft_node节点 */
    print_node_info(mostleft_node_parent);
    
    if(mostleft_node_parent == mostleft_node)
        goto free_mostleft;
    if(mostleft_node_parent->data.value > mostleft_node->data.value)
        delete_node(mostleft_node_parent->left, mostleft_node_parent);
    else
        delete_node(mostleft_node_parent->right, mostleft_node_parent);
    
    return;

free_del:
    free(del);
    return;

free_mostleft:
    free(mostleft_node);
    return;

}

/* 删除节点 */
void delete_opt_node(struct bt *root, int delete)
{
    struct bt *del, *del_parent;

    traversal_delete_safe(root, &del, &del_parent, delete);

    delete_node(del, del_parent);
}
