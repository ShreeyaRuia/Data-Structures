/*
insert
delete
traveral in level order
traversal in specific order
counting leaf nodes
counting internal nodes
hieght of tree
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("%d \t",temp->data);
inorder(temp->right);
}
}

void preorder(struct node *temp)
{
if(temp!=NULL)
{
printf("%d\t",temp->data);
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
printf("%d\t",temp->data);
}
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

int display(struct node *temp,int i)
{
if(temp==NULL)
return 0;
if(i==0)
printf("%d\t",temp->data);
else if(i>0)
{
display(temp->left,i-1);
display(temp->right,i-1);
}
}


void level(struct node *root)
{
int x,i;
struct node *temp=root;
int h=hieght(temp);
for(i=0;i<h;i++)
x=display(temp,i);
}




int traversal(struct node *root)
{
int n;
do
{
printf("\nEnter choice 1.Inorder 2.Preorder 3.postorder 4.level order 5.previous menu 6.exit\n");
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
case 4:level(temp);
       break;
case 5:return 0;
       break;
case 6:exit(0);
       break;
}
}while(n!=5);
}

int count(struct node *temp)
{
if(temp==0)
return 0;
if(temp->left==NULL && temp->right==NULL)
return 0;
else
return (count(temp->left) + count(temp->right) + 1);
}



int countl(struct node *temp)
{
if(temp==0)
return 0;
if(temp->left==NULL && temp->right==NULL)
return 1;
else
return (count(temp->left) + count(temp->right) );
}

struct node * insert(struct node *root,int val)
{
if(root==NULL)
{
struct node *new= (struct node *)malloc(sizeof(struct node ));
new->data=val;
new->left=NULL;
new->right=NULL;
root=new;
return root;
}
else
{
 if(val<(root->data))
  root->left=insert(root->left,val);
 else
 root->right=insert(root->right,val);
}
}

struct node* min(struct node* temp)
{
struct node* hold = temp; 
while (hold->left != NULL) 
hold= hold->left; 
return hold;
}

struct node *delete(struct node *root,int val)
{
if (root == NULL) 
return root; 
if (val < root->data) 
root->left = delete(root->left, val); 
else if (val > root->data) 
root->right = delete(root->right, val); 
else
{
if (root->left == NULL) 
{ 
struct node *temp = root->right; 
free(root); 
return temp; 
} 
else if (root->right == NULL) 
{
struct node *temp = root->left; 
free(root); 
return temp; 
}
struct node* temp = min(root->right);
root->data= temp->data;
root->right = delete(root->right, temp->data); 
} 
return root;  
}

void main()
{
struct node *root=(struct node*)malloc(sizeof(struct node));
root=NULL;
int n,x,y,t,z,val;
do
{
printf("\nEnter your choice 1.Insert 2. Delete 3.Traversal \n 4.Count internal nodes 5.hieght 6.count leaf node 7.Exit \n");
scanf("%d",&n);
switch(n)
{
case 1: printf("Enter value to be inserted");
        scanf("%d",&val);
        root=insert(root,val);
        break;
case 2: printf("Enter element to be deleted");
        scanf("%d",&val);
        root=delete(root,val);
        break;
case 3: t=traversal(root);
        break;
case 4: x=count(root);
        printf(" internal nodes are %d",x);
        break;     
case 5: y=hieght(root);
        printf(" hieght is %d",y);
        break;
case 6:z=countl(root);
       printf(" leaf nodes are %d",z);
        break;                 
case 7:exit(0);
        break;         
}
}while(n!=7);
} 
