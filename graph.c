#include<stdio.h>
#include<stdlib.h>
int visited[40]={0};
int que[100];
int front=-1,rear=-1;
int maxq=37;

struct node
{
int data;
struct node *next;
};
struct node *start[15]={NULL};

void dfs(int a[15][15],int x,int num)
{
int w;
printf("%d\n",x);
visited[x]=1;
for(w=0;w<num;w++)
{
if(visited[w]==0 && a[x][w]==1)
dfs(a,w,num);
}
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

void insert(int data)
{
int x,y;
 x=fullq();
 y=emptyq();
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
front++;
}


void bfs(int a[15][15],int x,int num)
{
int w,v;
insert(x);
visited[x]=1;
printf("%d",x);
while(front<=rear)
{
v=que[front];
delete();
for(w=0;w<num;w++)
{
if(visited[w]==0 && a[v][w]==1)
{
insert(w);
visited[w]=1;
printf("%d",w);
}
}
}
}



int array()
{
int a[15][15];
int i,j,n,num;
printf("Enter total vertices");
scanf("%d",&num);
printf("Enter elements");
for(i=0;i<num;i++)
{
for(j=0;j<num;j++)
scanf("%d",&a[i][j]);
}
do
{
printf("Enter your choice 1.Depth first search 2.Breadth for search 3.Previous menu 4.Exit");
scanf("%d",&n);
switch(n)
{
case 1:for(i=0;i<40;i++)
       visited[i]=0;
       dfs(a,0,num);
break;
case 2:for(i=0;i<40;i++)
       visited[i]=0;
       bfs(a,0,num);
break;
case 3:return 0;
break;
case 4:exit(0);
break;
}
}while(n!=4);
}

int insertion(int i)
{
int n=0,data1;
struct node *temp=NULL; 
struct node* new_node = (struct node*)malloc(sizeof(struct node));
printf("Enter data you want to insert");
scanf("%d",&data1);
new_node->data=data1;
temp=start[i];
if(temp==NULL)
{
new_node->next=NULL;
start[i]=new_node;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
new_node->next=NULL;
temp->next=new_node;
}
}

void dfsl(int i)
{
struct node *temp;
printf("%d\n",i);
temp=start[i];
visited[i]=1;
while(temp!=NULL)
{
i=temp->data;
if(visited[i]==0)
dfsl(i);
temp=temp->next;
}
}

void traversal(int i)
{
struct node *temp;
temp=start[i];
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}



void bfsl(int i,int num)
{
int w,v;
insert(i);
visited[i]=1;
printf("%d",i);
while(front<=rear)
{
v=que[front];
delete();
for(w=0;w<num;w++)
{
if(visited[w]==0)
{
insert(w);
visited[w]=1;
printf("%d",w);
}
}
}
}

int list()
{
int i,x,n,num,s,j;
printf("Enter number of vertices");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("Enter links for %d\n",i);
printf("enter number of elements");
scanf("%d",&s);
for(j=0;j<s;j++)
x=insertion(i);
}
for(i=0;i<num;i++)
{ 
traversal(i);
}
do
{
printf("\nEnter your choice 1.Depth first search 2.Breadth for search 3.Previous menu 4.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1:for(i=0;i<40;i++)
       visited[i]=0;
       dfsl(0);
break;
case 2:for(i=0;i<40;i++)
       visited[i]=0;
       bfsl(0,num);
break;
case 3:return 0;
break;
case 4:exit(0);
break;
}
}while(n!=4);
}





void main()
{
int n,y,x;
do
{
printf("Enter your choice 1.Matrix 2.List 3.Exit");
scanf("%d",&n);
switch(n)
{
case 1:x=array();
break;
case 2:y=list();
break;
case 3:exit(0);
break;
}
}while(n!=3);
}



