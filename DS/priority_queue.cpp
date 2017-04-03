#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
        int priority;
	int info;
        struct node *link;
}*front = NULL;

void insert(int item, int priority);
int del();
int isEmpty();
void display();

main()
{
        int choice, item, priority;
        while(1)
        {
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Quit\n");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1:
                                printf("\nEnter the item to insert in queue : ");
                                scanf("%d", &item);
				cout<<"\nEnter the priority of element : ";
				cin>>priority;
                                insert(item, priority);
                                break;

                        case 2:
                                item = del();
                                if(item!=0)
                                        printf("\nDeleted item is : %d", item);
				break;
	                case 3:
                                display();

                        case 4:
                                exit(0);

                        default:
                                printf("\nPick a valid choice...");
                } // End of swtich.
        } // End of while.
} // End of main function.              

void insert(int item, int item_priority)
{
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL)
	{
		cout<<"\nMemory not available.";
		return;
	}
	tmp->info;
	tmp->priority = item_priority;
	if(isEmpty() || item_priority < front->priority)
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		p = front;
		while(p->link!=NULL && p->link->priority<=item_priority)
			p=p->link;
		tmp->link = p->link;
		p->link = tmp;
	}
}

int del()
{
	struct node *tmp;
	int item;
	if(isEmpty())
	{
		cout<<"\nQueue Underflow.";
		return 0;
	}
	tmp = front;
	item = tmp->info;
	front = front->link;
	free(tmp);
	return item;
}
	
int isEmpty()
{
	if(front==NULL)
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
		cout<<"\nQueue underflow.";
		return;
	}
	cout<<"\nQueue is : ";
	cout<<"\nPriority        Item ";
	while(p!=NULL)
	{
		cout<<p->priority<<"        "<<p->info;
		p=p->link;
	}
}   //End of display
