#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head = NULL, *tail = NULL, *cur, *prev, *next;
void create()
{
	int n;
	printf("Enter the number of nodes for linked list :     \n");
	scanf("%d", &n);
	for(int i =0;i<n;i++)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		printf("enter current node data");
		scanf("%d",&(cur -> data));
		cur -> link = NULL;
		if(head == NULL)
			head = tail = cur;
		else
		{
			tail -> link = cur;
			tail = cur;
		}
	}
}	

void insert_at_begin()
{	
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter new beginning node data:   \n");
	scanf("%d",&(cur -> data));
	cur -> link = head;
	head = cur;
}

void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter new ending node data:      \n ");
	scanf("%d",&(cur -> data));
	cur -> link = NULL;
	tail -> link = cur;
	tail = cur;
}

void insert_at_pos()
{
	int pos , c=1;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter new node data to be stored at a position :       \n");
	scanf("%d",&(cur -> data));
	printf("enter position where the data is to be stored :        \n");
	scanf("%d",&pos);
	next = head;
	while(c<pos)
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = cur;
	cur -> link = next;
}

void insert_before_node()
{
	
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter new node data :         \n");
	scanf("%d",&(cur -> data));
	printf("enter node data before which new node is to be added:       \n");
	scanf("%d",&value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		prev = next;
		next = next -> link;
	}
	prev -> link = cur;
	cur -> link = next;	
}

void insert_after_node()
{
	
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter new node data:             \n");
	scanf("%d",&(cur -> data));
	printf("enter node data after which new node is to be added :          \n");
	scanf("%d",&value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		next = next -> link;
	}
	cur -> link = next -> link;
	next -> link = cur;	
}

void display()
{
	if(head == NULL)
		printf("Linked list is empty\n");
	else
	{
		next = head;
		while(next != NULL)
		{
			printf("%d -> ",next -> data);
			next = next -> link;
		}
		printf("NULL \n");
	}
}

void delete_at_begin()
{
	cur = head;
	head = cur->link;
	cur->link = NULL;
	printf("Deleted data :  %d\n",cur->data);
	free(cur);
}

void delete_at_end()
{
	cur = head;
	while(cur -> link != tail)
		cur = cur -> link;
	cur -> link = NULL;
	next = tail;
	printf("Deleted data :  %d \n" , next -> data);
	free(next);
	tail = cur;
}

void delete_at_pos()
{
	int pos , c=1;
	printf("Enter position of the data to be deleted :      \n");
	scanf("%d",&pos);
	next = head;
	while(c<pos)
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = next -> link;
	printf("Deleted Element = %d  \n",next -> data);
	next -> link = NULL;
	free(next);
}

void delete_before_node()
{
	printf("Enter before which node we need to delete:          \n");
	int value;
	scanf("%d",&value);
	next = head;
	while(next -> link -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev -> link = next -> link;	
	next -> link = NULL;
	printf("Deleted Element :   %d \n",next->data);
	free(next);
}

void delete_after_node()
{
	printf("Enter after which node we need to delete:        \n");
	int value;
	scanf("%d",&value);
	next = head;
	while(next -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev = next -> link;	
	next -> link = prev -> link;
	printf("Deleted Element :   %d \n",prev->data);
	prev->link = NULL;
	free(prev);
}

void search_for_element()
{
	int value, flag = 0, c=0;
	printf("Enter element to be searched:          \n");
	scanf("%d",&value);
	next = head;
	while(next != NULL)
	{
		if(next -> data == value)
		{
			flag = 1;
			break;
		}
		next = next -> link;
		c++;
	}
	if(flag == 1)
		printf("At pos = %d \n",c);
	else
		printf("Element Absent \n");
}

void reverse(struct node *head)
{
	if(head != NULL)
	{
		reverse(head -> link);
		printf(" <- %d",head -> data);

	}
	else
		printf("NULL");
		
}

void reverse_array()
{
	int a[100];
	int i = 0;
	cur = head;
	while( cur != NULL)
	{
		a[i] = cur -> data;
		cur = cur -> link;
		i += 1;
	}
	i -= 1;
	printf("NULL ");
	while(i >= 0)
	{
		printf("<- %d ",a[i]);
		i--;
	}
}

void bubblesort()
{
	struct node *p1 , *p2;
	int c=0 ,t;
	p1 = head;
	while(p1 != NULL)
	{
		c++;
		p1 = p1 -> link;
	}
	for(int i = 0;i<c;i++)
	{
		p2 = head;
		while(p2 -> link != NULL)
		{
			if(p2 -> data > p2 -> link -> data)
			{
				t = p2 -> data;
				p2 -> data = p2 -> link ->data;
				p2 -> link -> data = t;
			}
			p2 = p2 -> link;
		}
	}
}

void sorting()
{
	struct node *p1 , *p2,*last = NULL;
	int c,t;
	do
	{
		c=0;
		p1 = head;
		while(p1 -> link != last)
		{
			if(p1 -> data > p1->link->data)
			{
				t = p1 ->data;
				p1 -> data = p1 -> link ->data;
				p1 -> link -> data = t;	
				c = 1;			
			}
		p1 = p1-> link;	
		}
		last = p1;
	}while(c);
}



int main()
{
	int ch;
	while(1)
	{
	printf("\n\n");
	printf("---------------------------------------------------------------\n");
	printf("Program for SINGLE LINKED LIST\n");
	printf("-------------------------MENU-------------------------------\n");
	printf("1. Create a SLL \n");
	printf("2. Insert at begining \n");
	printf("3. Insert at end \n");
	printf("4. Insert at a position \n");
	printf("5. Insert before a node\n");
	printf("6. Insert after a node \n");
	printf("7. Display all the nodes \n");
	printf("8. Delete a node at beginning \n");
	printf("9. Delete a node at end \n");
	printf("10. Delete a node at a position \n");
	printf("11. Delete a node before a node \n");
	printf("12. Delete a node after a node \n");
	printf("13. Search for an element in linked list\n");
	printf("14. Reverse printing the linked list using recursion \n");
	printf("15. Reverse printing the linked list using array \n");
	printf("16. Sort single linked list using Bubble sort with lenght of linked list  \n");
	printf("17. Sort single linked list using Bubble sort without lenght of linked list \n");
	printf("18. Exit \n");
	printf("--------------------------END------------------------------\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:create();
		break;
		case 2:insert_at_begin();
		break;
		case 3:insert_at_end();
		break;
		case 4:insert_at_pos();
		break;
		case 5:insert_before_node();
		break;
		case 6:insert_after_node();
		break;
		case 7:display();
		break;
		case 8:delete_at_begin();
		break;
		case 9:delete_at_end();
		break;
		case 10:delete_at_pos();
		break;
		case 11:delete_before_node();
		break;
		case 12:delete_after_node();
		break;
		case 13:search_for_element();
		break;
		case 14:reverse(head);
		break;
		case 15:reverse_array();
		break;
		case 16:bubblesort();
		break;
		case 17:sorting();
		break;
		case 18:exit(0);
		default:printf("Invalid entry  \n");
	}	
	}
	return 0;
}











		
		



	

