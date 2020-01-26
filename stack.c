#include<stdio.h>
#include<stdlib.h>
int maxs,maxq;
int stack[100];
int que[100];
int front=-1,rear=-1;
int top=-1;



int fulls()
{
 if (top==maxs-1)
 return 0;
 else
 return 1;
}
int emptys()
{
 if (top==-1)
 return 0;
 else
 return 1;
}
void push()
{
 int data,x,y;
 x=fulls();
 y=emptys();
 printf("enter the data you want to insert\n");
 scanf("%d",&data);
 if (x==0)
 printf("insertion cannot be done stack is full\n");
 else if(y==0 || y==1)
 {
  top++;
  stack[top]=data;
 }
}
 
  
void pop()
{
 int y;
 y=emptys();
 if(y==0)
 printf("deletion cannot be done stack is empty\n");
 else
 top--;
}

void traversals()
{
int i;
for(i=0;i<=top;i++)
printf("%d\t",stack[i]);
}

int stacks()
{
int i,n;
printf("enter the size of stack\n");
scanf("%d",&maxs);
do
{
printf("\nEnter your choice \n 1.INSERTION \n 2.DELETION \n 3.TRAVERSAL\n 4.Return to previous menu \n5.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: push();
        break;
case 2: pop();
        break;
case 3: traversals();
        break;
case 4: return 0;
        break;
case 5:exit(0);
       break;
default : printf("invalid input");
          break;
}
}while(n!=4);
}


int fullq()
{
if(rear==maxq-1)
return 0;
else 
return 1;
}

int emptyq()
{
if(rear==-1 || front==-1)
return 0;
else
return 1;
}

void insert()
{
int data,x,y;
 x=fullq();
 y=emptyq();
 printf("enter the data you want to insert\n");
 scanf("%d",&data);
 if(x==0)
 printf("insertion cannot take place queue is full\n");
 else if(y==0)
 {
 front=0;
 rear=0;
 que[rear]=data;
 }
 else if(y==1)
 {
 rear++;
 que[rear]=data;
 }
}

void traversalq()
{
int i;
for(i=front;i<=rear;i++)
printf("%d\t",que[i]);
}

void delete()
{
int y,x;
 x=fullq();
 y=emptyq();
 if(y==0)
 printf("stack is empty no deletion\n");
 else if(front<rear)
 front++;
 else
 { 
 front=-1;
 rear=-1;
 }
}

int queue()
{
int i,n;
printf("enter the size of queue\n");
scanf("%d",&maxq);
do
{
printf("\nEnter your choice \n 1.INSERTION \n 2.DELETION \n 3.TRAVERSAL\n 4.Return to previous menu \n 5.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: insert();
        break;
case 2: delete();
        break;
case 3: traversalq();
        break;
case 4: return 0;
        break;
case 5:exit(0);
       break;
default : printf("invalid input \n");
          break;
}
}while(n!=4);
}
 
void main()
{
int j,i,n;
do
{
printf("\n enter your choice \n 1.Stack \n 2.Queue \n 3.Exit \n");
scanf("%d",&n);
switch(n)
{
case 1:i=stacks();
       break;
case 2:j=queue();
       break;
case 3:exit(0);
       break;
default : printf("invalid input");
          break;
}
}while(n!=3 && (i==0 || j==0 ));
}








