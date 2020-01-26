#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};


int insertion(struct node **start)
{
int n,data1,pos,i;
do
{
struct node *temp=NULL; 
struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
printf("Enter data you want to insert");
scanf("%d",&data1);
printf("Enter the type of insertion you want\n");
printf("1.At begin 2.At end 3.In between randomly 4.Goto previous menu 5.Exit");
scanf("%d",&n);
switch(n)
{
case 1: new_node->data=data1;
        new_node->next=*start;
        *start=new_node;
break;
case 2: new_node->data=data1;
        temp=*start;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        new_node->next=NULL;
        temp->next=new_node; 
break;
case 3:new_node->data=data1; 
       printf("enter position you want to insert");
       scanf("%d",&pos);
       temp=*start;
       for(i=0;i<pos-1;i++)
       temp=temp->next;
       new_node->next=temp->next;
       temp->next=new_node;
break;
case 4: return 0;
break;
case 5: exit(0);
break;
}
}while(n!=4 || n!=5);
}

int deletion(struct node **start)
{
int n,data1,pos,i;
do
{
struct node *temp=*start; 
struct node *prev=*start; 
printf("Enter the type of deletion you want\n");
printf("1.At begin 2.At end 3.In between randomly 4.Goto previous menu 5.Exit");
scanf("%d",&n);
switch(n)
{
case 1: temp=*start;
        *start=temp->next;
        
break;
case 2: temp=*start;
        prev=*start;
        while((temp->next)->next!=NULL)
        {
         temp=temp->next;
        }
        prev=temp->next->next;
        temp->next=NULL;
        free(prev);                 
break;
case 3:printf("enter position you want to delete");
       scanf("%d",&pos);
       prev=*start;
       temp=*start;
       for(i=0;i<pos-2;i++)
       prev=prev->next;
       temp=prev->next;
       prev->next=temp->next;
       free(temp);
break;
case 4: return 0;
break;
case 5: exit(0);
break;
}
}while(n!=4 || n!=5);
}

void traversal(struct node *start)
{
struct node *temp;
temp=start;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}



int empty(struct node *start)
{
struct node *temp=start;
if(temp->next==NULL)
return 0;
else
return 1;
}

void sort(struct node *start)
{
int a;
struct node *temp=start;
struct node *prev=start;
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
if(prev->data>temp->data)
{
a=prev->data;
prev->data=temp->data;
temp->data=a;
}
}
}


int search(struct node *start)
{
int i,x,count=0;
struct node *temp;
temp=start;
printf("enter data to be searched");
scanf("%d",&x);
while(temp->next!=NULL && temp->data!=x)
{
count++;
temp=temp->next;
}
count++;
return count;
}


void merge(struct node **start,struct node **head)
{
struct node *temp=NULL;
struct node *hold=NULL;
hold=*start;
temp=*start;
while(temp->next!=NULL)
{
temp=(temp->next);
}
temp->next=*head;
} 

int reverse(struct node **start)
{
struct node *temp=NULL;
struct node *hold=NULL;
temp=*start;
while(temp->next!=NULL)
{
struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
new_node->data=temp->data;
new_node->next=hold;
hold=new_node;
temp=temp->next;
}
struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
new_node->data=temp->data;
new_node->next=hold;
hold=new_node;
*start=hold;
return 0;
}



void main()
{
int i=0,d=0,s=0,x=0,y=0,count=0,n=0;
struct node *start=NULL;
struct node *head=NULL;
do
{
struct node *temp=NULL;
printf("\nEnter your choice 1.INSERTION 2.DELETION 3.TRAVERSAL 4.CHECK EMPTY 5.SORTING 6.MERGING \n 7.SEARCHING   8.REVERSE 9.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: i=insertion(&start);
          traversal(start);
break;
case 2: d=deletion(&start);
break;
case 3: traversal(start);
break;
case 4: x=empty(start);
        if(x==0)
        printf("List is empty");
        else
        printf("List is not empty");
break;
case 5: temp=start;
        count=0;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        count++;
        }
        for(i=0;i<count;i++)
        sort(start);
        printf("Sorted array is\n");
        traversal(start);
break;
case 6: i=insertion(&head);
        printf("\nfirst list is\n");
        traversal(start);
        printf("\nSecond list is\n");
        traversal(head);
        merge(&start,&head);
        printf("\nsorted list is\n");
        traversal(start);
break;
case 7: temp=start;
        count=1;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        count++;
        }
        s=search(start);
        if(s>=0 && s<count)
        printf("\n element is at %d position",(s));
        else
        printf("\nelement not found");
break;
case 8: y=reverse(&start);
        traversal(start);
break;
case 9:exit(0);
break;
default : printf("invalid \n");
}
}while(n!=9);
}











