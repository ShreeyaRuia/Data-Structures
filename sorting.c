#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100000],b[100000],s;
clock_t st,et;
void list();
void display();
void bubble();
void selection();
void insertion();
void shell();
void bucket();
void cal();
void main()
{
int l=0;
do
{
for(int i=0;i<s;i++)
a[i]=0;
printf("enter total number of elements \n");
scanf("%d",&s);
list();
printf("enter the type of sorting you want \n 1.BUBBLE SORT \n 2.SELECTION SORT \n 3.INSERTION SORT \n 4.SHELL SORT \n 5.BUCKET SORT \n 6.EXIT \n");
scanf("%d",&l);
switch(l)
{
case 1:  bubble(); printf("time requied for bubble sort is \t");
         cal();
break;
case 2:  selection(); printf("time requied for selection sort is \t");
         cal();
break;
case 3:  insertion(); printf("time requied for inserion sort is \t");
         cal();
break;
case 4:  shell(); printf("time requied for shell sort is \t");
         cal();
break;
case 5:  bucket(); printf("time requied for bucket sort is \t");
         cal();
break;
case 6: exit(0);
break;
default : printf("invalid input \n");
}
}while(l!=6);
}
void list()
{
int l,i,j,pos,val,n,num=0;
printf("enter the type of elemets you want \n 1.DECREASING \n 2.INCREASING \n 3.NORDER \n 4.RANDOM \n");
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
st=clock();
for(i=0;i<s;i++)
printf("%d \t",a[i]);
printf("\n");
et=clock();
}

void bubble()
{
int tem,i,j;
st=clock();
for(i=0;i<s-1;i++)
{
 for(j=0;j<s-i-1;j++)
 {
  if(a[j]>a[j+1])
  {
   tem=a[j];
   a[j]=a[j+1];
   a[j+1]=tem;
  }
 }
}
et=clock();
display();
}

void selection()
{
int i,j,tem=0,pos=0;
st=clock();
for(i=0;i<s-1;i++)
{
 pos=i;
 for(j=i+1;j<=s-1;j++)
 {
  if(a[pos]> a[j])
   pos=j; 
 }
 tem=a[pos];
 a[pos]=a[i];
 a[i]=tem;
 }
et=clock();
display();
} 


void insertion()
{
int i,j,tem=0;
st=clock();
for(i=0;i<s-1;i++)
{
for(j=i+1;j<=i+1 && j>0;j--)
{
if(a[j]<a[j-1])
{
tem=a[j];
 a[j]=a[j-1];
 a[j-1]=tem;
}
}
}
et=clock();
display();
}


void shell()
{
int i,j,gap,temp;
display();
st=clock();
for(gap=s/2;gap>0;gap=gap/2)
{
for(i=gap;i<s;i=i+1)
{
temp=a[i];
for(j=i;j>=gap;j=j-gap)
{
if(temp<a[j-1])
a[j]=a[j-gap];
else
break;
}
a[j]=temp;
}
}
et=clock();
display();
}


void bucket()
{
int c[12];
int i,j,temp;
st=clock();
for(j=0;j<s;j++)
c[j]=0;
printf("\n");
for(i=0;i<s;i++)
{
 j=a[i];
c[j]++;
}
for(i=0;i<=s;i++)
{
for(j=c[i];j<=c[i] && j>0;j--)
printf("%d \t",i);
}
printf("\n");
et=clock();
}

void cal()
{
double time;
time=(double)(et-st)/CLOCKS_PER_SEC;
printf("%lf \n",time);

}



 
 
  
 

 
 



