// Linked implementation of queue

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *link;
}*front = NULL, *rear = NULL;

void insert(int item);
int del();
int peek();
int isEmpty();
void display();

main()
{
	int choice, item;
        while(1)
        {
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display the element at the front");
                printf("\n4. Display all elements of the queue");
                printf("\n5. Quit\n");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1: 
                                printf("\nEnter the item to insert in queue : ");
                                scanf("%d", &item);
                                insert(item);
                                break;

                        case 2: 
                                item = del();
                                if(item!=0)
					printf("\nDeleted item is : %d", item);
                                break;

                        case 3: 
                                printf("Item at the front of queue is : %d", peek());
                                break;

                        case 4: 
                                display();

                        case 5: 
                                exit(0);

                        default:
                                printf("\nPick a valid choice...");
                } // End of swtich.
	} // End of while.
} // End of main function.		

void insert(int item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nOverflow, system ran out of memory.");
		return;
	}
	temp->info = item;
	temp->link = NULL;
	if(front == NULL)
		front = temp;
	else
		rear->link = temp;
	rear = temp;
}

int del()
{
	struct node *temp;
	int item;
	if(isEmpty())
	{
		printf("\nQueue underflow.");
		return 0;
	}
	temp = front;
	item = temp->info;
	front = front->link;
	free(temp);
	return item;
}

int peek()
{
	if(isEmpty())
	{
		printf("\nQueue underflow.");
		return 0;
	}
	return front->info;
}

int isEmpty()
{
	if(front == NULL)
		return 1;
	else 
		return 0;
}

void display()
{
	struct node *p;
	p = front;
	if(isEmpty())
	{
		printf("\nQueue is empty.");
		return;
	}
	printf("\nQueue elements are : ");
	while(p!=NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}
