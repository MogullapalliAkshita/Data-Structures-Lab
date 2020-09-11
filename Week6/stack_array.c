#include<stdio.h>
#include<stdlib.h>
#define maxsize 7
int a[maxsize], top = -1;
void push(int item)
{
		top += 1;
		a[top] = item;
		printf("Inserted the element into stack \n");
}

int pop()
{
	return(a[top--]);
}

int isfull()
{
	if(top == maxsize -1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int peek()
{	
	return (a[top]);
}

void display()
{
	printf("--------\n");
	for(int i = top; i >= 0; i--)
	{
	printf("|  %d  | \n",a[i]);
	printf("--------\n");
	}
	printf("\n");
}	

int main()
{
	int ch,x;
	while(1)
	{
		printf("\n--------------------STACK - ARRAYS--------------------\n");
		printf("Menu Available : \n");
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Peek \n");
		printf("5. Exit \n");
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(isfull())
				printf("Stack is full \n");
			              else
			              {
				printf("Enter element to be pushed into stack \n");
				scanf("%d",&x);
				push(x);
			              }
			break;	
			case 2:if(isempty())
				printf("Stack is empty \n");
			              else
				{
				x = pop();
				printf("Deleted element is %d",x);
				}
			break;
			case 3:display();
			break;
			case 4: if(isempty())
				printf("Stack is empty \n");
			              else
				{
				x = peek();
				printf("Topmost element is %d",x);
				}
			break;
			case 5:exit(0);
		}
		
	}
}