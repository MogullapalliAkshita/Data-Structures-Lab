#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *f = NULL, *r = NULL, *cur;

void enqueue()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to be inserted : ");
	scanf("%d",&(cur -> data));
	if(f == NULL)
	{
		cur -> link = cur;
		f = r = cur;
	}
	else
	{
		r -> link = cur;
		cur -> link = f;
		r = cur;
	}
}

void dequeue()
{
	if(f == NULL)
		printf("Queue is empty \n");
	else if(f == r)
	{
		printf("Deleted data : %d", f -> data);
		f = r = NULL;
	}
	else
	{
		cur = f;	
		printf("Deleted data : %d\n",cur -> data);
		f= f -> link;
		r -> link = f;
		free(cur);	 
	}
}

void display()
{
	if(f == NULL)	
		printf("Queue is empty\n");
	else
	{
		cur = f;
		while(cur -> link != f)
		{
			printf("%d ",cur -> data);
			cur = cur -> link;
		}
		printf("%d ",cur -> data);
	}
}

int main()
{
	int ch,x;
	while(1)
	{
		printf("\n\n-----------------------------------------------------------------------\n");
		printf("Circular Queue using single linked list\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display queue\n");
		printf("4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: enqueue();
		break;
		case 2:dequeue();
		break;
		case 3:display();
		break;
		case 4:exit(0);
		}
	}
	return 0;
}