/*film.c -- 使用ADT风格的列表	*/
/*和list.c一同编译		*/
#include<stdio.h>
#include<stdlib.h>	//为exit()提供原型
#include"list.h"	//定义List，Item

void showmovies(Item item);

int main(void)
{
	List movies;
	Item temp;
	
	/*初始化*/
	InitializeList(&movies);

	if(ListIsFull(&movies))
	{
		fprintf(stderr , "No memory available! Bye!\n");
		exit(1);
	}

	/*收集并存储*/
	puts("Enter first movie title: ");
	while(gets(temp.title)!=NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>: ");
		scanf("%d" , &temp.rating);
		while(getchar() != '\n')
			continue;
		if(AddItem(temp,&movies) == false)
		{
			fprintf(stderr,"Problem allocating memory\n");
			break;
		}
		if(ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movies title (empty line to stop):");
	}

	/*显示*/
	if(ListIsEmpty(&movies))
		printf("No data entered.\n");
	else
	{
		printf("Here is the movie list:\n");
		Traverse(&movies,showmovies);
	}

	printf("You entered %d movies.\n",ListItemCount(&movies));
	
	/*清除*/
	EmptyTheList(&movies);
	printf("Bye!\n");
	return 0;
}

	void showmovies(Item item)
	{
		printf("Movie: %s Rating: %d\n",item.title,item.rating);
	}

