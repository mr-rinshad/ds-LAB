#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};


struct node* createnode(int value)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=newnode->right=NULL;
	return newnode;
}


struct node* insert(struct node* root ,int value)
{
	if(root==NULL)
		return createnode(value);
	if(value< root->data)
		root->left=insert(root->left,value);
	else if(value>root->data)
		root->right=insert(root->right,value);
	else
		printf("Duplicate value %d not inserted",value);
	return root;
}

struct node* search(struct node* root,int key)
{
	while(root!=NULL)
	{
		if(key==root->data)
			return root;
		else if(key<root->data)
			root=root->left;
		else
			root=root->right;
	}
	return NULL;
}


void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
        if(root!=NULL)
        {
		printf("%d\n",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}


void postorder(struct node* root)
{
        if(root!=NULL)
        {
	       	postorder(root->left);
                postorder(root->right);
		printf("%d\n",root->data);

	       
	}
}

struct node* findmin(struct node* root)
{
	while(root && root->left!=NULL)
		root=root->left;
	return root;
}

struct node* deletenode(struct node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->data)
		root->left=deletenode(root->left,key);
	else
	{
		if(root->left==NULL)
		{
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}

		struct node* temp=findmin(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
	return root;
}


int main(){

	struct node* root=NULL;
	int choice,value,key;

	while(1){
		printf("\n-----menu-----\n");
		printf("\n1.insert node");
		 printf("\n2.search node");
		  printf("\n3.inorder");
		   printf("\n4.preorder");
		    printf("\n5.postorder");
		     printf("\n6.delete node");
		      printf("\n7.exit");
		       printf("\nEnter your choice from the menu:");
		       scanf("%d",&choice);


	switch(choice)
	{
		case 1 : printf("Enter value to insert:");
	                 scanf("%d",&value);
	                 root=insert(root,value);
	                 printf("node inserted");
	                 break;
	        
	        case 2: printf("Enter value to search:");      
                         scanf("%d",&key);     
                         struct node* found=search(root,key);
		         if(found!=NULL)
		        	printf("node %d found in BST",key);
			 else 
				 printf("node %d not found in BST",key);
		          	 
                         break;		 

		case 3: printf("inorder:");
		        inorder(root);
		        printf("\n");
		        break;	
                                
                case 4: printf("preorder:");              
                        preorder(root);
                        printf("\n");   
                        break;
                case 5: printf("postorder:");              
                        postorder(root);
                        printf("\n");   
                        break;
                 case 6:printf("Enter value to delete:");              
                        scanf("%d",&key);
                        printf("Node deleted");   
                        break;			
                 case 7: printf("Program exiting");
			 return 0;
	         default: printf("invalid choice Try again");
	}
	}
}
            
