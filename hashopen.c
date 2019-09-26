#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TABLE_SIZE 10
int hash[TABLE_SIZE]={0};
void insert()
{
   int key,index;
   printf("\nEnter the element to be inserted:");
   scanf("%d",&key);
   index=key%TABLE_SIZE;
   if(hash[index]==0)
     hash[index]=key;
   else
     hash[++index]=key;
   printf("\nElement inserted successfully!!!");
}
void display()
{
  int i;
  for(i=0;i<TABLE_SIZE;i++)
  {
     printf("\nHash index %d",i);
	 printf("\t\tvalue:%d\n",hash[i]);
  }
}
void search()
{
   int i,search,found;
   printf("\nEnter the element to be searched :");
   scanf("%d",&search);
   for(i=0;i<TABLE_SIZE;i++)
   {
      if(hash[i]==search)
	  {
	      printf("\nsearch element found\n");
		  found=1;
	  }
	  if(found==0)
	    printf("Element not found");
   }
}
int main()
{
  int i,opt,choice;
  do{
     printf("--------HASH TABLE----\n1.Insert\n2.Display\n3.search\nEnter your choice:");
	 scanf("%d",&opt);
	 switch(opt)
	 {
	    case 1: insert();
		break;
		case 2:display();
		break;
		case 3:search();
		break;
		case 4:exit(0);
	 }
	 printf("\nDo u want to continue:(press 1 for yes):");
	 scanf("%D",&choice);
	 }while(choice==1);
	 return 0;
}
		  
 

