#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};


//struct node *create_list(struct node *start);

void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);

struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefor(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *deeleete(struct node *start, int data);
struct node *reeverse(struct node *start);

int main()
{
	struct node *start=NULL;
	int choice, data, item, pos;
	while(1)
	{
		printf("\n\n\n1. Create list");
		printf("\n2. Display");
		printf("\n3. Count");
		printf("\n4. Search");
		printf("\n5. Add to empty list / Add at beginning");
		printf("\n6. Add at end");
		printf("\n7. Add after node");
		printf("\n8. Add before node");
		printf("\n9. Add at position");
		printf("\n10. Delete");
		printf("\n11. Reverse");
		printf("\n12. Quit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
//				start = create_list(start);
				break;
			
			case 2:
				display(start);
				break;
			
			case 3: 
				count(start);
				break;

			case 4:
				printf("\nEnter the element you want to search :- ");
				scanf("%d", &data);
				search(start, data);
				break;
			
			case 5:
				printf("\nEnter the element to be inserted :- ");
				scanf("%d", &data);
				start = addatbeg(start, data);
				break;
			case 6:
				printf("\nEnter the element to be inserted :- ");
				scanf("%d", &data);
				start = addatend(start, data);
				break;
			case 7:
				printf("\nEnter the element to be inserted :- ");
				scanf("%d", &data);
				printf("\nEnter the element after which to insert :- ");
				scanf("%d", &item);
				start = addafter(start, data, item);
				break;
			case 8:
                                printf("\nEnter the element to be inserted :- ");
                                scanf("%d", &data);
                                printf("\nEnter the element before which to insert :- ");
                                scanf("%d", &item);
                                start = addbefor(start, data, item);
                                break;
			case 9:
                                printf("\nEnter the element to be inserted :- ");
                                scanf("%d", &data);
                                printf("\nEnter the position at  which to insert :- ");
                                scanf("%d", &item);
                                start = addatpos(start, data, item);
                                break;
			case 10:
				printf("\nEnter the element to be deleted :- ");
				scanf("%d", &data);
				start = deeleete(start, data);
				break;
			case 11:
				start = reeverse(start);
				break;
			case 12:
				exit(1);
			default:
				printf("\nPlease select a valid option... ");
		} // End of Switch statement.
	} // End of infinite While loop.
} // End of Main function.


void display(struct node *start)
{	
	struct node *p;
	if(start == NULL)
	{
		printf("\nList empty.");
		return;
	}
	p = start;
	printf("\nList is :   start -> ");
	while(p!=NULL)
	{
		printf("%d -> ", p->info);
		p = p->link;
	}
	
	printf("NULL\n");
}

void count(struct node *start)
{
	int c = 0;
	struct node *p;
	p = start;
	while(p!=NULL)
	{
		p = p->link;
		c++;
	}
	printf("\nLenght of this list is : %d", c);
}

void search(struct node *start, int data)
{
	struct node *p;
	p = start;
	int pos = 1;
	while(p!=NULL)
	{
		if(p->info == data)
		{
			printf("\nThe item is found at position %d", pos);
			return;
		}
		p = p->link;
		pos++;
	}
	printf("\nGiven data is not in the list.");
	return;
}

struct node *addatbeg(struct node *start, int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}

struct node *addatend(struct node *start, int data)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	p = start;
	while(p->link!=NULL)
		p=p->link;
	p->link = temp;
	temp->link = NULL;
	return start;
}

struct node *addafter(struct node *start, int data, int item)
{
	struct node *temp, *p;
	p = start;
	while(p!=NULL)
	{
		if(p->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("\nEntered item not in the list.");
	return start;
}
	
struct node *addbefor(struct node *start, int data, int item)
{
	struct node *p, *temp;
	p = start;
	if(start == NULL)
	{
		printf("\nList is empty.");
		return start;
	}
	if(item == start->info)   // If data is to be entered before first element.
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	while(p->link==NULL)
	{
		if(p->link->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("\nEntered item not in the list.");
	return start;
}

struct node *addatpos(struct node *start, int data, int item)
{
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	int i, pos = item;
	if(pos == 1)
	{
		addatbeg(start, data);
		return start;
	}
	p = start;
	for(i = 1; i < pos; i++)
		p = p->link;
	if(p == NULL)
		printf("\nThere are less than %d elements in the list.", pos);
		
	else
	{
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

struct node *deeleete(struct node *start, int data)
{
	struct node *p, *temp;
	if(start == NULL)
	{
		printf("\nList is empty.");
		return start;
	}
	if(start->info == data)   // Deletion of first element.
	{
		temp = start;
		start = start->link;
		free(temp);
		return start;
	}
	p = start;
	while(p->link!=NULL)	
	{
		if(p->link->info == data)
		{
			temp = p->link;			
			p->link = temp->link;
			free(temp);
			return start;
		}
		p = p->link;
	}
	printf("\nElement %d found in the list", data);
	return start;
}
struct node *reeverse(struct node *start)
{
	struct node *prev, *p, *next;
	prev = NULL;
	p = start;
	while(p!=NULL)
	{
		next = p->link;
		p->link = prev;
		prev = p;
		p = next;
	}
	start = prev;
	return start;
}
		
