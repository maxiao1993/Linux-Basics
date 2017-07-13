#include <stdio.h>

#include "bt.h"
#include "queue.h"

enum OPT{
    SEARCH = 1,
    INSERT,
    DELETE,
    DESTROY,
    EXIT,
};

static void search(struct bt *root)
{
    int sear;
    struct bt *node;


    printf("search value : ");
    scanf("%d", &sear);

    node = search_opt_node(root, sear);

    if(!node){
        printf("NOT exist %d\n", sear);
    }else{
        printf("EXIST\n");
    }


    return;    
}

static void insert(struct bt *root)
{
    int inse;
    
    printf("insert value : ");
    scanf("%d", &inse);

    insert_opt_node(root, inse);

    return;
}

static void delete(struct bt *root)
{
    int dele;

    printf("delete value : ");
    scanf("%d", &dele);

    delete_opt_node(root, dele);
}

static void destroy(struct bt *root)
{
    destroy_opt_bt(root);
}

int main(void)
{
    struct bt *root;
    struct bt *node;
    int opt;

    /* create a new binary tree according to bt.txt*/
    root = init_opt_bt();
    node = root;
    

    while(1){
        printf("1 search, 2 insert, 3 delete, 4 destroy, 5 EXIT. opt : ");
        scanf("%d", &opt);
        switch(opt){
            case SEARCH:
                search(root);
                break;
            case INSERT:    
                insert(root);
                break;
            case DELETE:
                delete(root);
                break;
            case DESTROY:
                destroy(root);
            case EXIT:
                printf("demo exit\n");
                goto exit;
        }
    }

exit:
    return 0;
}


