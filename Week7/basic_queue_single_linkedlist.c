#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node *front = NULL, *rear = NULL, *cur;

void enqueue()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to be inserted : ");
	scanf("%d",&(cur -> data));
	if(front == NULL)
		front = rear = cur;
	else
	{
		rear -> link = cur;
		rear = cur;
	}
}

void dequeue()
{
	if(front == NULL)
		printf("Queue is empty \n");
	else if(front == rear)
	{
		printf("Deleted data : %d", front -> data);
		front = rear = NULL;
	}
	else
	{
		cur = front;	
		printf("Deleted data : %d\n",cur -> data);
		front = front -> link;
		free(cur);	 
	}
}

void display()
{
	if(front == NULL)	
		printf("Queue is empty\n");
	else
	{
		cur = front;
		while(cur != rear)
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
		printf("Basic Queue using single linked list\n");
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
