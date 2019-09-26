#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TABLE_SIZE 10
struct node
{
    int data;
	struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*ptr;
void insert()
{
    int i,key,choice;
	do{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	  printf("\nEnter the value to insert into hashtable:");
	  scanf("%d",&key);
	  i=key%TABLE_SIZE;
	  newnode->data=key;
	  newnode->next=NULL;
	  if(head[i]==NULL)
	     head[i]=newnode;
	  else
	  {
	    ptr=head[i];
		while(ptr->next!=NULL)
		  ptr=ptr->next;
		ptr->next=newnode;
	  }
	  printf("\n\n Doyou want to insert another element?-(press 1 for yes)-:");
	  scanf("%d",&choice);
	  }while(choice==1);
}
void search()
{
    int key,index;
	printf("\n\nEnter the element to be searched:");
	scanf("%d",&key);
	index=key%TABLE_SIZE;
	if(head[index]==NULL)
	   printf("\n\nSearch element not found\n");
	else
	{
	  for(ptr=head[index];ptr!=NULL;ptr=ptr->next)
	  {
	     if(ptr->data==key)
		 {
		    printf("\nSearch element %d is found at %d\n",key,index);
			break;
		 }
	  }
	  if(ptr==NULL)
	     printf("\nSearch element not found\n");
	}
}
void display()
{
   int i;
   for(i=0;i<TABLE_SIZE;i++)
   {
       printf("\nEntries at index %d\n",i);
	     if(head[i]==NULL)
		   printf("no hash entry");
		 else
		 {
		   for(ptr=head[i];ptr!=NULL;ptr=ptr->next)
		     printf("%d->",ptr->data);
		 }
	}
}
int main()
{
  int opt,key,i,choice;
  do{
     printf("\n-----HASH TABLE------\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter your choice:");
	 scanf("%d",&opt);
	 switch(opt)
	 {
	    case 1:insert();
		break;
		case 2:display();
		break;
		case 3:search();
		break;
		case 4:exit(0);
	 }
	 printf("\nDo you want to continue the program?-:(press 1 for yes):");
	 scanf("%d",&choice);
	}while(choice==1);
	return 0;
}

