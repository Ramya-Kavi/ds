#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *next;
}*top,*new1,*first;
int main()
{
  int wish,opt;
  void create(),push(),pop(),view();
  do
  {
   printf("stack using linked list menu");
   printf("\n1.create\n2.push\n3.pop\n4.view\n5.Exit\n");
   printf("\nEnter your option(1,2,3,4,5):");
   scanf("%d",&wish);
   switch(wish)
   {
    case 1:create();
	break;
	case 2:push();
	break;
	case 3:pop();
	break;
	case 4:view();
	break;
	case 5:exit(0);
   }
   printf("\nDo you want to continue(0/1):");
   scanf("%d",&opt);
  }while(opt==1);
}
void create()
{
   int ch;
   top=(struct node*)malloc(sizeof(struct node));
   top->next=NULL;
   do
   {
      printf("Enter the data:\n");
	  scanf("%d",&top->data);
	  printf("Do you want to insert another(1/0)\n");
	  scanf("%d",&ch);
	  if(ch==1)
	  {
	  new1=(struct node*)malloc(sizeof(struct node));
	  new1->next=top;
	  top=new1;
	  first=top;
	  }
  	  else
	    break;
	}while(ch==1);
}
void push()
{
   top=first;
   new1=(struct node*)malloc(sizeof(struct node));
   printf("Enter the element to be pushed:");
   scanf("%d",&new1->data);
   new1->next=top;
   top=new1;
   first=top;
}
void pop()
{
    top=first;
	if(top==NULL)
	printf("\nstack is empty");
	else
	{
	    printf("\nThe element popped out from stack	 is %d",top->data);
		top=top->next;
		first=top;
    }
}  
void view()
{
    printf("\nStack contents\n");
	while(top->next!=NULL)
	{
	printf("%d",top->data);
	top=top->next;
	}
	printf("%d\n",top->data);
	getch();
}

	    

