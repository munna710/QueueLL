#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct queuenode* queuepointer;
struct queuenode
{
	int data;
	queuepointer next;
};
queuepointer front=NULL,rear=NULL,node;
void add(int);
void del();
void list();
void main()
{
	int choice,n;

	do
	{
		clrscr();
		printf("\n\tqueue operation\n");
		printf("\n\t\t1.add");
		printf("\n\t\t2.delete");
		printf("\n\t\t3.list");
		printf("\n\t\t4.exit");
		printf("\nenter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n enter the data: ");
			       scanf("%d",&n);
			       add(n);
				break;
			case 2:del();
				break;
			case 3:list();
				break;
			default:printf("please enter the choice between(1-6)");
				continue;
		 }
		 getch();
	}
	while(choice!=4);
}
void add(int x)
{
	node=(queuepointer)malloc(sizeof(*node));
	if(node==NULL)
	{
		printf("\nsorry,insufficient memmory...");
		return;
	}
	node->data=x;
	node->next=NULL;
	if(front==NULL)
	front=rear=node;
	else
	{
		rear->next=node;
		rear=rear->next;
	}
	printf("\n%d is added",x);
}
void del()
{
	if(front==NULL)
	{
		printf("\nqueue is empty...");
		return;
	}
	printf("\n%d is removed",front->data);
	node=front;
	front=front->next;
	free(node);
}
void list()
{
	if(front==NULL)
	{
		printf("\nqueue is empty...");
		return;
	}
	printf("\nelements in the queue are:\n");
	for(node=front;node!=NULL;node=node->next)
	printf("%d\n",node->data);
}