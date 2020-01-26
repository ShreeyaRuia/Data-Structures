#include<stdio.h>
#include<stdlib.h>
int s=10,a[20],i;
void menu(int );
void insert();
void del();
void searching();
void traversing();
void merge();
void main()
{
int n;
i=-1;
printf("enter elements \n");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
a[i]=-1;
do
{
printf("select from the menu \n 1.INSERTION \n 2.DELETION \n 3.SEARCHING \n 4.TRAVERSING \n 5.MERGE SORT 6. EXIT \n");
scanf("%d",&n);
menu(n);
}while(n!=6);
}
void menu(int n)
{
switch(n)
{
case 1: if(i<=20)
        {
         printf("inertion possible \n");
          insert();
        }
        else
        printf("insertion not possible \n");
break;
case 2: if(i<=20 && i!=-1)
        {
        printf("deletion possible \n");
        del();
        }
        else printf("deletion not possible \n");
break;
case 3: searching();
break;
case 4: traversing();
break;
case 5: merge();
break;
case 6:exit(0);
break;
default : printf("invalid \n");
}
}
void insert()
{
int i=0,pos,val;
printf("enter pos and value \n");
scanf("%d%d",&pos,&val);
for(i=s;i>=pos;i--)
{
a[i]=a[i-1];
}
a[pos]=val;
s++;
printf("elements are \n");
for(i=0;i<s;i++)
printf("%d \t",a[i]);
printf("\n");
}
void del()
{
int i,pos;
printf("enter position to be deleted \n");
scanf("%d",&pos);
for(i=pos;i<s;i++)
{
a[i]=a[i+1];
}
printf("elements are \n");
s=s-1;
for(i=0;i<s;i++)
printf("%d \t",a[i]);
printf("\n");
}
void searching()
{
int i,se,k=0;
printf("enter element to be searched \n ");
scanf("%d",&se);
for(i=0;i<10;i++)
{
if(a[i]==se)
k=1;
}
if(k==1)
printf("element found \n");
else
printf("element not found \n");
}
void traversing()
{
int i;
printf("elements are \n");
for(i=0;i<s;i++)
printf("%d \t",a[i]);
printf("\n");
}

void merge()
{
int b[10],c[20],temp,i,j,k;
for(i=0;i<10;i++)
{
for(j=0;j<9;j++)
{
if (a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("enter second array elements \n");
for(i=0;i<10;i++)
{
scanf("%d",&b[i]);
}
for(j=0;j<10;j++)
{
for(i=0;i<9;i++)
{
if (b[i]>b[i+1])
{
temp=b[i];
b[i]=b[i+1];
b[i+1]=temp;
}
}
}
i=0,j=0,k=0;
while(i<10 && j<10)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
k++;
}
else
{
c[k]=b[j];
k++;
j++;
}
}
if(i>=10)
{
while(j<10)
{
c[k]=b[j];
j++;
k++;
}
}
if(j>=10)
{
while(i<10)
{
c[k]=a[i];
k++;
i++;
}
}
printf("new array is \n");
for(i=0;i<20;i++)
printf("%d \t",c[i]);
}









