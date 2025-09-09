#include<stdio.h>

int main(){
	int size;
	printf("Enter the size of the stack:\n");
	scanf("%d",&size);

	int stack[size];
	int top=-1,ch,vl;

	while(1){

		   printf("\n-----stack menu-----\n");
		   printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT \n");
		   printf("Enter your choice\n");
		   scanf("%d",&ch);

       switch(ch){

	           case 1:if(top==size-1)
			  {
				  printf("overflow! can't push");
			  }
			  else
			  {
				  printf("Enter value  to push:\n");
				  scanf("%d",&vl);
				  top++;
				  stack[top]=vl;
				  printf("%d pushed into stack",vl);
			  }
		   break;

	           case 2:if(top==-1)
			  {
		                  printf("under flow!can't pop ");
		          }
	                  else
			  {
		                   printf("%d popd",stack[top]);
				   top--;
			  }
		  break;

	          case 3: if(top==-1)
			  {
			    printf("stack is empty");
			  }
	                   else
			   {
		             printf("stack elements:\n");
	                     for(int i=top; i>=0; i--)
			     {
		                printf("%d\t", stack[i]);
			     }
                              printf("\n");
			   }
                  break ;

                  case 4:
                          printf("Exiting");
	                  return 0;

	          default : printf("invalid  choice");
               }
	}
}	
		                   		   

