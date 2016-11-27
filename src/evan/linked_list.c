#include <stdio.h>
#include <stdlib.h>
typedef struct singly_linked_list{
        int val;
        struct singly_linked_list *next;
} snode;

typedef struct double_linked_list{
        int val;
        struct double_linked_list *next;
        struct double_linked_list *prev;
} dnode;

void list_init(snode *L, int *array, int array_length){
        int i;
        snode *tmp, *p = L;
        for(i = 0; i < array_length; i++){
                tmp = (snode *)malloc(sizeof(snode));
                tmp->val = array[i];
                tmp->next = NULL;
                p->next = tmp;
                p = p->next;
        }
        return;
}

void list_print(snode *L){
        snode *tmp = L;
        printf("[ ");
        for( ; tmp != NULL ; tmp = tmp->next){
                printf("%d ",tmp->val);
        }
        printf("]\n");
        return;
}

snode *list_search(snode *L, int val){
        snode *p = L;
        while((p != NULL) && (p->val != val)){
                p = p->next;
        }
        return p;
}

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

snode *list_delete(snode *L, snode *x){
        if(L == NULL || x == NULL)
                return NULL;
        if(L == x)
                return L->next;
        snode *p = L;
        do{
                if(p->next == x){
                        p->next = x->next;
                        break;
                }
        }while(p = p->next);
        return L;
}

int main(){
        int a[] = {2, 6, 3, 9, 1, 7, 4, 8, 0, 5};
        snode *p;
        snode L = {-1, NULL};

        //init a list and print as an array
        list_init(&L, a, 10);
        list_print(L.next);
        
        //search the node whose val is 5 and print it
        p = list_search(&L, 5);
        printf("%d\n", p->val);

        //insert a new node into the head
        snode new_node = {11, NULL};
        p = list_add(L.next, &new_node); 
        list_print(p);
        list_print(L.next);

        //insert a new node into the tail
        snode new_node1 = {12, NULL};
        list_add_tail(L.next, &new_node1);
        list_print(L.next);

        p = list_search(L.next, 2);
        p = list_delete(L.next, p);
        list_print(p);
        return 0;
}
