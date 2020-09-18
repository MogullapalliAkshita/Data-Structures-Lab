#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int f=-1, r= -1,queue[maxsize];
int isfull()
{
	if(r == maxsize - 1)
		return 1;
	else	
		return 0;
}

int isempty()
{
	if(f == -1)
		return 1;
	else
		return 0;
}

void enqueue(int data)
{
	if(f == -1)
		f=0;
	queue[++r] = data;
}

int dequeue()
{
	int x=queue[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return x;
}

void display()
{
	for(int i=f;i<=r;i++)
		printf("%d\t",queue[i]);
}

int main()
{
	int ch,x;
	while(1){
		printf("\n----------------------------------------------------------------------------------------\n");
		printf("BASIC QUEUE USING ARRAYS : \n");
		printf("\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-QUIT\n");
		printf("ENTER YOUR CHOICE\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:if(isfull())
				printf("QUEUE OVERFLOW\n");
			else
			{
			printf("ENTER THE DATA TO BE INSERTED\n");
			scanf("%d",&x);	
			enqueue(x);	
			}
		break;
		case 2:if(isempty())
				printf("QUEUE UNDERFLOW");
			else
			{
			printf("DELETED ELEMENT IS %d\n",dequeue());
			}
		break;
		case 3:display();
		break;
		case 4:exit(0);
		}
	}
}