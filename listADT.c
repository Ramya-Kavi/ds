#include<stdio.h>
#define MAX 10
void create();
void insert();
void delete();
void search();
void display();
int a,b[20],n,p,e,f,i,pos;
int main()
{
int ch,opt;
do
{
printf("\nMain menu");
printf("\n1.create\n2.delete\n3.search\n4.insert\n5.display\n6.exit\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:delete();
break;
case 3:search();
break;
case 4:insert();
break;
case 5:display();
break;
case 6:exit(0);
break;
default:printf("Enter the correct choice");
}
printf("do u want to continue(0/1):");
scanf("%d",&opt);
}while(1);
}
void create()
{
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the element:",i+1);
scanf("%d",&b[i]);
}
}
void delete()
{
printf("Enter the position u want to delete:");
scanf("%d",&pos);
if(pos>=n)
{
printf("\nInvalid location:");
}
else
{
for(i=pos+1;i<n;i++)
{
b[i-1]=b[i];
}
n--;
}
printf("\nThe elements after deletion:");
for(i=0;i<n;i++)
{
printf("\t%d",b[i]);
}
}
void search()
{
printf("\nEnter the element to be searched:");
scanf("%d",&e);
for(i=0;i<n;i++)
{
if(b[i]==e)
{
printf("Value is in the %d position:\n",i);
}
}
}
void insert()
{
printf("\nEnter the position u need to insert:");
scanf("%d",&pos);
if(pos>=n)
{
printf("\nInvalid location:");
}
else
{
for(i=MAX-1;i>=pos-1;i--)
{
b[i+1]=b[i];
}
printf("\nEnter the element to insert :\n");
scanf("%d",&p);
b[pos]=p;
n++;
}
printf("\nThe list after insertion :\n");
display();
}
void display()
{
printf("\nThe elements of the list ADT are:\n");
for(i=0;i<n;i++)
{
printf("\n\n%d\n",b[i]);
}
}

