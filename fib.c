#include<stdio.h>
void fibbo(int n,int a,int b)
{
   int c;
   c=a+b;
   printf("%d",&c);
   printf("\n");
   a=b;
   b=c;
   if(n>1)
   { 
     fibbo(n-1,a,b);
   }
}
int main()
{
  int a=-1,b=1,n;
  printf("Enter the limit:");
  scanf("%d",&n);
  fibbo(n,a,b);
  return 0;
}

