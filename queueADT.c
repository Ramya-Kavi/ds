#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int front=-1;
int rear=-1;
int q[size];
void insert();
void del();
void display();
int main()
{
int choice;
do
{
printf("\tMENU");
printf("\n1.insert \n2.delete \n3.display \n4.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: insert();display();break;
case 2: del();display();break;
case 3: display();break;
case 4: printf("End the program....!!!!");
exit(0);
}
}while(choice!=4);
}
void insert()
{
int no;
printf("\nEnter no:");
scanf("%d",&no);
if(rear<size-1)
{
q[++rear]=no;
if(front==-1)
front =0;
}
else
{
printf("\nQueue overflow");
}
}
void del()
{
if(front==-1)
{
printf("\nQueue underflow");
return ;
}
else
{
printf("\nDeleted item:-->%d\n",q[front]);
}
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
}
void display()
{
int i;
if(front==-1)
{
printf("\nQueue is empty....");
return;
}
for(i=front;i<=rear;i++)
printf("\t%d",q[i]);
}

