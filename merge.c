#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t st,et;
int s=0;
int a[100000];
int k[100000];
void merge(int a[],int beg,int mid,int end);
void mergesort(int a[],int beg,int end);
void merges(int a,int beg,int end);
void list();
void display();
void cal();

void mergesort(int a[],int beg,int end)
{
 int mid;
 if(beg<end)
 {
 mid=(beg+end)/2;
 mergesort(a,beg,mid);
 mergesort(a,mid+1,end);
 merge( a, beg, mid, end);
 }
}



void merge(int a[],int beg,int mid,int end)
{
int i=beg,j=mid+1,m=beg,l=beg;
while(i<=mid && j<=end)
{
if(a[i]<=a[j])
{
k[m]=a[i];
m++;
i++;
}
else
{
k[m]=a[j];
m++;
j++;
}
}
while(j<=end)
{
k[m]=a[j];
m++;
j++;
}
while(i<=mid)
{
k[m]=a[i];
m++;
i++;
}
for(l=beg;l<m;l++)
{
a[l]=k[l];
}
}

void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}
int partition(int a[],int f,int l)
{
int i=0,j=0;
int pivot=a[l];
i=f-1;
for(j=f;j<=l-1;j++)
{
if(a[j]<=pivot)
{
i++;
swap(&a[i],&a[j]);
}
}
swap(&a[i+1],&a[l]);
return (i+1);
}

void quick(int a[],int f,int l)
{
int x;
if(f<l)
{
x=partition(a,f,l);
quick(a,f,x-1);
quick(a,x+1,l);
}
}

int partitionf(int a[],int f,int l)
{
int i=0,j=0;
int pivot=a[f];
i=l+1;
for(j=l;j>=f+1;j--)
{
if(a[j]>=pivot)
{
i--;
swap(&a[i],&a[j]);
}
}
swap(&a[i-1],&a[f]);
return (i-1);
}

void quickf(int a[],int f,int l)
{
int x;
if(f<l)
{
x=partitionf(a,f,l);
quick(a,f,x-1);
quick(a,x+1,l);
}
}





void main()
{
int i,l,n,size;
do
{
printf("enter the size of array\n");
scanf("%d",&s);
list();
printf("Choose \n 1.mergesort \n 2. quicksort(last pivot)\n 3.quicksort(first pivot) 3.exit\n");
scanf("%d",&l);
switch(l)
{
case 1: st=clock(); mergesort(a,0,s-1); et=clock(); display(); printf("time requied for mergesort sort is \t");
         cal();
break;
case 2: st=clock(); quick(a,0,s-1); et=clock(); display(); printf("time requied for quicksort sort is \t");
         cal();
break;
case 3:st=clock(); quickf(a,0,s-1); et=clock(); display(); printf("time requied for quicksort sort is \t");
         cal();
break;
case 4: exit(0);
break;
default : printf("invalid input \n");
}
}while(l!=4);
}


void list()
{
int l,i,j,pos,val,n,num=0;
printf("enter the type of elemets you want \n 1.DECREASING \n 2.INCREASING \n 3.NORDER \n 4.RANDOM 5.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1: num=s;
        st=clock();
        for(i=0;i<s;i++)
         {
          a[i]=num;
          num--;
          }
        et=clock();
break;           
case 2:  st=clock();
         for(i=s;i>0;i--)
         a[i]=i;
         et=clock();
         display();
break;           
case 3: st=clock();
        for(i=s;i>0;i--)
        a[i]=i;
        printf("enter pos and value \n");
        scanf("%d%d",&pos,&val);
        for(j=pos;j<s;j=j+pos)
        a[j]=val;
        printf("elements are \n");
        for(i=0;i<s;i++)
        printf("%d \n",a[i]);
        et=clock();
break;
case 4:st=clock();
       for(i=0;i<s;i++)
       a[i]=rand();
       et=clock();
break; 
case 5: exit(0);
break;
default : printf("invalid choice \n");
}
}

void display()
{
int i;
printf("the new sorted array is \n");
for(i=0;i<s;i++)
printf("%d \t",a[i]);
printf("\n");
}

void cal()
{
double time;
time=(double)(et-st)/CLOCKS_PER_SEC;
printf("%lf \n",time);
}

