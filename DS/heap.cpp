#include<stdio.h>
#include<stdlib.h>

#define MAX_VAL 9999   // All values in the heap must be less than this value.

void display(int arr[], int hsize);
void insert(int num, int arr[], int *p_hsize);
int del_root(int arr[], int *p_hsize);
void restoreUp(int arr[], int loc);
void restoreDown(int arr[], int i, int size);
void buildHeap(int arr[], int size);

main()
{
	int arr[100];
	int hsize = 0;
	int i, choice, num;
	arr[0] = MAX_VAL;
	while(1)
	{
		printf("\n1. Insert");
		printf("\n2. Delete Root");
		printf("\n3. Display");
		printf("\n4. Build Heap");
		printf("\n5. Exit");
		printf("\n6. Enter your choice :- ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the numbe you want to insert : ");
				scanf("%d", &num);
				insert(num, arr, &hsize);
				break;
			
			case 2:
				if(hsize == 0)
					printf("\nHeap is empty");
				else
				{
					num = del_root(arr, &hsize);
					printf("\nMaximum element is %d", num);
				}
				break;
			case 3:
				display(arr, hsize);
				break;
			case 4:
				printf("\nEnter the size of the array : ");
				scanf("%d", &hsize);
				printf("\nEnter array : ");
				for(i=1;i<=hsize;i++)
					scanf("%d", &arr[i]);
				buildHeap(arr, hsize);
				break;

			case 5:
				exit(1);
			default:
				printf("\nPlease select a valid option");
		}
	}
}

void display(int arr[], int hsize)
{
	int i;
	if(hsize == 0)
	{
		printf("\nHeap is empty.");
		return;
	}
	for(i=1;i<=hsize;i++)
		printf("%d", arr[i]);
	printf("\n");
	printf("\nNumber of elements in the heap is : %d", hsize);
}

void insert(int num, int arr[], int *p_hsize)
{
	(*p_hsize)++;
	arr[*p_hsize] = num;
	restoreUp(arr, *p_hsize);
}

void restoreUp(int arr[], int i)
{
	int k = arr[i];
	int par = i/2;
	while(arr[par] < k)
	{
		arr[i] = arr[par];
		i = par;
		par = i/2;
	}
	arr[i] = k;
}

int del_root(int arr[], int *p_hsize)
{
	int max = arr[1];
	arr[1] = arr[*p_hsize];
	(*p_hsize)--;
	restoreDown(arr, 1, *p_hsize);
	return max;
}

void restoreDown(int arr[], int i, int hsize)
{
	int lchild = 2*i, rchild = lchild + 1;
	int num = arr[i];
	
	while(rchild <= hsize)
	{
		if(num>=arr[lchild] && num>=arr[rchild])	
		{
			arr[i] = num;
			return;
		}
		else if(arr[lchild] > arr[rchild])
		{
			arr[i] = arr[lchild];
			return;
		}
		else
		{
			arr[i] = arr[rchild];
			i = lchild;
		}
		lchild = 2*i;
		rchild = lchild + 1;
	}
	if(lchild == hsize && num < arr[lchild])
	{	
		arr[i] = arr[lchild];
		i = lchild;
	}
	arr[i] = num;
}

void buildHeap(int arr[], int size)
{
	int i;
	for(i=size/2;i>=1;i--)
		restoreDown(arr, i, size);
}		
