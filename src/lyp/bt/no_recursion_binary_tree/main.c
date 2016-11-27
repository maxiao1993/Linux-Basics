#include <stdio.h>
#include "bt.h"

struct bt bt_root = INIT_BT_ROOT(bt_root);


enum OPT{
    SEARCH = 1,
    INSERT,
    DELETE,
    EXIT,
};

static void search(struct bt *root)
{
    int sear;
    struct bt *node;


    printf("search value : ");
    scanf("%d", &sear);

    node = search_opt_node(root, sear);

    if(node == NULL){
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





int main(void)
{
    int opt;

    /* create a new binary tree according to bt.txt*/
    create_original_bt(&bt_root);

    while(1){
        printf("1 search, 2 insert, 3 delete, 4 EXIT. opt : ");
        scanf("%d", &opt);
        switch(opt){
            case SEARCH:
                search(&bt_root);
                break;
            case INSERT:    
                insert(&bt_root);
                break;
            case DELETE:
                delete(&bt_root);
                break;
            case EXIT:
                printf("demo exit\n");
                goto exit;
        }
    }

exit:
    return 0;
}



