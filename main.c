#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection();
void insertion();
void copying();
void displayin();
void displayout();
void bubble();
void shell();
void bucket();
long int a[100000],b[100000];
int s;
int main()
{
 long int i,j=0,m,p;
 int n,c,z=1;
 while(z!=0)
 {
printf("enter total number of elements \n");
scanf("%d",&s);
 printf("\nEnter your choice: \n 1.Decreasing order\n 2.Increasing order\n 3.nth element out of order\n 4.Random elements\n 5.Exit\n");
 scanf("%d",&n);
 switch(n)
 {
  case 1:
          for(i=s;i>0;i--)
          {
          a[j]=i;
          j++;
          }
          displayin();
          break;
  case 2: 
           for(i=0;i<s;i++)
           a[i]=i;
           displayin();
          break;
  case 3: 
           for(i=0;i<s;i++)
           a[i]=i;
           displayin();
           printf("\nEnter element to be replaced");
           scanf("%li",&m);
           printf("\nElement interval at which it has to be replaced:");
           scanf("%li",&p);
           for(i=p;i<s;(i=i+p))
           a[i]=m;
           displayin();
           break;
  case 4:
         {
           for(i=0;i<s;i++)
           a[i]=rand();
           displayin();
           break;
         }
  case 5:
         {
          z=0;
          exit(0);
         }
          }
printf("Enter choice for sorting: \n1.Bubble\n2.Insertion\n3.Selection\n4.Shell\n5.Bucket :\n");
scanf("%d",&c);
switch(c)
{
 case 1:
 {
  bubble();
  displayout();
  break;
 }
 case 2:
 {
  insertion();
  displayout();
  break;
 }
 case 3:
 {
  selection();
  displayout();
  break;
 }
 case 4:
 {
 shell();
 displayout();
 break;
 }
 case 5:
 {
 bucket();
 displayout();
 break;
 }
 }
 }
 return 0;
}

void copying()
{
    long int i;
for(i=0;i<100000;i++)
 b[i]=a[i];
}
void displayin()
{
 long int i;
 printf("Your array is:\n");
 for(i=0;i<s;i++)
 printf(" %li\t ",a[i]);

 }
void displayout()
{
 long int i;
 printf("Sorted array is:\n");
 for(i=0;i<s;i++)
 printf(" %li\t ",a[i]);
 printf("\n");
 }
 void bubble()
 {
  long int i,k,t;
  for(i=0;i<s-1;i++)
  {
  for(k=0;k<s-1-i;k++)
  {
   if(a[k]>a[k+1])
   {
    t=a[k];
    a[k]=a[k+1];
    a[k+1]=t;
   }
   }
   }
 }
 void insertion()
 {
  long int i,k,t;
  for(i=1;i<s;i++)
  {
   t=a[i];
   k=i-1;
   while((t<a[k])&&(k>=0))
   {
    a[k+1]=a[k];
    k=k-1;
   }
  a[k+1]=t;
  }
 }
 void selection()
 {
  int i,j,min,t;
  for(i=0;i<s-1;i++)
  {
   min=i;
   for(j=i+1;j<s;j++)
   {
    if(a[j]<a[min])
    min=j;
    }
    if(min!=i)
    t=a[i];
    a[i]=a[min];
    a[min]=t;
   }
  }
 void shell()
 {
     int gap,i,temp,j;
   for(gap=s/2;gap>0;gap=gap/2)
   {
    for(i=gap;i<s;i++)
    {
     for(j=i-gap;j>=0;j=j-gap)
     {
      if(a[j+gap]>= a[j])
      break;
      else {
        temp=a[j];
        a[j]=a[j+gap];
        a[j+gap]=temp;
      }
     }
    }
   }
 }
void bucket()

{
   int i, j;
   int count[10];
   for (i = 0; i < 10; i++)
   count[i] = 0;
   for (i = 0; i < 10; i++)
   (count[a[i]])++;
   for(i=0;i<10;i++)
   {
    for(j=count[i];(j<=count[i]&&j>0);j--)
    printf("%d",i);
 }
}
