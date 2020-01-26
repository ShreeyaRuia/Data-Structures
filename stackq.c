#include<stdio.h>
#include<stdlib.h>
int maxs,maxq,maxc;
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
int i,n,x,y;
printf("enter the size of stack\n");
scanf("%d",&maxs);
for(i=0;i<=maxs+1;i++)
stack[i]=0;
top=-1;
do
{
printf("\nEnter your choice \t 1.INSERTION \t 2.DELETION \t 3.TRAVERSAL\t 4.CHECK EMPTY OR FULL\t 5.previous menu \t6.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: push();
        break;
case 2: pop();
        break;
case 3: traversals();
        break;
case 4:x=fulls();
       y=emptys();
       if(x==0)
       printf(" stack is full\n");
       else if(x==1)
       printf(" stack is not full\n");
       else if(y==0)
       printf(" stack is empty\n");
       else if(y==1)
       printf("stack is not empty\n");
       break;
case 5: return 0;
        break;
case 6:exit(0);
       break;
default : printf("invalid input");
          break;
}
}while(n!=6);
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
int i,x,y,n;
printf("enter the size of queue\n");
scanf("%d",&maxq);
for(i=0;i<=maxq+1;i++)
que[i]=0;
front=-1;
rear=-1;
do
{
printf("\nEnter your choice \t 1.INSERTION \t 2.DELETION \t 3.TRAVERSAL\t 4. CHECK EMPTY OR FULL\t 5.previous menu \t 6.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: insert();
        break;
case 2: delete();
        break;
case 3: traversalq();
        break;
case 4:x=fullq();
       y=emptyq();
       if(x==0)
       printf(" queue is full\n");
       else if(x==1)
       printf(" queue is not full\n");
       else if(y==0)
       printf(" queue is empty\n");
       else if(y==1)
       printf("queue is not empty\n");
       break;        
case 5: return 0;
        break;
case 6:exit(0);
       break;
default : printf("invalid input \n");
          break;
}
}while(n!=6);
}

int fullc()
{
if(front==-1 && rear==-1)
printf("queue is empty");
if(rear<front && rear!=front-1)
printf("queue is  not empty not full");
if(front<rear && rear!=maxc-1)
printf("queue is not empty not full");
if(rear==front-1)
printf("queue is full");
if(front=0 && rear==maxc-1)
printf("queue is full");
}

void insertc()
{
int data,x,y;
 printf("enter the data you want to insert\n");
 scanf("%d",&data);
 if(rear==maxc-1 && front==0)
 printf("insertion cannot take place queue is full");
 else if(rear==maxc-1 && front!=0 )
 {
 rear=0;
 que[rear]=data;
 }
 else if(front!=0 && rear<front && rear!=front-1)
 {
 rear++;
 que[rear]=data;
 }
 else if(rear==-1 && front==-1)
 {
 front=0;
 rear=0;
 que[rear]=data;
 }
 else if(front<=rear && rear<maxc-1)
 {
 rear++;
 que[rear]=data;
 }
 else if(rear==front-1)
 printf("insertion cannot take place queue is full");
}

void deletec()
{
 if(front==-1 && rear==-1)
 printf("stack is empty no deletion\n");
 else if((rear>front || rear<front) && front!=maxc-1)
 front++;
 else if(front==maxc-1)
 front=0;
else
 { 
 front=-1;
 rear=-1;
 }
}

int traversalc()
{
int i;
for(i=front;i<maxc;i++)
printf("%d\t",que[i]);
for(i=0;i<=rear;i++)
printf("%d\t",que[i]);
}

int circular()
{
int i,n;
printf("enter the size of circular queue\n");
scanf("%d",&maxc);
for(i=0;i<=maxc+1;i++)
que[i]=0;
front=-1;
rear=-1;
do
{
printf("\nEnter your choice \t 1.INSERTION \t 2.DELETION \t 3.TRAVERSAL\t 4.CHECK FULL OR EMPTY \t 5.PREVIOUS MENU \t 6.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1: insertc();
        break;
case 2: deletec();
        break;
case 3: if(front<rear)
        traversalq();
        else
        traversalc();
        break;
case 4 :fullc();
        break;
case 5: return 0;
        break;
case 6:exit(0);
        break;
default : printf("invalid input \n");
          break;
}
}while(n!=6);
}



 
void main()
{
int j,i,q,n;
do
{
printf("\n enter your choice \t 1.Stack \t 2.Queue \t 3.Circular queue \t 4.Exit \n");
scanf("%d",&n);
switch(n)
{
case 1:i=stacks();
       break;
case 2:j=queue();
       break;
case 3:q=circular();
       break;       
case 4:exit(0);
       break;
default : printf("invalid input\n");
          break;
}
}while(n!=4 );
}








