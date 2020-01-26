#include<stdio.h>
void main()
{
int i,j,k,temp=0, a[15],b[15],c[25];
printf("enter first array elements \n");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<5;i++)
{
for(j=0;j<4;j++)
{
if (a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("new array is \n");
for(i=0;i<5;i++)
printf("%d",a[i]);
printf("enter second array elements \n");
for(i=0;i<5;i++)
{
scanf("%d",&b[i]);
}
for(j=0;j<5;j++)
{
for(i=0;i<4;i++)
{
if (b[i]>b[i+1])
{
temp=b[i];
b[i]=b[i+1];
b[i+1]=temp;
}
}
}
printf("new array is \n");
for(i=0;i<5;i++)
printf("%d \n ",b[i]);
i=0,j=0,k=0;
while(i<=5 && j<5)
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
if(i>=5)
{
while(j<5)
{
c[k]=b[j];
j++;
k++;
}
}
if(j>=5)
{
while(i<5)
{
c[k]=a[i];
k++;
i++;
}
}
printf("new array is \n");
for(i=0;i<10;i++)
printf("%d \n",c[i]);
}


