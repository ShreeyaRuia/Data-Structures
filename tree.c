/*
inorder
preorder
postorder
hieght of tree
counting internal nodes
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};

struct node * create(int val)
{
 struct node *new= (struct node *)malloc(sizeof(struct node ));
new->data=val;
new->left=NULL;
new->right=NULL;
return new;
}

void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%d ->",temp->data);
inorder(temp->right);
}
}

void preorder(struct node *temp)
{
if(temp!=NULL)
{
printf("%d -",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}

void postorder(struct node *temp)
{
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%d ->",temp->data);
}
}
int count(struct node *temp)
{
if(temp==NULL)
return 0;
if(temp->left==NULL && temp->right==NULL)
return 0;
else
return (count(temp->left) + count(temp->right) + 1);
}

int hieght(struct node *temp)
{
int ls;
int rs;
if (temp==NULL)
return 0;
else
{
 ls=hieght(temp->left);
  rs=hieght(temp->right);
}
if(ls>rs)
return ls+1;
else 
return rs+1;
}


int link(struct node *root)
{
int n,x,y;
do
{
printf("\nEnter your choice 1.Inorder 2. Preorder 3.postorder \n 4.Count number nodes 5.hieght 6.Previous menu 7.Exit \n");
scanf("%d",&n);
struct node *temp=root;
switch(n)
{
case 1: inorder(temp);
        break;
case 2: preorder(temp);
        break;
case 3: postorder(temp);
        break;
case 4: x=count(temp);
        printf(" internal nodes are %d",x);
        break;     
case 5: y=hieght(temp);
        printf(" hieght is %d",y);
        break;
case 6:return 0;
       break;              
case 7:exit(0);
        break;         
}
}while(n!=7);
} 



struct node *createa(int tree[],int n)
{
struct node *temp=NULL;
if(tree[n]!=-1)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->left=createa(tree,2*n);
temp->data=tree[n];
temp->right=createa(tree,2*n+1);
}
return temp;
}

int array()
{
int tree[100]={0};
int num,i=0,n,x,y,j=0;
struct node *root2= (struct node*)malloc(sizeof(struct node));
printf("enter the number of elements in array\n");
scanf("%d",&num);
printf("Enter array elements\n");
for(i=1;i<=num;i++)
{
scanf("%d",&tree[i]);
}
for(j=i;j<100;j++)
tree[j]=-1;
printf("Array is");
for(i=1;i<=num;i++)
printf("%d\t",tree[i]);
root2=createa(tree,1);
do
{
printf("\nEnter your choice 1.Inorder 2. Preorder 3.postorder \n 4.Count number nodes 5.hieght 6.Previous menu 7.Exit \n");
scanf("%d",&n);
switch(n)
{
case 1: inorder(root2);
        break;
case 2: preorder(root2);
        break;
case 3: postorder(root2);
        break;
case 4: x=count(root2);
        printf(" internal nodes are %d",x);
        break;     
case 5: y=hieght(root2);
        printf(" hieght is %d",y);
        break;
case 6:return 0;
       break;              
case 7:exit(0);
        break;         
}
}while(n!=7);
}


void main()
{
int n,num;
struct node *root= (struct node*)malloc(sizeof(struct node));
do
{
printf(" Enter choice of creation : ----1.LINK LIST 2.ARRAY 3.EXIT");
scanf("%d",&n);
switch(n)
{
case 1: 
        root->left=NULL;
        root->right=NULL;
        root->data=8;
        root->left=create(7);
        (root->left)->right=create(4);
        root->right=create(5);
        (root->right)->left=create(3);
        (root->right)->right=create(9);
        num=link(root);
        break;
case 2:array();
       break;
case 3: exit(0);
       break;  
}
}while(n!=3);
}      
        
        
        
        
        
        
        
        
        
        
        
        
