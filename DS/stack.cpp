// Linked implementation of stack.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
}*top = NULL;

void push(int item);
int pop();
int peek();
int isEmpty();
void display();

main()
{
	int choice, item;
	while(1)
	{
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display item at the top");
		printf("\n4. Display all items at the top");
		printf("\n5. Quit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the item to be pushed.");
				scanf("%d", &item);
				push(item);
				break;
			
			case 2:
				item = pop();
				if(item!=0)printf("\nPopped item is : %d", item);
				break;
			
			case 3:
				printf("Item at the top is : %d", peek());
				break;

			case 4:
				display();			
	
			case 5:
				exit(0);
		
			default:
				printf("\nPick a valid choice...");
		} // End of swtich
	} // End of while loop
} // End of main()


void push(int item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nOverflow error, system ran out of memory.");
		return;
	}
	temp->info = item;
	temp->link = top;
	top = temp;
	return;
}

int pop()
{
	struct node *temp;
	int item;
	if(top == NULL)
	{
		printf("\nUnderflow error.");
		return 0;
	}
	temp = top;
	top = top->link;
	item = temp->info;
	free(temp);
	free(temp);
	return item;
}

int peek()
{
	if(isEmpty())
	{
		printf("\nStack is empty.");
		return 0;
	}
	return top->info;
}

int isEmpty()
{
	if(top->link == NULL)
		return 1;
	return 0;
}

void display()
{
	struct node *p;
	p = top;
	if(isEmpty())
	{
		printf("\nStack is empty.");
		return;
	}
	printf("\nStack elements => \n");
	while(p->link!=NULL)
	{
		printf("%d\n", p->info);
		p = p->link;	
	}
	printf("NULL\n");
}
