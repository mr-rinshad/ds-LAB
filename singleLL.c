#include<stdio.h>
#include<stdlib.h>

        struct node{
		int data;
		struct node *link;
	};

        struct node *head=NULL;

	   void insert_front(int x);
	   void insert_end(int x);
	   void delete(int key);
	   void display();
	   void search(int key);

int main(){
         int ch ,x,key;
	 while(1){

		
		  
                 printf("1.insert front \n");
                printf("2.insert end\n");
                  printf("3.delete\n");
                   printf("4.display\n");
                     printf("5.search\n");
                       printf("6.exit\n");

                printf("Enter your choice:");


                scanf("%d",&ch);
                switch(ch){

                      case 1: printf("enter the new data:");
			      scanf("%d",&x);
			      insert_front(x);
			      break;

		     case 2:  printf("enter the new data:");
                              scanf("%d",&x);
                              insert_end(x);
                              break;
	             case 3:  printf("enter the node to delete");
	                      scanf("%d",&key);
	                      delete(key);
	                      break;

	            case 4:   display();
	                      break;
	            
	            case 5:  printf("enter the data to search:");
                             scanf("%d",&key);
                             search(key);
                             break;

                     case 6: printf("program exited");
                             return 0;

                     default : printf("enter a valid choice\n");
		}			       
	      
   
	        		
	 }



}



           void display(){
		   struct node *ptr;
		   if(head==NULL)
		   {
			   printf("linked list is empty");
		   }
		   else{
			   ptr=head;
			   printf("linked list elements are:");
			   while(ptr!=NULL)
			   {
				   printf("%d \t",ptr->data);
				   ptr=ptr->link;
			   }
			   printf("\n");
		   }
	   }

           void insert_front(int x){
                      struct node *newnode;
                      newnode=(struct node*)malloc(sizeof(struct node));
                      newnode->data=x;
                      newnode->link=head;
                      head=newnode;
                      display();
              }

            void insert_end(int x){
                    struct node *newnode,*ptr;
                    newnode=(struct node*)malloc(sizeof(struct node));
                    newnode->data=x;
                    newnode->link=NULL;

                    if (head==NULL){
                            head=newnode;
                    }else{
                            ptr=head;
                            while(ptr->link != NULL)
                            {
                                    ptr=ptr->link;
                            }
                            ptr->link=newnode;
                    }
                    display();
            }


           void delete(int key){
	           
		   struct node *prev,*curr,*temp;
		   if (head==NULL)
		   {
			   printf("Deletion is not possible\n");
		   }else if(head->data==key){
			   temp=head;
			   head=head->link;
			   free(temp);
		   }else{
			   prev=head;
			   curr=head;

			   while(curr!=NULL && curr->data!=key)
			   {
				   prev=curr;
				   curr=curr->link;
			   }
			   if(curr==NULL){
				   printf("Data not found\n");
			   }else{
				   prev->link=curr->link;
				   free(curr);
			   }
			
		   }
	   }


          void search(int key){
		  struct node *ptr=head;
		  int pos=0;

		  while(ptr!=NULL){
			  if (ptr->data==key){
				  printf("Data found at position %d \n",pos);
				  return;
			  }

			  ptr=ptr->link;
			  pos++;
		  }
		  printf("Data not found in the linked list");
	  }
