#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
   int height;
};
struct node *root=NULL;
int found=0,check=0;
int height(struct node *n)
{
    if(n==NULL)
	   return 0;
	return n->height;
}
int max(int a,int b)
{
    return(a>b)?a:b;
}
int balance(struct node *N)
{
    if(N==NULL)
	   return 0;
	return height(N->left)-height(N->right);
}
struct node *newnode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
struct node *RR(struct node *t1)
{
    struct node *t2;
	t2=t1->right;
	t1->right=t2->left;
	t2->left=t1;
	t1->height=1+max(height(t1->left),height(t1->right));
	t2->height=1+max(height(t2->left),height(t2->right));
	return t2;
}
struct node *LL(struct node *t1)
{
    struct node *t2;
	t2=t1->left;
	t1->left=t2->right;
	t2->right=t1;
	t1->height=1+max(height(t1->left),height(t1->right));
	t2->height=1+max(height(t2->left),height(t2->right));
	return t2;
}
struct node *RL(struct node *t1)
{
    t1->right=LL(t1->right);
	return RR(t1);
}
struct node *LR(struct node *t1)
{
    t1->left=RR(t1->left);
	return LL(t1);
}
struct node *modify(struct node *temp)
{
    int bal;
	temp->height=1+max(height(temp->left),height(temp->right));
	bal=balance(temp);
	if(bal > 1 && balance(temp->left)>=0)
	   return LL(temp);
	if(bal < -1 && balance(temp->right)<=0)
	   return RR(temp);
	if(bal > 1 && balance(temp->left)<0)
	   return LR(temp);
	if(bal <-1 && balance(temp->right)>0)
	   return RL(temp);
	return temp;
}
struct node *insert(struct node *temp,int key)
{
    int bal;
	if(temp==NULL)
	   return (newnode(key));
	if(key < temp->data)
	   temp->left=insert(temp->left,key);
	else if(key >temp->data)
	   temp->right=insert(temp->right,key);
	else
	   return temp;
	return (modify(temp));
}
struct node *min(struct node *root)
{
    while(root->left != NULL)
	   root=root->left;
	return root;
}
void display(struct node *root)
{
    if(root != NULL)
	{
	    printf("%d\t",root->data);
		display(root->left);
		display(root->right);
	}
}
void search(struct node *root,int num)
{
    if(root != NULL)
	{
	    if(root->data==num)
		{
		   printf("\n\tElement is found!!!");
		   found=1;
		}
		search(root->left,num);
		search(root->right,num);
	}
}
struct node *del(struct node *root,int key)
{
    struct node *temp;
	int bal;
	if(root==NULL)
	    return root;
	else if(key<root->data)
	    root->left=del(root->left,key);
	else if(key>root->data)
	    root->right=del(root->right,key);
	else
	{
	    check=1;
		if(root->left == NULL && root->right == NULL)
		    root=NULL;
		else if(root->left==NULL)
		{
		    temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
		    temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
		    temp=min(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	if(root==NULL)
	   return root;
	return modify(root);
}
int main()
{
    int opt,num;
	while(1)
	{
	   printf("\n\n----------AVL TREE------------\n\n1.Insert\n\n2.Display\n\n3.Search\n\n4.Delete\n\n5.Exit\n\nEnter your choice:");
	   scanf("%d",&opt);
	   switch(opt)
	   {
	       case 1:printf("\nEnter the number to insert:");
		          scanf("%d",&num);
				  root=insert(root,num);
				  printf("\nInsert Successfully\n");
				  break;
		   case 2:if(root==NULL)
		          {   
				     printf("\nTree is Empty\n");
					 break;
				  }
				  display(root);break;
		  case 3:printf("\nEnter the number to be searched:");
		         scanf("%d",&num);
				 search(root,num);
				 if(found==0)
				     printf("\n\tElement not found!!!");
				 found=0;
				 break;
		  case 4:printf("\nEnter the number to be deleted:");
		         scanf("%d",&num);
				 root=del(root,num);
				 if(check==0)
				    printf("\nElement not found\n");
				 else
				    printf("\nDeleted successfully\n");
				 check=0;
				 break;
		 case 5:exit(0);break;
		 default:printf("Enter correct option!!!");
	  }
	}
	return 0;
}















	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	      

