#include<stdio.h>
#include<stdlib.h>
int a[200],b[200],f1=-1,f2=-1,r1=-1,r2=-1,s,max,t1=-1,t2=-1,maxq;

int full()
{
	if(r1==-1 && f1==-1 || r1==f1)
		return 0;
	else if(r1==max-1)
		return 1;
	else 
        	return 2;
}

void delete()
{
int i;
f2=0;
r2=-1;
if(r1==-1 && f1==-1)
printf("empty stack no element deleted\n");
else if(r1<max && f1<r1) 
{
for(i=r1;i>=f1;i--)
{
r2++;
b[r2]=a[i];
}
f2++;
r1=-1;
f1=0;
for(i=r2;i>=f2;i--)
{
r1++;
a[r1]=b[i];
}
}
else if(r1==f1)
{
r1=-1;
f1=-1;
printf("after deletion no element left\n");
}
}


void insert()
{
int data,i;
printf("eneter data to be inserted\n");
scanf("%d",&data);
if(r1==-1 && f1==-1)
{
r1=0;
f1=0;
a[r1]=data;
}
else if(r1<max)
{
r1++;
a[r1]=data;
}
else if(r1==max-1)
printf("stack is full no element can be inserted\n");
}

void traversal()
{
int i;
for(i=0;i<=r1;i++)
printf("%d\t",a[i]);
printf("\n");
}

int stack()
{
int n,x;
printf("enter max size of stack\n");
scanf("%d",&max);
do
{
printf("\nenter your choice\n 1.Insertion\t 2.Deletion\t 3.full or empty \t4.traversal\t5.return to previous menu\t 6.exit\n");
scanf("%d",&n);
switch(n)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: x=full();
        if(x==0)
        printf("Stack is empty\n");
        if(x==1)
        	printf("stack is full\n");
        if(x==2)
         printf("stack is neither full nor empty\n"); 
break;
case 4: traversal();
break;
case 5:return 0;
break;
case 6: exit(0);
break;
default: printf("invalid input");
}
}while(n!=5);
}

int fullq()
{
if(t1==maxq-1)
return 1;
if(t1==-1)
return 0;
else
return 2;
}

void push()
{
int data;
printf("Enter data to be inserted");
scanf("%d",&data);
if(t1==-1)
{
t1=0;
a[t1]=data;
}
else if(t1<maxq-1)
{
t1++;
a[t1]=data;
}
else if(t1==maxq-1)
printf("Queue is full insertion not possible");
}

void pop()
{
int i;
t2=-1;
if(t1==-1)
printf("queue is empty deletion not possible");
else if(t1!=-1 && t1<=maxq-1)
{
for(i=t1;i>=0;i--)
{
t2++;
b[t2]=a[i];
}
t2--;
t1=-1;
for(i=t2;i>=0;i--)
{
t1++;
a[t1]=b[i];
}
}
}

void traversalq()
{
int i;
if(t1!=-1)
{
for(i=0;i<=t1;i++)
printf("%d",a[i]);
}
else
printf("Empty Queue");
}


int queue()
{
int n,x;
printf("enter max size of stack\n");
scanf("%d",&maxq);
do
{
printf("\nenter your choice\n 1.Insertion\t 2.Deletion\t 3.full or empty \t4.traversal\t5.Return to previous menu\t 6.exit \n");
scanf("%d",&n);
switch(n)
{
case 1: push();
break;
case 2: pop();
break;
case 3: x=fullq();
        if(x==0)
        printf("queue is empty\n");
        if(x==1)
        	printf("queue is full\n");
        if(x==2)
         printf("queue is neither full nor empty\n"); 
break;
case 4: traversalq();
break;
case 5:return 0;
break;
case 6: exit(0);
break;
default: printf("invalid input");
}
}while(n!=5);
}



void main()
{
int x,y,n;
do
{
printf("\nEnter your choice \n 1.Stack using queue \n2.Queue using stack\n 3.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1: x=stack();
break;
case 2: y=queue();
break;
case 3: exit(0);
break;
default: printf("invalid input");
}
}while(n!=3 && (x==0 || y==0));
}



