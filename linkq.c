#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node1
{
	int data1;
	struct node1 *next1;
};



int push(struct node **start)
{
    int data2;
    struct node *temp=NULL; 
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert"); 
    scanf("%d",&data2);
    new_node->data=data2;
    new_node->next=*start;
    *start=new_node;
    return 0;
}

int pop(struct node **start)
{
    struct node *temp=*start;
    if(temp==NULL)
    printf("Deletion not possible");
    else
{ 
    temp=*start;
    *start=temp->next;
    free(temp);
}
    return 0;
}

int check(struct node *start)
{
	if(start==NULL)
		printf("Stack is empty\n");
	else 
		printf("stack is not empty\n");
	return 0;
}

void traversals(struct node *start)
{
struct node *temp;
temp=start;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}
  
int stack()
{
	int n,x,y,z;
	struct node *start=NULL;
	do
	{
	printf("\nEnter your choice 1.Insertion 2.Deletion 3.Check empty 4.Traversal 5.Go to previous menu 6.Exit");
	scanf("%d",&n);
	switch(n)
	{
		case 1: x=push(&start);
		break;
		case 2: y=pop(&start);
		break;
		case 3: z=check(start);
		break;
                case 4:traversals(start);
                break;
		case 5:return 0;
		break;
		case 6 :exit(0);
		break;
		default: printf("Invalid input\n");
	}
    }while(n!=5 || n!=4);
}




int insert(struct node **front,struct node **rear)
{
    int data2;
    struct node *temp=*rear;
    struct node *hold=*front;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert"); 
    scanf("%d",&data2);
	if(*rear==NULL || *front==NULL)
	{
                *rear=NULL;
                *front=NULL;
                new_node->data=data2;
                new_node->next=NULL;
		*rear=new_node;
                *front=new_node;
                
	}
    else
    {
        temp=*rear;
    	new_node->data=data2;
        new_node->next=NULL;
        temp->next=new_node; 
        *rear=new_node;
    }
    return 0;
}

int delete(struct node **front,struct node **rear)
{
	struct node *temp;
	if(*front==NULL)
		printf("queue is empty no deletion possible\n");
	else
	{
	temp=*front;
        *front=temp->next;
        free(temp);
        }
    return 0;
}

int checkq(struct node *front)
{
	if(front==NULL)
		printf("Queue is empty\n");
	else
		printf("Queue is not empty\n");
}

void traversalq(struct node *front,struct node *rear)
{
struct node *temp;
temp=front;
while(temp!=rear->next)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}

int queue()
{
	int n,x,y,z;
	struct node *front=NULL;
	struct node *rear=NULL;
	do
	{
	printf("\nEnter your choice 1.Insertion 2.Deletion 3.Check empty 4.Traversal 5.Go to previous menu      6.Exit");
	scanf("%d",&n);
	switch(n)
	{
		case 1: x=insert(&front,&rear);
		break;
		case 2: y=delete(&front,&rear);
		break;
		case 3: z=checkq(front);
		break;
                case 4: traversals(front);
                break;
		case 5:return 0;
		break;
		case 6 :exit(0);
		break;
		default: printf("Invalid input\n");
	}
    }while(n!=5 || n!=4);

}

void main()
{
int n,y,x1;
do
{
printf("Enter your choice \n 1.Stack using link list 2.Queue using link list");
scanf("%d",&n);
switch(n)
{
case 1:x1=stack();
break;
case 2:y=queue();
break;
case 3:exit(0);
break;
default : printf("Invalid choice");
}
}while(n!=3);
}


