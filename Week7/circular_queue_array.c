#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
int cqueue[MAXSIZE],front=-1,rear=-1,i;
int isfull(	)
{	
	if(front ==(rear+1)%MAXSIZE)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}

void enqueue( )
{
	if(isfull())
		printf("\nCircular queue overflow\n");
	else
	{
		int item;
		printf("Enter data : ");
		scanf("%d",&item);
		if(front==-1)
			front=rear=0;
		else
			rear=(rear+1)%MAXSIZE;
		cqueue[rear]=item;
	}
}


void dequeue()
{
	if(isempty())
		printf("Circular queue underflow \n");
	else
	{
	int a=cqueue[front];
	if(front==rear)
		front=rear=-1;
	else
		front = (front+1)%MAXSIZE;
	printf("\nDeleted element from circular queue is  : %d ",a);	
	}
}

void display()
{
	if(isempty())
		printf("Circular queue is empty \n");
	else
	{
		if (front > rear)
    		{
        		for (i = front; i < MAXSIZE; i++)
            			printf("%d ", cqueue[i]);
        		for (i = 0; i <= rear; i++)
            			printf("%d ", cqueue[i]);
    		}
    		else
    		{
        		for (i = front; i <= rear; i++)
            			printf("%d ", cqueue[i]);
    		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n---------------------------------------------------------------------------\n");
		printf("Circular Queue using Arrays\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your option\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:enqueue();
		break;
		case 2:dequeue();
		break;
		case 3:display();
		break;
		case 4:exit(0);
		break;
		
		}
	}
}