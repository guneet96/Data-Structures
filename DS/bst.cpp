// guneet96
// Recursive Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
	
struct node *search(struct node *p, int skey);
struct node *insert(struct node *p, int ikey);
struct node *del(struct node *p, int dkey);
struct node *Max(struct node *p);
struct node *Min(struct node *p);

void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);

int height(struct node *p);

main()
{
	struct node *root = NULL, *p;
	int choice, k;
	while(1)
        {
                printf("\n1. Search");
                printf("\n2. Insert");
                printf("\n3. Delete");
                printf("\n4. Preorder traversal");
                printf("\n5. Inorder traversal");
		printf("\n6. Postorder travarsal");
		printf("\n7. Height of tree");
		printf("\n8. Find minimum and maximum");
		printf("\n9. Quit");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1:
                                printf("\nEnter the key to be searched : ");
                                scanf("%d", &k);
                                p = search(root, k);
                                break;

                        case 2:
				printf("\nEnter the key to be inserted : ");
                                scanf("%d", &k);
                                p = insert(root, k);
                                break;

                        case 3:
                                printf("Enter the key to be deleted");
				scanf("%d", &k);
				root = del(root, k);
                                break;

                        case 4:
                                preorder(root);
				break;

                        case 5:
                                inorder(root);
				break;
			
			case 6:
				postorder(root);
				break;
			
			case 7:
				printf("Height of tree is %d\n", height(root));
				break;
			
			case 8:
				p = Min(root);
				if(p!=NULL)
					printf("\nMin key in the tree is %d", p->info);
				p = Max(root);
				if(p!=NULL)
					printf("\nMax key is the tree is %d", p->info);
				break;
			
			case 9:
				exit(0);
			default:
				printf("Please select a valid choice.");
		} // End of switch
	} // End of while loop
} // End of main function

struct node *search(struct node *p, int skey)
{
	if(p == NULL)
	{
		prinftf("\nKey not found.");
		return NULL;
	}
	else if(skey < p->info)
		return search(p->lchild, skey);
	else if(skey > p->info)
		return search(p->rchild, skey);
	else 
		return p;
}

struct node *insert(struct node *root, int ikey)
{
	if(p == NULL)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->info = ikey;
		p->lchild = NULL:
		p->rchild = NULL;
	}
	else if(ikey < p->info)
		p->lchild = insert(p->lchild, ikey);
	else if(ikey > p->info)
		p->rchild = insert(p->rchild, ikey);
	else 
		printf("\nDuplicate key.");
	return p;
}

struct node *del(struct node *p, int dkey)
{
	struct node *temp, *succ;
	if(p == NULL)
	{
		printf("\nKey not found");
		return(p);
	}
	if(dkey < p->info)
		p->lchild = del(p->lchild, dkey);
	else if(dkey > p->rchild)
		p->rchild = del(p->rchild, dkey);
	else
 	{
		if(p->lchild!=NULL && p->rchild!=NULL)
		{
			succ = p->rchild;
			while(succ->lchild)
				succ = succ->lcchild;
			p->info = succ->info;
			p->rchild = del(p->rchild, succ->info);
		}
		else
		{
			temp = p;
			if(p->lchild!=NULL)
				p = p->lchild;
			else if(p->rchild!=NULL)
				p = p->rchild;
			else
				p = NULL;
			free(temp);
		}
	}
}

void preorder(struct node *p)
{
	if(p == NULL)
		return;
	printf("%d", p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}

void inorder(struct node *p)
{
	if(p == NULL)
		return;
	inorder(p->lchild);
	printf("%d", p->info);
	inorder(p->rchild);
}

void postorder(struct node *p)
{
	if(p == NULL)
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d", p->info);
}

int height(struct node *p)
{
	int h_l, h_r;
	if(p == NULL)
		return 0;
	h_l = height(p->lchild);
	h_r = height(p->rchild);
	if(h_l > h_r)
		return 1+h_l;
	else
		return 1+h_r;
}

struct node *Min(struct node *p)
{
	if(p == NULL)
		return NULL:
	else if(p->lchild == NULL)
		return p;
	else
		return Min(p->lchild);
}

struct node *Max(struct node *p)
{
        if(p == NULL)
                return NULL:
        else if(p->rchild == NULL)
                return p;
        else
                return Max(p->rchild);
}



