#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5 

 
void enqueue();  
void dequeue();  
int peek();
void display();  
int front = -1, rear = -1;  
int queue[maxsize]; 

 

int main ()  
{  
    int choice;   
    while(choice != 5)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Peek\n4.Display the queue\n5.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;
			case 3:
			peek();
			break;
            case 4:  
            display();  
            break;  
            case 5:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    } 
	return 0; 
}  


void enqueue()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  


void dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted ");  
    }  
      
      
} 

int peek()
{
	if(front == -1)
	{
		printf("queue underflow\n");
		exit(1);
	}
	printf("Topmost element: %d\n", queue[front]);
}
 
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d\n",queue[i]);  
        }     
    }  
}  

