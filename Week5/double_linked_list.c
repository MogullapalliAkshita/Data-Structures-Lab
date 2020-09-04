#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node *prev;
	struct node *next;
};
struct node *head = NULL, *tail = NULL, *cur, *temp, *t2;
void create()
{
	int n;
	printf("Enter the number of nodes : \n");
	scanf("%d",&n);
	for(int i =0; i<n; i++)
	{
		cur  = (struct node *)malloc(sizeof(struct node));
		printf("Enter new node data \n");
		scanf("%f",&(cur -> data));
		cur -> prev = NULL;
		cur -> next = NULL;
		if(head == NULL)
		{
			tail = head = cur;	
		}	
		else
		{
			tail -> next = cur;
			cur -> prev = tail;
			tail = cur;
		}
	}
}

void insert_at_begin()
{
	cur  = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data : \n");
	scanf("%f",&(cur->data));
	cur -> prev =  NULL;
	cur -> next = head;
	head -> prev = cur;
	head = cur ;
}

void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter data : \n");
	scanf("%f",&(cur -> data));
	cur -> next = NULL;
	cur -> prev = tail;
	tail -> next = cur;
	tail = cur;
}

void insert_at_pos()
{
	int pos,c = 1;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter the new data \n");
	scanf("%f",&(cur -> data));
	printf("Enter position where we have to enter \n");
	scanf("%d",&pos);
	temp = head;
	while( c< pos && temp != NULL )
	{
		t2 = temp;
		temp = temp -> next;
		c += 1;
	}
	cur -> prev = t2;
	t2 -> next = cur;
	temp -> prev = cur;
	cur -> next = temp;	
}

void insert_before_node()
{
	float value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data \n");
	scanf("%f",&(cur -> data));
	printf("Enter data of node before which new node is to be added \n");
	scanf("%f",&value);
	temp = head;
	while(temp -> data != value && temp != NULL)
	{
		t2 = temp;
		temp = temp -> next;
	}	
	t2 -> next = cur;
	cur -> prev = t2;
	temp -> prev = cur;
	cur -> next = temp;
}

void insert_after_node()
{
	float value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data \n");
	scanf("%f",&(cur -> data));
	printf("Enter data of node after which new node is to be added \n");
	scanf("%f",&value);
	temp = head;
	while(temp  -> data != value && temp != NULL)
	{
		temp = temp -> next;
	}	
	cur -> next = temp -> next;
	temp -> next -> prev = cur ;
	temp -> next = cur;
	cur -> prev = temp;
}


void display()
{
	if(head == NULL)
		printf("List is empty \n");
	else
	{
		cur = head;
		while(cur != NULL)
		{
			printf(" %f <->  ",cur -> data);
			cur = cur -> next;
		}
		printf("NULL \n");
	}
}

void delete_at_begin()
{
	cur = head;
	head = head -> next;
	head -> prev = NULL;
	printf("Deleted data : %f \n",cur -> data);
	cur -> next  = NULL;
	free(cur);
}

void delete_at_end()
{
	cur = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	printf("Deleted data : %f \n",cur -> data);
	cur -> prev = NULL;
	free(cur);
}

void delete_at_pos()
{
	int pos,c = 1;
	printf("Enter position where we have to delete the node \n");
	scanf("%d",&pos);
	temp = head;
	while( c<pos )
	{	
		t2 = temp;
		temp = temp -> next;
		c += 1;
	}
	t2 -> next = temp -> next;
	temp -> prev = NULL;
	temp -> next -> prev = t2;
	temp -> next = NULL;
	printf("Deleted Element = %f ",temp -> data);
	free(temp);
	
}

void delete_before_node()
{
	float value;
	temp = head;
	printf("Enter data before which node has to be deleted \n");
	scanf("%f",&value);
	while(temp -> next -> data != value && temp -> next != NULL)
	{
		t2 = temp;
		temp = temp -> next;
	}
	printf("Deleted element = %f",(temp -> data));
	t2 -> next = temp -> next;
	(temp -> next) -> prev = temp -> prev;
	temp -> next =  NULL;
	temp -> prev = NULL;
	free(temp);
}

void delete_after_node()
{
	float value;
	printf("Enter value after which, node has to be deleted \n");
	scanf("%f",&value);
	temp = head;
	while(temp -> data != value && temp != NULL) 	
	{
		temp = temp -> next;
	}
	t2 = temp -> next;
	temp -> next = t2 -> next;
	(t2 -> next) -> prev = temp;
	printf("Deleted data = %f" , t2 -> data);
	t2 -> prev = NULL;
	t2 -> next = NULL;
	free(t2);
}


void reverse_display()
{
	if(head == NULL)
		printf("List is empty \n");
	else
	{
		cur = tail;
		printf("NULL ");
		while(cur  != NULL)
		{
			printf("<-> %f  ",cur -> data);
			cur = cur -> prev;
		}
	}
}

void search_for_element()
{
	int flag = 0, c=0;
	float value;
	printf("Enter element to be searched:          \n");
	scanf("%f",&value);
	temp = head;
	while(temp != NULL)
	{
		if(temp -> data == value)
		{
			flag = 1;
			break;
		}
		temp = temp -> next;
		c++;
	}
	if(flag == 1)
		printf("At pos = %d \n",c);
	else
		printf("Element Absent \n");
}

void sorting()
{
	struct node *p1 , *p2,*last = NULL;
	int c,t;
	do
	{
		c=0;
		p1 = head;
		while(p1 -> next != last)
		{
			if(p1 -> data > p1->next->data)
			{
				t = p1 ->data;
				p1 -> data = p1 -> next ->data;
				p1 -> next -> data = t;	
				c = 1;			
			}
		p1 = p1-> next;	
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
	printf("Program for DOUBLE LINKED LIST\n");
	printf("-------------------------MENU-------------------------------\n");
	printf("1. Create a DLL \n");
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
	printf("13. Display linked list in reverse order\n");
	printf("14. Sort the double linked list \n");
	printf("15. Searching for an element in double linked list \n");
	printf("16. Exit \n");
	printf("--------------------------END------------------------------\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:create();
		break;
		case 2:insert_at_begin();
		break;
		case 3: insert_at_end();
		break;
		case 4: insert_at_pos();
		break;
		case 5: insert_before_node();
		break;
		case 6: insert_after_node();
		break;
		case 7: display();
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
		case 13:reverse_display();
		break;
		case 14:sorting();
		break;
		case 15:search_for_element();
		break;
		case 16: exit(0);
	}
	}
	return 0; 
}	