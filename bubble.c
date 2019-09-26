#include<stdio.h>
int main()
{
  int arr[20],i,j,n,temp;
     printf("Enter the no of elements:");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
	       printf("\nEnter the %d element:",i+1);
		   scanf("%d",&arr[i]);
	 }
	 for(i=0;i<n;i++)
	   for(j=0;j<n-i-1;j++)
	     if(arr[j]>arr[j+1])
		 {
		    temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		 }
	 printf("sorted list....\n");
	 for(i=0;i<n;i++)
	    printf("%d\n",arr[i]);
	 return 0;
}
			

