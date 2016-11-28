#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>


//创造单项链表节点
typedef struct single_list{
		int val;
		struct single_list * next;
}Node;

static Node *ph;
//插入
Node *Add(int val)
{
		Node *padd;
		padd = (Node *)malloc(sizeof(Node));
		padd ->val = val;
		padd ->next = ph ->next;
		ph ->next = padd;
		
		return padd;
}

Node *D_list()
{
		Node * pd= NULL;
		pd=(Node *)malloc(sizeof(Node));
		
		while(ph->next != NULL)
		{
				ph=pd;
				ph=ph->next;

		}
		free(pd);		

}

//打印
void P_list()
{
		if(NULL == ph ->next)
		{
				printf("IS NULL\n");

				return ;
		}
		
		while(ph ->next != NULL)
		{
				printf("%d\n",ph->val);
				ph = ph->next;
		}
		
}




void main(void)
{
		  ph=(Node *)malloc(sizeof(Node));
		  ph ->val = -1;
		  ph ->next = NULL;
		
		FILE *fd;
		fd = fopen("test.txt","r");
		char ch[12];
		while(fgets(ch,12,fd) != NULL)
		{
				int i;
				i = atoi(ch);
				Add(i);
		}
		fclose(fd);
		P_list();
		D_list();
		P_list();

}







