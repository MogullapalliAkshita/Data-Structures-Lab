#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top = NULL, *cur, *temp;

int isempty()
{
	if(top ==  NULL)
		return 1;
	else
		return 0;
}

void push()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to be pushed \n");
	scanf("%d",&(cur -> data));
	cur -> link = top;
	top = cur;
}

void pop()
{
	cur = top;
	top = cur->link;
	cur->link = NULL;
	printf("Poped data :  %d\n",cur->data);
	free(cur);
}


void display()
{
	temp = top;
	printf("--------\n");
	while(temp != NULL)
	{
	printf("|  %d  | \n",temp -> data);
	temp = temp -> link;
	printf("--------\n");
	}
	printf("\n");
}

int peek()
{
	return (top -> data);
}

int main()
{
	int ch,x;
	while(1)
	{
		printf("\n--------------------STACK - SINGLE LINKED LIST--------------------\n");
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
			case 1:push();
			break;	
			case 2:if(isempty())
				printf("Stack is empty \n");
			              else
				{
				pop();
				}
			break;
			case 3:if(isempty())
				printf("Stack is empty \n");
			              else
				display();
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