#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};


void create(struct node **start)
{
int data1;
struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
printf("enter the data");
scanf("%d",&data1);
new_node->data=data1;
new_node->next=*start;
*start=new_node;
}

int search(struct node *start,int n)
{
int i,x,count=0;
struct node *head;
head=start;
printf("enter data to be searched");
scanf("%d",&x);
while(head!=NULL && head->data!=x)
{
count++;
head=head->next;
}
return count;
}

void traversal(struct node *start)
{
struct node *head;
head=start;
while(head!=NULL)
{
printf("%d\t",head->data);
head=head->next;
}
}

void main()
{
int i,n,x,data,count=0;
struct node *start=NULL;
struct node *temp=NULL;
printf("Enter the number of elements you want");
scanf("%d",&n);
for(i=0;i<n;i++)
create(&start);
traversal(start);
temp=start;
while(temp->next!=NULL)
{
count++;
temp=temp->next;
}
x=search(start,n);
if(x>=0 && x<count)
printf("\n%d",x+1);
else
printf("\nelement not found");
}









