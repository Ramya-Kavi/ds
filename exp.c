#include<stdio.h>
#include<conio.h>
#define MAX 20
int opt,a[20],i,top=0,n;
int main()
{
void create(),push(),pop(),disp();
int wish;
do
{
printf("\n MENU");
printf("\n1.create \n2.push \n3.pop \n4.display \n5.exit");
printf("\n Enter your option");
scanf("%d",&opt);
switch(opt)
{
case 1:create();break;
case 2:push(); break;
case 3:pop(); break;
case 4:disp(); break;
case 5:exit(0);
}
printf("\nDo u want to continue(1/0):");
scanf("%d",&wish);
}
while(wish==1);
}
void create()
{
printf("\nEnter the limit  of stack");
scanf("%d",&n);
if(n<MAX)
{
printf("\nEnter the items");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
top=n-1;
}
else
printf("\nUnable to create the stack");
}
void push()
{
int x;
if(top<MAX)
{
printf("\nEnter the element to be pushed:");
scanf("%d",&x);
top=top+1;
a[top]=x;
n=top;
}
else
printf("\n stack is full");
}
void pop()
{
if(top<0)
printf("\n stack is empty");
else
{
printf("\nThe element popped is %d",a[top]);
top=top-1;
n=top;
}
}
void disp()
{
if(top<0)
printf("\n The elements in the stack are:");
for(i=top;i>=0;i--)
printf("\n%d",a[i]);
}





