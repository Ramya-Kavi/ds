#include<stdio.h>
int main()
{
   int arr[20],i,found=0,no,search;
   printf("Enter the no of elements:");
   scanf("%d",&no);
   for(i=0;i<no;i++)
   {
   printf("Enter the %d elements:",i+1);
   scanf("%d",&arr[i]);
   }
      printf("\nEnter the elements that you want to search:");
	  scanf("%d",&search);
	  for(i=0;i<no;i++)
	  {
	     if(arr[i]==search)
	     {
	        printf("\nthe elements is found at the position %d and index :%d",i+1,i);
			found=1;
	     }
	  }
	  if(found==0)
	        printf("\nThe elements is not found\n");
			return 0;
}

