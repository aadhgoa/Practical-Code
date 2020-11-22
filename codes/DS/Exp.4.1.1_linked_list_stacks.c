#include <stdio.h>
#include <stdlib.h>    
  
  
  
struct Node  
{  
    int data;  
    struct Node* link;  
};  
  
struct Node* top;  
  
 void push(int data);
 int isEmpty();
 int peek();
 void pop();
 void display();
 
   
int main()  
{
	int x, data;
	
	while(1){
		printf("Menu\n");
		printf("1. Push to the stack\n");
		printf("2. Pop from the list\n");
		printf("3. Peek to the top\n");
		printf("4. Exit\n");
		
		printf("Enter your input: ");
		scanf("%d",&x);
		
		
		switch(x){
			case 1:
				printf("Data: ");
				scanf("%d", &data);
				push(data);
				display();
				break;
				
			case 2:
				pop();
				display();
				break;
				
			case 3:
				peek();
				//display();
				break;
				
				
			case 4:
				exit(0);
				break;
		}
	}
  	
	return 0;
}  


void push(int data)  
{  
      
    struct Node* temp;  
    temp = new Node();  
   
    if (!temp) 
    {  
        printf("\nHeap Overflow");
        exit(1);  
    }  
   
    temp->data = data;   
    temp->link = top; 
    top = temp;  
}  
  
  
int isEmpty()  
{  
    return top == NULL;  
}  

int peek()  
{  
 
    if (!isEmpty())  
        printf("top element: %d\n", top->data);  
    else
        exit(1);  
}  

 
void pop()  
{  
    struct Node* temp;  
 
    if (top == NULL)  
    {  
        printf("\nStack Underflow.");
        exit(1);  
    }  
    else
    {
        temp = top;  
        top = top->link;  
        temp->link = NULL;    
        free(temp);  
    }  
}  

void display()  
{  
    struct Node* temp;  
  
    // Check for stack underflow  
    if (top == NULL) 
    {  
        printf("\nStack Underflow");
        exit(1);  
    }  
    else 
    {  
        temp = top;  
        while (temp != NULL) 
        {  
  
        	printf("%d->",temp->data);
            temp = temp->link;  
        }  
    } 
	printf("\n");
}

